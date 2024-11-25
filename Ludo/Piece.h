// Piece.h (Updated with movement methods)
#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include "Board.h"

class Piece {
public:
    Piece(int ownerId);
    int getOwnerId() const;
    int getCurrentTile() const;
    void setCurrentTile(int tileId);
    void move(int steps, Board& board);
    bool canMove(int steps, const Board& board) const;
    bool isAtHome() const;
private:
    int ownerId;
    int currentTileId; // -1 indicates the piece is at the starting area
    bool atHome; // True if the piece has reached the end
};

#endif // PIECE_H
