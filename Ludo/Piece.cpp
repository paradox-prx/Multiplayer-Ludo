// Piece.cpp (Complete implementation)
#include "Piece.h"

Piece::Piece(int ownerId) : ownerId(ownerId), currentTileId(-1), atHome(false) {}

int Piece::getOwnerId() const {
    return ownerId;
}

int Piece::getCurrentTile() const {
    return currentTileId;
}

void Piece::setCurrentTile(int tileId) {
    currentTileId = tileId;
}

void Piece::move(int steps, Board& board) {
    if (currentTileId == -1 && steps == 6) {
        // Move out of starting area
        currentTileId = board.getStartingTile(ownerId);
    }
    else if (currentTileId != -1) {
        currentTileId = (currentTileId + steps) % board.getTotalTiles();
        if (currentTileId == board.getHomeTile(ownerId)) {
            atHome = true;
        }
    }
}

bool Piece::canMove(int steps, const Board& board) const {
    if (atHome) return false;
    if (currentTileId == -1 && steps == 6) return true;
    if (currentTileId != -1) return true;
    return false;
}

bool Piece::isAtHome() const {
    return atHome;
}