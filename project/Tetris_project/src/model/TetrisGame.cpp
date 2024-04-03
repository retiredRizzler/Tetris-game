#include "TetrisGame.h"

TetrisGame::TetrisGame(int boardRow, int boardCol) : model(boardRow, boardCol) {}

void TetrisGame::start() {
    model.startGame();
}

void TetrisGame::end() {
//potential function for stop the game, saving score,...
}

bool TetrisGame::isGameOver() {
    return model.isGameOver();
}

void TetrisGame::movePieceDown() {
    model.movePieceDown();
}

void TetrisGame::movePieceLeft() {
    model.movePieceLeft();
}

void TetrisGame::movePieceRight() {
    model.movePieceRight();
}

void TetrisGame::dropPiece() {
    model.dropPiece();
}

void TetrisGame::rotatePiece(char dir) {
    model.rotatePiece(dir);
}

void TetrisGame::updateGame() {
    model.updateGame();
}

GameBoard& TetrisGame::getGameBoard() {
    return model.getBoard();
}
