#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "channel.hpp"

class Client_channel: public Channel
{
public:
    Client_channel(Socket* sock_fd);
    virtual void start() override;
};
#endif