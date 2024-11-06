#ifndef SERVER_HPP
#define SERVER_HPP

#include "channel.hpp"

class Server_channel: public Channel
{
public:
    Server_channel(Socket* sock_fd);
    virtual void start() override;
};
#endif