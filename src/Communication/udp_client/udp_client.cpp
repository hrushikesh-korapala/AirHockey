#include "Communication/udp_client/udp_client.h"
    
comms::UDPClient::UDPClient(const char* server_ip, int port) {
    // Create UDP socket
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        std::cerr << "Socket creation failed: " << strerror(errno) << std::endl;
        exit(1);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address: " << strerror(errno) << std::endl;
        close(sock_fd);
        exit(1);
    }
}

comms::UDPClient::~UDPClient() {
    close(sock_fd);
}

void comms::UDPClient::sendAndReceive(const char* message) {
    // Send message to server
    if (sendto(sock_fd, message, strlen(message), 0,
                (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Send failed: " << strerror(errno) << std::endl;
        return;
    }
    std::cout << "Sent message: " << message << std::endl;

    // Wait for acknowledgment
    char buffer[1024] = {0};
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);

    // Set receive timeout to 5 seconds
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    ssize_t received = recvfrom(sock_fd, buffer, sizeof(buffer)-1, 0,
                                (struct sockaddr*)&from_addr, &from_len);
    
    if (received < 0) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            std::cerr << "Timeout waiting for server response" << std::endl;
        } else {
            std::cerr << "Receive failed: " << strerror(errno) << std::endl;
        }
        return;
    }

    buffer[received] = '\0';
    std::cout << "Received acknowledgment: " << buffer << std::endl;
}