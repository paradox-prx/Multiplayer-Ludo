// Menu.h (Updated to include getWindow)
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();
    void display();
    int getNumberOfBots();
    bool isMultiplayerSelected();
    sf::RenderWindow& getWindow(); // Added function to get the window
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text title;
    sf::Text singlePlayerButton;
    sf::Text multiplayerButton;
    sf::Text botsText;
    sf::Text instructionText;
    int numberOfBots;
    bool multiplayer;
    bool selectingBots;
};

#endif // MENU_H
