#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define IP      "192.168.7.255"

class Socket
{
public:
    virtual void wait_for_connection() = 0;
    virtual void Connect() = 0;
    virtual void Send(const std::string& message) = 0;
    virtual void receive() = 0;
    virtual void shutdown() = 0;
};
#endif