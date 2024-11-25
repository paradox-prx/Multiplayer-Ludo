// NetworkManager.cpp
#include "NetworkManager.h"
#include <iostream>

NetworkManager::NetworkManager() {
    // Initialize sockets if needed
}

void NetworkManager::connect() {
    // Example: Connect to localhost on port 54000
    if (listener.listen(54000) != sf::Socket::Done) {
        std::cerr << "Error setting up listener\n";
    }
    else {
        std::cout << "Listener is listening to port 54000, waiting for connections...\n";
        if (listener.accept(socket) == sf::Socket::Done) {
            std::cout << "Client connected\n";
        }
    }
}

void NetworkManager::sendData() {
    // Implement data sending
}

void NetworkManager::receiveData() {
    // Implement data receiving
}
