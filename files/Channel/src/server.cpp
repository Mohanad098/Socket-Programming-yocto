#include "server.hpp"

Server_channel::Server_channel(Socket* sock_fd):Channel(sock_fd){}
void Server_channel::start()
{
    socket_ptr()->wait_for_connection();
}