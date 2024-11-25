#pragma once
#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
public:
    Tile(int id, bool isSafeZone);
    int getId() const;
    bool isSafeZone() const;
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& pos);
private:
    int id;
    bool safeZone;
    sf::Vector2f position;
};

#endif // TILE_H
