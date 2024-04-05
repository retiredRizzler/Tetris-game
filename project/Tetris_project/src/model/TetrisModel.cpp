#include "TetrisModel.h"

TetrisModel::TetrisModel(int boardRow, int boardCol) :
    board(boardRow,boardCol), bag(5),
    state(0, bag.getNextPiece(), 1) {}

void TetrisModel::startGame() {
    spawnPiece();
    dropScore = 0;
    totalCompletedLine = 0;
    startTime = std::chrono::steady_clock::now();
}

void TetrisModel::spawnPiece() {
    auto& piece = state.getCurrentPiece();

    int spawnRow = 0;
    int spawnCol = board.getCols() / 2;
    board.setPieceAt(spawnRow, spawnCol, piece);

    // Move the piece down until it's completely within the board
    while (!pieceCompletelyInsideBoard()) {
        state.getCurrentPiece()->moveDown();
    }
    setCurrentPieceOnBoard();
}

bool TetrisModel::pieceCompletelyInsideBoard() {
    auto& piece = state.getCurrentPiece();

    for (const auto& pos : piece->getAbsolutePositions()) {
        if (!board.isInsideBoard(pos.getX(), pos.getY())) {
            return false;
        }
    }

    return true;
}

void TetrisModel::movePieceDown() {
    auto& piece = state.getCurrentPiece();
    if (!canMoveDown()) {
        std::cerr << ("Collision detected while moving piece down. ");
    }
    deleteCurrentPieceFromBoard();
    state.getCurrentPiece()->moveDown();
    setCurrentPieceOnBoard();
}

void TetrisModel::deleteCurrentPieceFromBoard() {
    for (const auto& pos : state.getCurrentPiece()->getAbsolutePositions()) {
        board.at(pos.getX(), pos.getY()).reset();
    }
}

void TetrisModel::setCurrentPieceOnBoard() {

    for (const auto& pos : state.getCurrentPiece()->getAbsolutePositions()) {
        board.at(pos.getX(), pos.getY()) = state.getCurrentPiece();
    }
}

void TetrisModel::movePieceLeft() {
    auto& piece = state.getCurrentPiece();
    if (isColliding(piece, 0, -1)) {
        std::cerr << "Collision detected while moving piece left. ";
        return;
    }

        deleteCurrentPieceFromBoard();
        state.getCurrentPiece()->moveLeft();
        setCurrentPieceOnBoard();

}

void TetrisModel::movePieceRight() {
    auto& piece = state.getCurrentPiece();
    if (isColliding(piece, 0, 1)) {
        std::cerr << "Collision detected while moving piece right. ";
        return;
    }

        deleteCurrentPieceFromBoard();
        state.getCurrentPiece()->moveRight();
        setCurrentPieceOnBoard();

}

void TetrisModel::dropPiece() {
    auto& piece = state.getCurrentPiece();
    int dropCount = 0;
    while (true) {
        if (!canMoveDown()) {
            std::cerr << "Collision detected while dropping piece. ";
            break;
        }
        movePieceDown();
        if (dropCount > 1) {
            dropScore++;
        }
        dropCount++;
    }
}

