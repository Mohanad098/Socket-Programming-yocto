#include "UDPsocket.hpp"

/*********************** CONSTRUCTOR *************************/
Udp_Socket::Udp_Socket():sock(socket(AF_INET, SOCK_DGRAM, 0)),reuse(1),ttl(1)
{
    if (sock < 0) 
    {
        std::cerr << "Socket creation failed!" << std::endl;
        //return -1;
    }
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(reuse)) < 0) 
    {
        std::cerr << "Setting SO_REUSEADDR failed" << std::endl;
        close(sock);
        //return -1;
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);       // Bind to port 8080
    std::cout<<"Socket creation successful!\n";
}

/******************** Wait for Connection *******************/
void Udp_Socket::wait_for_connection()
{
    address.sin_addr.s_addr = inet_addr(MULTICAST_GROUP);
    if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(ttl)) < 0) 
    {
        std::cerr << "Failed to set TTL" << std::endl;
        close(sock);
        //return -1;
    }
    identity = SERVER;
}

/*********************** Connect **********************/
void Udp_Socket::Connect()
{
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        close(sock);
        //return -1;
    }

    //Join the multicast group
    mreq.imr_multiaddr.s_addr = inet_addr(MULTICAST_GROUP);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
        std::cerr << "Failed to join multicast group" << std::endl;
        close(sock);
        //return -1;
    }

    std::cout << "Joined multicast group: " << MULTICAST_GROUP << std::endl;
    identity = CLIENT;
}

/********************** Send *******************/
void Udp_Socket::Send(const std::string& message)
{
    const char* msg = message.c_str();
    sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&address, sizeof(address));
    std::cout << "Message sent: " << message << std::endl;
}

/********************** Receive *******************/
void Udp_Socket::receive()
{
    int len = recvfrom(sock, buffer, BUFFER_SIZE, 0, nullptr, nullptr);
    if (len < 0) 
    {
        std::cerr << "Receive failed" << std::endl;
    }
    else
    {
        buffer[len] = '\0';
        std::cout << "Received message: " << buffer << std::endl;
    }
}

/********************** Shutdown ******************/
void Udp_Socket::shutdown()
{
    if(identity == CLIENT)
    {
        setsockopt(sock, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));
    }
    
    close(sock);
    sock = 0;
}

/*********************** Deconstructor ******************/
Udp_Socket::~Udp_Socket()
{
    if(sock!=0)
    {
        shutdown();
    }
}