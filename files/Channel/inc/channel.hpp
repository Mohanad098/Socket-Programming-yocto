#ifndef CHANNEL_HPP
#define CHANNEL_HPP
#include "../../Socket/inc/socket.hpp"

class Channel
{
private:

    Socket* channelSocket; //A pointer to a Socket object either TCPSocket or UDPSocket

public:

    Channel(Socket* sock): channelSocket(sock){}
    Socket* socket_ptr()
    {
        return channelSocket;
    }
    virtual void start() = 0;
    virtual void stop()
    {
        channelSocket->shutdown();
    }
    virtual void send(const std::string& message)
    {
        channelSocket->Send(message);
    }
    virtual void receive()
    {
        channelSocket->receive();
    }

};
#endif