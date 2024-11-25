// Tile.cpp
#include "Tile.h"

Tile::Tile(int id, bool isSafeZone) : id(id), safeZone(isSafeZone), position(0.0f, 0.0f) {}

int Tile::getId() const {
    return id;
}

bool Tile::isSafeZone() const {
    return safeZone;
}

sf::Vector2f Tile::getPosition() const {
    return position;
}

void Tile::setPosition(const sf::Vector2f& pos) {
    position = pos;
}
