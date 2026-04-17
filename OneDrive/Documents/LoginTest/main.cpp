#include <iostream>
#include "chat_server.cpp"

int main() {
    try {
        ChatServer myServer;
        myServer.start();
    } catch (std::exception& e) {
        std::cerr << "Main Exception: " << e.what() << std::endl;
    }
    return 0;
}
