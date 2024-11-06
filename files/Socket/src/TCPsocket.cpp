#include "TCPsocket.hpp"

/*********************** CONSTRUCTOR *************************/
Tcp_Socket::Tcp_Socket():sock(socket(AF_INET, SOCK_STREAM, 0)),addrlen(sizeof(address))
{
    if (sock < 0) 
    {
    std::cerr << "Socket creation failed!" << std::endl;
    //return -1;
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);       // Bind to port 8080
    std::cout<<"Socket creation successful!\n";
}

/******************** Wait for Connection *******************/
void Tcp_Socket::wait_for_connection()
{
    // Step 2: Bind the socket to an IP address and port
    address.sin_addr.s_addr = INADDR_ANY; // Listen on any available interface

    if (bind(sock, (struct sockaddr*)&address, addrlen) < 0) {
        std::cerr << "Bind failed!" << std::endl;
        //return -1;
    }

    std::cout<<"Server : Socket has been binded successfully \n";

    // Step 3: Put the server in a listening state (up to 3 connections)
    if (listen(sock, 3) < 0) {
        std::cerr << "Listen failed!" << std::endl;
        //return -1;
    }

    std::cout<<"Server : Socket is listening for incoming connections  ..... \n";

    // Step 4: Accept an incoming connection
    socklen_t client_addrlen = sizeof(client_address);
    new_socket = accept(sock, (struct sockaddr*)&client_address, (socklen_t*)&client_addrlen);
    if (new_socket < 0) {
        std::cerr << "Accept failed!" << std::endl;
        //return -1;
    }
    /* Get client IP in readable format and print it */
    inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);
    std::cout << "Server: Connection accepted from " << client_ip << ":" << ntohs(client_address.sin_port) << "\n";
    
    identity = SERVER;
}

/*********************** Connect **********************/
void Tcp_Socket::Connect()
{
    new_socket = sock;
    // Convert the server address from text to binary form
    if (inet_pton(AF_INET, IP, &address.sin_addr) <= 0) {
        std::cerr << "Invalid address!" << std::endl;
        //return -1;
    }

    std::cout << "Client : Trying to connect to server \n" << std::endl;

    // Step 3: Connect to the server
    if (connect(new_socket, (struct sockaddr*)&address, addrlen) < 0) {
        std::cerr << "Connection failed!" << std::endl;
        //return -1;
    }

    std::cout << "Client : Connection established with server \n" << std::endl;

    identity = CLIENT;
}

/********************** Send *******************/
void Tcp_Socket::Send(const std::string& message)
{
    const char* msg = message.c_str();
    send(new_socket, msg, strlen(msg), 0);
}

/********************** Receive *******************/
void Tcp_Socket::receive()
{
    read(new_socket, buffer, BUFFER_SIZE);
    std::cout << "Message received: " << buffer << std::endl;
}

/********************** Shutdown ******************/
void Tcp_Socket::shutdown()
{
    close(new_socket);
    close(sock);
    new_socket = 0;
    sock = 0;
}

/*********************** Deconstructor ******************/
Tcp_Socket::~Tcp_Socket()
{
    if(sock != 0 || new_socket!=0)
    {
        shutdown();
    }
}
