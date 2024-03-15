#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Piece.hpp"
#include <memory>

class GameState {
private:
    int score;
    Piece currentPiece;
    int currentLevel;
    Piece nextPiece;
    bool game_over;

public:
    // Constructeur prenant les valeurs initiales
    GameState(int score, const Piece& currentPiece, int currentLevel, const Piece& nextPiece)
        : score(score), currentPiece(currentPiece), currentLevel(currentLevel), game_over(false),nextPiece(nextPiece) {}

    // Accesseurs
    int getScore() const {
        return score;
    }

    Piece getCurrentPiece() const {
        return currentPiece;
    }

    int getCurrentLevel() const {
        return currentLevel;
    }

    Piece getNextPiece() const {
        return nextPiece;
    }

    bool isGameOver() const {
        return game_over;
    }

    // Mutateurs
    void setScore(int score) {
        this->score = score;
    }

    void setCurrentPiece(const Piece& piece) {
        currentPiece = piece;
    }

    void setNextPiece(const Piece& piece) {
        nextPiece = piece;
    }

    void setCurrentLevel(int level) {
        currentLevel = level;
    }
};

#endif // GAMESTATE_HPP
