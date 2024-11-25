// HumanPlayer.h
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

// Forward declarations
class Board;
class Dice;

class HumanPlayer : public Player {
public:
    HumanPlayer(int id);
    void takeTurn(Board& board, Dice& dice) override;
};

#endif // HUMANPLAYER_H
