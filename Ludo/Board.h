// Board.h (Updated with methods for starting and home tiles)
#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include <vector>

class Board {
public:
    Board();
    void initialize();
    const std::vector<Tile>& getTiles() const;
    const Tile& getTile(int id) const;
    int getStartingTile(int playerId) const;
    int getHomeTile(int playerId) const;
    int getTotalTiles() const;
private:
    std::vector<Tile> tiles;
};

#endif // BOARD_H
