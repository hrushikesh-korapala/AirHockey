#ifndef _GAME_SERVER_COMMUNICATIONS_UDP_SERVER_
#define _GAME_SERVER_COMMUNICATIONS_UDP_SERVER_

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

namespace comms {
    class UDPServer {
    private:
        int sock_fd;
        struct sockaddr_in server_addr;
        bool running;

    public:
        UDPServer(int port);

        ~UDPServer();

        void start();
        void stop();
    };
}
#endif // _GAME_SERVER_COMMUNICATIONS_UDP_SERVER_