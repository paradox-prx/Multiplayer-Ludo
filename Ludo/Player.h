#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.h"
#include <vector>

// Forward declarations
class Board;
class Dice;

class Player {
public:
    virtual ~Player() {}
    virtual void takeTurn(Board& board, Dice& dice) = 0;
    std::vector<Piece>& getPieces();
    int getPlayerID() const;
    bool hasWon() const;
protected:
    int playerID;
    std::vector<Piece> pieces;
};

#endif // PLAYER_H
