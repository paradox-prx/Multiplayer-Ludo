// Game.cpp
#include "Game.h"
#include "HumanPlayer.h"
#include "BotPlayer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() : gameState(GameState::MENU), currentPlayerIndex(0) {}

void Game::init() {
    // Display the menu and get user selections
    std::cout << "Initializing game...\n";
    menu.display();
    std::cout << "Menu displayed.\n";    if (menu.isMultiplayerSelected()) {
        // Initialize network and players for multiplayer
        networkManager.connect();
        // Initialize local player
        players.push_back(new HumanPlayer(0));
        // Other players will be connected over the network
        // For simplicity, we'll assume two players
        players.push_back(new HumanPlayer(1));
    }
    else {
        int bots = menu.getNumberOfBots();
        // Initialize players
        players.push_back(new HumanPlayer(0));
        for (int i = 1; i <= bots; ++i) {
            players.push_back(new BotPlayer(i));
        }
    }
    // Initialize the board
    board.initialize();
    // Initialize the dice
    dice = Dice();
    // Initialize the renderer with the window from Menu
    renderer.setWindow(menu.getWindow());
    // Set game state to playing
    gameState = GameState::PLAYING;
}

void Game::run() {
    while (renderer.isWindowOpen()) {
        handleEvents();
        if (gameState == GameState::PLAYING) {
            update();
            render();
        }
    }
    // Clean up
    for (auto player : players) {
        delete player;
    }
}

void Game::update() {
    // Current player takes a turn
    Player* currentPlayer = players[currentPlayerIndex];
    currentPlayer->takeTurn(board, dice);
    // Check for win condition
    if (currentPlayer->hasWon()) {
        std::cout << "Player " << currentPlayer->getPlayerID()
            << " has won the game!\n";
        gameState = GameState::GAME_OVER;
    }
    else {
        // Move to next player
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }
}

// In Game::render()
void Game::render() {
    renderer.clear();
    renderer.drawBoard(board);
    renderer.drawPieces(players, board); // Pass board as parameter
    renderer.display();
}


void Game::handleEvents() {
    sf::Event event;
    while (renderer.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            renderer.closeWindow();
        }
        // Handle other events as needed
    }
}
