// BotPlayer.cpp
#include "BotPlayer.h"
#include "Dice.h" // Add this line

#include <iostream>

BotPlayer::BotPlayer(int id) {
    playerID = id;
    // Initialize pieces
    for (int i = 0; i < 4; ++i) {
        pieces.emplace_back(playerID);
    }
}

void BotPlayer::takeTurn(Board& board, Dice& dice) {
    std::cout << "Bot " << playerID << "'s turn.\n";
    int roll = dice.roll();
    std::cout << "Bot rolled a " << roll << ".\n";
    decideMove(roll, board);
}

void BotPlayer::decideMove(int roll, Board& board) {
    // Simple AI: move the first piece that can move
    for (auto& piece : pieces) {
        if (piece.canMove(roll, board)) {
            piece.move(roll, board);
            std::cout << "Bot moved a piece.\n";
            return;
        }
    }
    std::cout << "Bot cannot move any pieces.\n";
}
