// Game.h
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "Dice.h"
#include "Renderer.h"
#include "NetworkManager.h"
#include "GameState.h"
#include "Menu.h"
#include <vector>

class Game {
public:
    Game();
    void init();
    void run();
    void update();
    void render();
    void handleEvents();
private:
    Board board;
    std::vector<Player*> players;
    Dice dice;
    Renderer renderer;
    NetworkManager networkManager;
    int currentPlayerIndex; // Add this line
    GameState gameState;
    Menu menu; // Added Menu member variable
};

#endif // GAME_H