void TetrisModel::rotatePiece(char dir) {
    auto& piece = state.getCurrentPiece();
    std::vector<std::vector<int>> rotationMatrix = piece->getRotationMatrix();// source : Gemini (google AI)
    //rotate clockwise
    if (dir == 'r') {
        for (const auto &piecePos: piece->getShape()) {
            int deltaRow = rotationMatrix[0][0] * piecePos.getX() + rotationMatrix[0][1] * piecePos.getY();
            int deltaCol = rotationMatrix[1][0] * piecePos.getX() + rotationMatrix[1][1] * piecePos.getY() ;
            for (const auto& absPos : piece->getAbsolutePositions()) {
                int pieceNextRow = absPos.getX() + deltaRow;
                int pieceNextCol = absPos.getY() + deltaCol;
                if (!board.isInsideBoard(pieceNextRow, pieceNextCol)
                    //Have to check it's not the position of the currentPiece so we avoid self piece collision
                    || (board.at(pieceNextRow, pieceNextCol) != piece
                        && board.at(pieceNextRow, pieceNextCol) != nullptr)) {
                    std::cerr << "Collision detected while rotating piece. ";
                    return;
                }
                break; // Here the break is very important to update correctly deltaRow and deltaCol for each absPos
            }
        }
        deleteCurrentPieceFromBoard();
        piece->rotateClockwise();
        setCurrentPieceOnBoard();

        //Same logic for rotate counterclockwise
    } else {
        //negate the matrix to rotate counterclockwise, source : Gemini
        piece->negateMatrix(rotationMatrix);
        for (const auto &piecePos: piece->getShape()) {
            int deltaRow = rotationMatrix[0][0] * piecePos.getX() + rotationMatrix[0][1] * piecePos.getY();
            int deltaCol = rotationMatrix[1][0] * piecePos.getX() + rotationMatrix[1][1] * piecePos.getY() ;
            for (const auto& absPos : piece->getAbsolutePositions()) {
                int pieceNextRow = absPos.getX() + deltaRow;
                int pieceNextCol = absPos.getY() + deltaCol;
                if (!board.isInsideBoard(pieceNextRow, pieceNextCol)
                    || (board.at(pieceNextRow, pieceNextCol) != piece
                        && board.at(pieceNextRow, pieceNextCol) != nullptr)) {
                    std::cerr << "Collision detected while rotating piece";
                    return;
                }
                break;
            }
        }
        deleteCurrentPieceFromBoard();
        piece->rotateCounterClockwise();
        setCurrentPieceOnBoard();
    }
}

bool TetrisModel::isGameOver(){
    auto currentPiece = state.getCurrentPiece();
    if(!canMoveDown()) {
        std::cerr << "Piece couldn't spawn. ";
        return true;
    }

    if (state.getScore() >= MAX_SCORE) {
        std::cerr << "Maximum score reached. ";
        return true;
    }

    if (totalCompletedLine >= MAX_COMPLETED_LINES) {
        std::cerr << "You completed 100 lines. ";
        return true;
    }

    //source chat.openai.com
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = currentTime - startTime;
    if (elapsedTime.count() >= MAX_TIME_SECONDS) {
        std::cerr << "Maximum time reached game is over";
        return true;
    }
    return false;
}

void TetrisModel::updateGame() {
    auto currentPiece = state.getCurrentPiece();
    if (!canMoveDown()) {
        std::cerr << "Can't move down, updating game"; //Only for debug, will throws exception later
        int completedLine = board.clearCompletedLines();
        totalCompletedLine = completedLine;
        updateScore(completedLine);
        dropScore = 0; // so next time the player drops a piece, score wont be false
        if (totalCompletedLine >= 10 && totalCompletedLine % 10 == 0) {
            state.incrementCurrentLevel();
        }
        state.updateCurrentPiece(bag);
        spawnPiece();
        startTime = std::chrono::steady_clock::now();
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
    if (isColliding(currentPiece, 1, 0)) {
        return false;
    }
    return true;
}

void TetrisModel::updateScore(int completedLine) {
    int computedScore;
    switch (completedLine) {
    case 0:
    case 1:
        computedScore = (40 * completedLine + dropScore) * state.getCurrentLevel();
        break;
    case 2:
        computedScore = (100 * completedLine + dropScore) * state.getCurrentLevel();
        break;
    case 3:
        computedScore = (300 * completedLine + dropScore) * state.getCurrentLevel();
        break;
    case 4:
        computedScore = (1200 * completedLine + dropScore) * state.getCurrentLevel();
        break;
    default:
        throw std::out_of_range("max of completed line reached, see if totalCompletedLine is updated correctly");
    }
    state.incrementScore(computedScore);
}

bool TetrisModel::isColliding(const std::shared_ptr<Piece>& piece, int deltaRow, int deltaCol) const {
    for (const Position& piecePos : piece->getAbsolutePositions()) {
        int pieceNextRow = piecePos.getX() + deltaRow;
        int pieceNextCol = piecePos.getY() + deltaCol;
        // if piece is not inside the board, or reach another piece isColliding == true
        if (!board.isInsideBoard(pieceNextRow, pieceNextCol)
        //Have to check it's not the position of the currentPiece
                || (board.at(pieceNextRow, pieceNextCol) != piece
                    && board.at(pieceNextRow, pieceNextCol) != nullptr)) {
            return true;
        }
    }
    return false;
}


