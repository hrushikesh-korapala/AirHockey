#include <iostream>
#include "Communication/udp_client/udp_client.h"

int main() {
    try {
        comms::UDPClient client("127.0.0.1", 8080);
        client.sendAndReceive("Hello, Server!");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}