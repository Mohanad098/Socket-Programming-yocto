#ifndef UDPSOCKET_HPP
#define UDPSOCKET_HPP

#include "socket.hpp"
#include "string.h"

#define PORT 8080
#define BUFFER_SIZE 1024
#define MULTICAST_GROUP "224.0.0.1"

#define SERVER 1
#define CLIENT 2

class Udp_Socket: public Socket
{
private:
    char buffer[BUFFER_SIZE] = {0};
    unsigned char ttl;
    unsigned char identity;
    int reuse;
public:
    int sock;
    struct sockaddr_in address;
    struct ip_mreq mreq;

    /*********************** CONSTRUCTOR *************************/
    /*
    1) Creates socket
    2) Allows multiple sockets to bind to the same address and port
    3) Assigns sockaddr_in struct members:
        sin_family = AF_INET (IPV4)
        sin_port = htons(8080) (Port 8080)
    */
    Udp_Socket();

    /******************** Wait for Connection *******************/
    /*
    UDP server implementation
    1) Sets the server address for the multicast group
    2) Sets the time to live for the multicast packet (allows 1 hop here in this example)
    */
    virtual void wait_for_connection();

    /*********************** Connect **********************/
    /*
    UDP client implementation
    1) Bind to the local address and port
    2) Join the multicast group
    */
    virtual void Connect() override;

    /********************** Send *******************/
    /*
     * Send a message to the multicast group
     */
    virtual void Send(const std::string& message) override;

    /********************** Receive *******************/
    /*
     * Receive a message
     */
    virtual void receive() override;

    /********************** Shutdown ******************/
    /*
     * Close any opened sockets
     */
    virtual void shutdown() override;

    /*********************** Deconstructor ******************/
    /* 
     * Calls shutdown function to exit the class gracefully
     */
    ~Udp_Socket();
};
#endif