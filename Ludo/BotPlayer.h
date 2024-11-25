// BotPlayer.h
#ifndef BOTPLAYER_H
#define BOTPLAYER_H
#include "Player.h"

// Forward declarations
class Board;
class Dice;

class BotPlayer : public Player {
public:
    BotPlayer(int id);
    void takeTurn(Board& board, Dice& dice) override;
private:
    void decideMove(int roll, Board& board);
};

#endif // BOTPLAYER_H
