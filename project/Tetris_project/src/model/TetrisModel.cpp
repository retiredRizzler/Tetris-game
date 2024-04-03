#include "TetrisModel.h"

TetrisModel::TetrisModel(int boardRow, int boardCol) : board(boardRow,boardCol), bag(5), state(0, bag.getNextPiece(), 1), totalCompletedLine(0)
{}

void TetrisModel:: startGame() {
    board.setPieceAt(0, 5, state.getCurrentPiece());
    startTime = std::chrono::steady_clock::now();
}

void TetrisModel::movePieceDown() {
    auto& piece = state.getCurrentPiece();
    if (!canMoveDown()) {
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
    int dropCount = 0;
    while (true) {
        if (!canMoveDown()) {
            std::cerr << "Collision detected: please make a valid move";
            break;
        }
        piece->moveDown();
        if (dropCount > 1) {
            dropScore++;
        }
        dropCount++;
    }
}

void TetrisModel::rotatePiece(char dir) {
    auto& piece = state.getCurrentPiece();
    std::vector<std::vector<int>> rotationMatrix = piece->getRotationMatrix();// source : Gemini (google AI)
    if (dir == 'r') {
        for (const auto& piecePos : piece->getAbsolutePositions()) {
            int nextRow = rotationMatrix[0][0] * piecePos.getX() + rotationMatrix[0][1] * piecePos.getY();
            int nextCol = rotationMatrix[1][0] * piecePos.getX() + rotationMatrix[1][1] * piecePos.getY();
            if (isColliding(piece, nextRow, nextCol)) {
                std::cerr << "Collision detected: please make a valid move";
                return;
            }
        }
        piece->rotateClockwise();
    } else {
        piece->negateMatrix(rotationMatrix);
        for (const auto& piecePos : piece->getAbsolutePositions()) {
            int nextRow = rotationMatrix[0][0] * piecePos.getX() + rotationMatrix[0][1] * piecePos.getY();
            int nextCol = rotationMatrix[1][0] * piecePos.getX() + rotationMatrix[1][1] * piecePos.getY();
            if (isColliding(piece, nextRow, nextCol)) {
                std::cerr << "Collision detected: please make a valid move";
                return;
            }
        }
        piece->rotateCounterClockwise();
    }
}

bool TetrisModel::isGameOver(){
    auto currentPiece = state.getCurrentPiece();
    if (isColliding(currentPiece, 0, currentPiece->getCol())) {
        return true;
    }

    if (state.getScore() >= MAX_SCORE) {
        return true;
    }

    if (totalCompletedLine >= MAX_COMPLETED_LINES) {
        return true;
    }

    //source chat.openai.com
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = currentTime - startTime;
    if (elapsedTime.count() >= MAX_TIME_SECONDS) {
        std::cerr << "max time reached u've lost";
        return true;
    }
    return false;
}

void TetrisModel::updateGame() {
    auto currentPiece = state.getCurrentPiece();
    if (!canMoveDown()) {
        std::cerr << "Can't move down, updating game"; //Only for debug, will throws exception later
        int completedLine = board.clearCompletedLines();
        updateScore(completedLine);
        dropScore = 0; // so next time the player drops a piece, score wont be false
        totalCompletedLine = 0; //same here but with completedLine

        if (totalCompletedLine % 10 == 0) {
            state.incrementCurrentLevel();
        }
        state.updateCurrentPiece(bag);
        notifyObservers();
    }
}

//Getters for members state, board and bag
GameState& TetrisModel::getState(){
    return state;
}
GameBoard& TetrisModel::getBoard(){
    return board;
}
PieceBag& TetrisModel::getBag(){
    return bag;
}

bool TetrisModel::canMoveDown() {
    auto currentPiece = state.getCurrentPiece();
    if (isColliding(currentPiece, currentPiece->getRow() + 1, currentPiece->getCol())) {
        return false;
    }
    return true;
}

void TetrisModel::updateScore(int completedLine) {
    int computedScore;
    switch (completedLine) {
    case 0:
    case 1:
        computedScore = (40 * totalCompletedLine + dropScore) * state.getCurrentLevel();
        break;
    case 2:
        computedScore = (100 * totalCompletedLine + dropScore) * state.getCurrentLevel();
        break;
    case 3:
        computedScore = (300 * totalCompletedLine + dropScore) * state.getCurrentLevel();
        break;
    case 4:
        computedScore = (1200 * totalCompletedLine + dropScore) * state.getCurrentLevel();
        break;
    default:
        throw std::out_of_range("max of completed line reached, see if totalCompletedLine is updated correctly");
    }
    state.incrementScore(computedScore);
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


