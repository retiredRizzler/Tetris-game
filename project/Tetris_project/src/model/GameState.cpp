#include "GameState.h"

GameState::GameState(int score, std::shared_ptr<Piece> currentPiece, int currentLevel)
    : score(score), currentPiece(std::move(currentPiece)), currentLevel(currentLevel) {
    gameOver = false;
}

int GameState::getScore() const {
    return score;
}

const std::shared_ptr<Piece>& GameState::getCurrentPiece() const {
    return currentPiece;
}

int GameState::getCurrentLevel() const {
    return currentLevel;
}

const std::shared_ptr<Piece>& GameState::getNextPiece() const {
    return nextPiece;
}

bool GameState::isGameOver() const {
    return gameOver;
}

void GameState::setScore(int score) {
    this->score = score;
}

void GameState::updateCurrentPiece(PieceBag& pieceBag) {
    currentPiece = std::move(pieceBag.getNextPiece());
    nextPiece = pieceBag.getNextPiece(); // Update next piece
}

void GameState::setCurrentLevel(int level) {
    currentLevel = level;
}

void GameState::setGameOver(bool isOver) {
    gameOver = isOver;
}
