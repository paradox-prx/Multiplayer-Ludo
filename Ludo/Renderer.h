// Renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"

class Renderer {
public:
    Renderer();
    void setWindow(sf::RenderWindow& win);
    void drawBoard(const Board& board);
    void drawPieces(const std::vector<Player*>& players, const Board& board);
    void display();
    void clear();
    bool isWindowOpen();
    void closeWindow();
    bool pollEvent(sf::Event& event);
private:
    sf::RenderWindow* window;
};

#endif // RENDERER_H
