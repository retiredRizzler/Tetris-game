#include "GameBoard.h"

GameBoard::GameBoard(int rows, int cols) : rows(rows), cols(cols) {
    board.resize(rows, std::vector<std::shared_ptr<Piece>>(cols, nullptr));
}

int GameBoard::getRows() const {
    return rows;
}

int GameBoard::getCols() const {
    return cols;
}

std::shared_ptr<Piece> GameBoard::getPieceAt(int row, int col) const {
    if (isInsideBoard(row, col)) {
        return board[row][col];
    } else {
        return nullptr;
    }
}

void GameBoard::setPieceAt(int row, int col, const std::shared_ptr<Piece>& piece) {
    if (isInsideBoard(row, col)) {
        board[row][col] = piece;
    }
}

bool GameBoard::isInsideBoard(int row, int col) const {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

bool GameBoard::checkCollision(const std::shared_ptr<Piece>& piece, int row, int col) const {
    // Check if any block of the piece would collide with an occupied space on the board
    for (const Position& pos : piece->getAbsolutePositions()) {
        int absoluteRow = pos.getX() + row;
        int absoluteCol = pos.getY() + col;
        if (!isInsideBoard(absoluteRow, absoluteCol) || getPieceAt(absoluteRow, absoluteCol) != nullptr) {
            return true;
        }
    }
    return false;
}

void GameBoard::clearCompletedLines() {

}
