#include "../Socket/inc/TCPsocket.hpp"
#include "../Socket/inc/UDPsocket.hpp"
#include "../Channel/inc/server.hpp"
#include "../Channel/inc/client.hpp"

int main()
{
    std::string message = "Acknowledge. Current Temperature is 39 ⁰C";
    Socket* TCP = new Tcp_Socket;
    Server_channel server(TCP);
    server.start();
    server.receive();
    std::cout<<"Sending message: " << message << std::endl;
    server.send(message);
    delete (TCP);
}