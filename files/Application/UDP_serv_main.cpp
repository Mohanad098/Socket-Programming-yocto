#include "../Socket/inc/TCPsocket.hpp"
#include "../Socket/inc/UDPsocket.hpp"
#include "../Channel/inc/server.hpp"
#include "../Channel/inc/client.hpp"

#define SLEEP_DURATION  5
#define MAX_SLEEP_TIME  65  //1 minute 5 seconds

std::string clock(int sec, int min, std::string text)
{
    /* Convert the minutes and seconds to string */
    std::string sec_string = std::to_string(sec);
    std::string min_string = std::to_string(min);
    std::string message;

    /* Concatinate all the message */
    if(sec == 0 || sec == 5)
    {
        message = text + min_string + static_cast<std::string>(":0") + sec_string + static_cast<std::string>(" AM");
    }
    else
    {
        message = text + min_string + static_cast<std::string>(":") + sec_string + static_cast<std::string>(" AM");
    }
    return message;
}

int main()
{
    std::string text = "System update at 10:0";
    std::string message;
    int seconds = 0;
    int minutes = 0;
    Socket* UDP = new Udp_Socket;
    Server_channel server(UDP);
    server.start();

    /* Sending to the multicast group */
    std::cout << "Multicast server sending to group " << MULTICAST_GROUP << std::endl;

    unsigned char sleep_time = MAX_SLEEP_TIME; //60 seconds
    // Send message every 5 seconds for 1 minute
    while(sleep_time != 0)
    {
        message = clock(seconds,minutes,text);
        server.send(message);
        /* Add 5 seconds */
        seconds +=SLEEP_DURATION;
        if(seconds == 60)
        {
            seconds = 0;
            minutes++; //And we should continue if minutes == 60, but in this app the while loop takes 1 minute only so no need
        }
        sleep(SLEEP_DURATION);
        sleep_time-=SLEEP_DURATION;
    }
    delete (UDP);   
}