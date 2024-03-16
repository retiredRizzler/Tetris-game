#include "GameBoard.h"

GameBoard::GameBoard(int rows, int cols) : rows(rows), cols(cols) {
    // Initialize the game board with nullptrs
    board.resize(rows, std::vector<Piece*>(cols, nullptr));
}

GameBoard::~GameBoard() {
    // Free memory for pieces on the board
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            delete board[i][j];
        }
    }
}

int GameBoard::getRows() const {
    return rows;
}

int GameBoard::getCols() const {
    return cols;
}

Piece* GameBoard::getPieceAt(int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return board[row][col];
    }
    return nullptr; // Return nullptr for out-of-bounds indices
}

void GameBoard::setPieceAt(int row, int col, Piece* piece) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        board[row][col] = piece;
    }
}
