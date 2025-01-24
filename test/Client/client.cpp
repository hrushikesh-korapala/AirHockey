#include <iostream>
#include "Communication/udp_client/udp_client.h"

int main() {
    try {
        comms::UDPClient client("52.172.26.255", 9696);
        client.sendAndReceive("Hello, Server!");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}