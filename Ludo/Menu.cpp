// Menu.cpp
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu() : numberOfBots(0), multiplayer(false), selectingBots(false) {
    window.create(sf::VideoMode(800, 600), "Ludo Game Menu");
    const std::string fontPath = "arial.ttf";
    std::cout << "Attempting to load font from path: '" << fontPath << "'\n";
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font from path: '" << fontPath << "'\n";
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "Font loaded successfully from path: '" << fontPath << "'\n";
    }


    title.setFont(font);
    title.setString("Ludo Game");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::Black);
    title.setPosition(250, 50);

    singlePlayerButton.setFont(font);
    singlePlayerButton.setString("Single Player");
    singlePlayerButton.setCharacterSize(24);
    singlePlayerButton.setFillColor(sf::Color::Blue);
    singlePlayerButton.setPosition(300, 200);

    multiplayerButton.setFont(font);
    multiplayerButton.setString("Multiplayer");
    multiplayerButton.setCharacterSize(24);
    multiplayerButton.setFillColor(sf::Color::Blue);
    multiplayerButton.setPosition(300, 250);

    botsText.setFont(font);
    botsText.setString("Number of Bots (0-3): ");
    botsText.setCharacterSize(20);
    botsText.setFillColor(sf::Color::Black);
    botsText.setPosition(280, 350);

    instructionText.setFont(font);
    instructionText.setString("Press number key to select bots");
    instructionText.setCharacterSize(20);
    instructionText.setFillColor(sf::Color::Black);
    instructionText.setPosition(220, 400);
}

void Menu::display() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                if (singlePlayerButton.getGlobalBounds().contains(mousePosF)) {
                    selectingBots = true;
                }
                if (multiplayerButton.getGlobalBounds().contains(mousePosF)) {
                    multiplayer = true;
                    window.close();
                }
            }

            // Handle text input for bots
            if (event.type == sf::Event::TextEntered && selectingBots) {
                if (event.text.unicode >= '0' && event.text.unicode <= '3') {
                    numberOfBots = event.text.unicode - '0';
                    botsText.setString("Number of Bots (0-3): " + std::to_string(numberOfBots));
                    window.close();
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(title);
        window.draw(singlePlayerButton);
        window.draw(multiplayerButton);
        if (selectingBots) {
            window.draw(botsText);
            window.draw(instructionText);
        }
        window.display();
    }
}

int Menu::getNumberOfBots() {
    return numberOfBots;
}

bool Menu::isMultiplayerSelected() {
    return multiplayer;
}

sf::RenderWindow& Menu::getWindow() {
    return window;
}

