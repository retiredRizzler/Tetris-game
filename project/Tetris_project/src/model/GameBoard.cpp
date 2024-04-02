#include "GameBoard.h"
#include <algorithm>

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
    if (!isInsideBoard(row, col)) {
        throw std::out_of_range("Tried to place a piece outside the board!");
    }
    piece->setPosition(row, col);
    board[row][col] = piece;
}

bool GameBoard::isInsideBoard(int row, int col) const {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

std::vector<Position> GameBoard::getOccupiedPositions() const {
    std::vector<Position> occupiedPositions;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            std::shared_ptr<Piece> piece = board[row][col];
            if (piece != nullptr) {
                for (const auto& position : piece->getAbsolutePositions()) {
                    occupiedPositions.push_back(position);
                }
            }
        }
    }

    return occupiedPositions;
}

/**
 * @brief Clears completed lines and shifts pieces down.
 * @return A vector containing the indices of the cleared rows.
 */
std::vector<int> GameBoard::clearCompletedLines() {
    // 1. Identify completed lines
    std::vector<int> completedRows;
    for (int row = 0; row < rows; ++row) {
        bool isCompleted = true;
        for (int col = 0; col < cols; ++col) {
            if (getPieceAt(row, col) == nullptr) {
                isCompleted = false;
                break;
            }
        }
        if (isCompleted) {
            completedRows.push_back(row);
        }
    }

    // 2. Remove completed lines and shift pieces down
    if (!completedRows.empty()) {
        int nbClearedLines = completedRows.size(); //Very important to keep track of the number of rows to shift down the piece
        for (int clearedRow = rows - 1; clearedRow >= 0; --clearedRow) {
            if (std::find(completedRows.begin(), completedRows.end(), clearedRow) != completedRows.end()) {
                // Clear completed row
                for (int col = 0; col < cols; ++col) {
                    setPieceAt(clearedRow, col, nullptr);
                }

                // Shift down remaining pieces above the cleared row
                for (int row = clearedRow - 1; row >= 0; --row) {
                    for (int col = 0; col < cols; ++col) {
                        auto piece = getPieceAt(row, col);
                        if (piece != nullptr) {
                            // Move piece down one row
                            setPieceAt(row, col, nullptr);
                            setPieceAt(row + nbClearedLines, col, piece);
                        }
                    }
                    nbClearedLines++; // Adjust number of cleared lines for shifting
                }
            }
        }
    }
    return completedRows;
}
