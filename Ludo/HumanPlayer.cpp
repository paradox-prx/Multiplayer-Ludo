// HumanPlayer.cpp
#include "HumanPlayer.h"
#include "Dice.h" // Add this line

#include <iostream>

HumanPlayer::HumanPlayer(int id) {
    playerID = id;
    // Initialize pieces
    for (int i = 0; i < 4; ++i) {
        pieces.emplace_back(playerID);
    }
}

void HumanPlayer::takeTurn(Board& board, Dice& dice) {
    std::cout << "Player " << playerID << "'s turn.\n";
    int roll = dice.roll();
    std::cout << "You rolled a " << roll << ".\n";

    // Display movable pieces
    std::vector<int> movablePieces;
    for (size_t i = 0; i < pieces.size(); ++i) {
        if (pieces[i].canMove(roll, board)) {
            movablePieces.push_back(static_cast<int>(i));
        }
    }

    if (movablePieces.empty()) {
        std::cout << "No pieces can be moved.\n";
        return;
    }

    // Ask player to select a piece
    int choice = -1;
    while (choice < 0 || choice >= static_cast<int>(movablePieces.size())) {
        std::cout << "Select a piece to move:\n";
        for (size_t i = 0; i < movablePieces.size(); ++i) {
            std::cout << i << ": Piece " << movablePieces[i] << "\n";
        }
        std::cin >> choice;
    }

    // Move the selected piece
    pieces[movablePieces[choice]].move(roll, board);
}
