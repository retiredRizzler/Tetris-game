#include "TetrisModel.h"
#include "GameSate.h"

TetrisModel::TetrisModel(GameBoard& board) : board(board), bag(5), state(0, bag.getNextPiece(), 0) {}

void TetrisModel::startGame() {

}
void TetrisModel::movePieceDown() {
    auto& piece = state.getCurrentPiece();
    if (isColliding(piece, piece->getRow() + 1, piece->getCol())) {
        std::cerr << "Collision detected: please make a valid move"; //Only for debug, will throws exception later
    }
    state.getCurrentPiece()->moveDown();
}

void TetrisModel::movePieceLeft() {
    auto& piece = state.getCurrentPiece();
    if (isColliding(piece, piece->getRow(), piece->getCol() - 1)) {
        std::cerr << "Collision detected: please make a valid move";
    }
    state.getCurrentPiece()->moveLeft();
}

void TetrisModel::movePieceRight() {
    auto& piece = state.getCurrentPiece();
    if (isColliding(piece, piece->getRow(), piece->getCol() + 1)) {
        std::cerr << "Collision detected: please make a valid move";
    }
    state.getCurrentPiece()->moveRight();
}

void TetrisModel::dropPiece() {
    auto& piece = state.getCurrentPiece();
    while (true) {
        if (isColliding(piece, piece->getRow() + 1, piece->getCol())) {
            std::cerr << "Collision detected: please make a valid move";
            break;
        }
        piece->moveDown();
    }
}

void TetrisModel::rotatePiece(char dir) {
    auto& piece = state.getCurrentPiece();
    //if (isColliding(piece, )) {

    //}
    if (dir == 'l') {

    }
}

/**
 * @brief Checks if a piece collides with the board or other pieces.
 *
 * @param piece A shared pointer to the `Piece` object to be checked for collision.
 * @param row The intended row position where the piece should be placed.
 * @param col The intended column position where the piece should be placed.
 * @return `true` if there is a collision, `false` otherwise.
 */
bool TetrisModel::isColliding(const std::shared_ptr<Piece>& piece, int row, int col) const {
    auto occupiedPositions = board.getOccupiedPositions();

    for (const Position& piecePos : piece->getAbsolutePositions()) {
        int pieceNextRow = piecePos.getX() + row;
        int pieceNextCol = piecePos.getY() + col;
        for (const auto occupiedPos : occupiedPositions) {
            if (!board.isInsideBoard(row, col) ||(pieceNextRow == occupiedPos.getX() && pieceNextCol == occupiedPos.getY())) {
                return true;
            }
        }
    }
    return false;
}


