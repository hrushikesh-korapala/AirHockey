#include "Communication/udp_server/udp_server.h"

comms::UDPServer::UDPServer(int port) : running(false) {
    // Create UDP socket
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        std::cerr << "Socket creation failed: " << strerror(errno) << std::endl;
        exit(1);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket
    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed: " << strerror(errno) << std::endl;
        close(sock_fd);
        exit(1);
    }
}

comms::UDPServer::~UDPServer() {
    close(sock_fd);
}

void comms::UDPServer::start() {
    running = true;
    std::cout << "Server is running on port " << ntohs(server_addr.sin_port) << std::endl;

    while (running) {
        char buffer[1024] = {0};
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        // Receive message from client
        ssize_t received = recvfrom(sock_fd, buffer, sizeof(buffer)-1, 0,
                                    (struct sockaddr*)&client_addr, &client_len);
        
        if (received < 0) {
            std::cerr << "Receive failed: " << strerror(errno) << std::endl;
            continue;
        }

        buffer[received] = '\0';
        
        // Print client information and message
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        std::cout << "Received from " << client_ip << ":" << ntohs(client_addr.sin_port)
                    << " - Message: " << buffer << std::endl;

        // Send acknowledgment
        const char* ack = "Message received successfully";
        if (sendto(sock_fd, ack, strlen(ack), 0,
                    (struct sockaddr*)&client_addr, client_len) < 0) {
            std::cerr << "Failed to send acknowledgment: " << strerror(errno) << std::endl;
        }
    }
}

void comms::UDPServer::stop() {
    running = false;
}
