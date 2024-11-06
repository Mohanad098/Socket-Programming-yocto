#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP

#include "socket.hpp"
#include "string.h"

#define PORT 8080
#define BUFFER_SIZE 1024

#define SERVER 1
#define CLIENT 2

class Tcp_Socket: public Socket
{
private:
    struct sockaddr_in address,client_address;
    char buffer[BUFFER_SIZE] = {0};
    char client_ip[INET_ADDRSTRLEN];
    int sock, new_socket;
    int addrlen;
    unsigned char identity = 0;
public:

    /*********************** CONSTRUCTOR *************************/
    /*
    1) Creates socket
    2) Assigns sockaddr_in struct members:
        sin_family = AF_INET (IPV4)
        sin_port = htons(8080) (Port 8080)
    3) Assigns addrlen to the size of struct
    */
    Tcp_Socket();

    /******************** Wait for Connection *******************/
    /*
    TCP server implementation
    1) Assigns struct member sin_addr.s_addr = INADDR_ANY to listen to any avalable interface
    2) Binds the socket
    3) Listens to upcoming connections
    4) Accepts connections and puts them in new_socket
    */
    virtual void wait_for_connection();

    /*********************** Connect **********************/
    /*
    TCP client implementation
    1) Convert the server address from text to binary form
    2) Connects to the server
    */
    virtual void Connect() override;

    /********************** Send *******************/
    /*
     * Send a message
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
    ~Tcp_Socket();
};
#endif