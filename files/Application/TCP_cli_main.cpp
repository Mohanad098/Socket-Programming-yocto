#include "../Socket/inc/TCPsocket.hpp"
#include "../Socket/inc/UDPsocket.hpp"
#include "../Channel/inc/server.hpp"
#include "../Channel/inc/client.hpp"

int main()
{
    std::string message = "Hello Server!";
    Socket* TCP = new Tcp_Socket;
    Client_channel server(TCP);
    server.start();
    std::cout<<"Sending message: "<< message << std::endl;
    server.send(message);
    server.receive();

    delete (TCP);
}
