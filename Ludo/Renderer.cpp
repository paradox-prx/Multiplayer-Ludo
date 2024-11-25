// Renderer.cpp
#include "Renderer.h"

Renderer::Renderer() : window(nullptr) {}

void Renderer::setWindow(sf::RenderWindow& win) {
    window = &win;
}

void Renderer::drawBoard(const Board& board) {
    for (const auto& tile : board.getTiles()) {
        sf::RectangleShape rect(sf::Vector2f(50.0f, 50.0f));
        rect.setPosition(tile.getPosition());
        if (tile.isSafeZone())
            rect.setFillColor(sf::Color::Green);
        else
            rect.setFillColor(sf::Color::White);
        rect.setOutlineThickness(1.0f);
        rect.setOutlineColor(sf::Color::Black);
        window->draw(rect);
    }
}

void Renderer::drawPieces(const std::vector<Player*>& players, const Board& board) {
    for (const auto& player : players) {
        for (const auto& piece : player->getPieces()) {
            if (piece.getCurrentTile() != -1) {
                sf::CircleShape circle(10.0f);
                const Tile& tile = board.getTile(piece.getCurrentTile());
                sf::Vector2f pos = tile.getPosition();
                circle.setPosition(pos.x + 20.0f, pos.y + 20.0f);
                // Assign color based on player ID
                switch (player->getPlayerID()) {
                case 0: circle.setFillColor(sf::Color::Red); break;
                case 1: circle.setFillColor(sf::Color::Blue); break;
                case 2: circle.setFillColor(sf::Color::Yellow); break;
                case 3: circle.setFillColor(sf::Color::Green); break;
                default: circle.setFillColor(sf::Color::Black); break;
                }
                window->draw(circle);
            }
        }
    }
}

void Renderer::display() {
    window->display();
}

void Renderer::clear() {
    window->clear(sf::Color::White);
}

bool Renderer::isWindowOpen() {
    return window->isOpen();
}

void Renderer::closeWindow() {
    window->close();
}

bool Renderer::pollEvent(sf::Event& event) {
    return window->pollEvent(event);
}
