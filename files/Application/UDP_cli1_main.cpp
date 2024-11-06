#include "../Socket/inc/TCPsocket.hpp"
#include "../Socket/inc/UDPsocket.hpp"
#include "../Channel/inc/server.hpp"
#include "../Channel/inc/client.hpp"

int main()
{
    Socket* UDP = new Udp_Socket;
    Client_channel client(UDP);
    client.start();
    
    while(true)
    {
        std::cout<<"Client 1: ";
        client.receive();
    }
    delete (UDP); 
}