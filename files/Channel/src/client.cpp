#include "client.hpp"

Client_channel::Client_channel(Socket* sock_fd):Channel(sock_fd){}

void Client_channel::start()
{
    socket_ptr()->Connect();
}