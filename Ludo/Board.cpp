// Board.cpp (Complete implementation)
#include "Board.h"

Board::Board() {
    initialize();
}

void Board::initialize() {
    // Initialize tiles for Ludo board
    // Example: creating 52 tiles
    for (int i = 0; i < 52; ++i) {
        bool safe = (i % 13 == 0); // Every 13th tile is a safe zone
        tiles.emplace_back(i, safe);
        tiles.back().setPosition(sf::Vector2f(50.0f + (i % 13) * 50.0f,
            50.0f + (i / 13) * 50.0f));
    }
}

const std::vector<Tile>& Board::getTiles() const {
    return tiles;
}

const Tile& Board::getTile(int id) const {
    return tiles.at(id);
}

int Board::getStartingTile(int playerId) const {
    // Return starting tile based on player ID
    switch (playerId) {
    case 0: return 0;
    case 1: return 13;
    case 2: return 26;
    case 3: return 39;
    default: return 0;
    }
}

int Board::getHomeTile(int playerId) const {
    // Return home tile based on player ID
    // Adjust according to game rules
    return getStartingTile(playerId);
}

int Board::getTotalTiles() const {
    return static_cast<int>(tiles.size());
}
