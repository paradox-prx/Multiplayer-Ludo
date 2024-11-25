// Player.cpp (Implementation)
#include "Player.h"

std::vector<Piece>& Player::getPieces() {
    return pieces;
}

int Player::getPlayerID() const {
    return playerID;
}

bool Player::hasWon() const {
    // Check if all pieces have reached the end
    for (const auto& piece : pieces) {
        if (!piece.isAtHome()) {
            return false;
        }
    }
    return true;
}
