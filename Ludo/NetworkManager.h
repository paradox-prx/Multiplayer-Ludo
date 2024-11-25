// NetworkManager.h
#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <SFML/Network.hpp>

class NetworkManager {
public:
    NetworkManager();
    void connect();
    void sendData();
    void receiveData();
private:
    sf::TcpSocket socket;
    sf::TcpListener listener;
};

#endif // NETWORKMANAGER_H
