#ifndef _GAME_SERVER_COMMUNICATIONS_UDP_CLIENT_
#define _GAME_SERVER_COMMUNICATIONS_UDP_CLIENT_

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

namespace comms {
    class UDPClient {
    private:
        int sock_fd;
        struct sockaddr_in server_addr;
        
    public:
        UDPClient(const char* server_ip, int port);

        ~UDPClient();

        void sendAndReceive(const char* message);
};
}
#endif // _GAME_SERVER_COMMUNICATIONS_UDP_CLIENT_