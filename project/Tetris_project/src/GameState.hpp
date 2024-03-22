#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Piece.h"
#include "PieceBag.h" // Include PieceBag.h

class GameState {
private:
    int score;
    std::shared_ptr<Piece> currentPiece; // Use unique_ptr for current piece ownership
    int currentLevel;
    std::shared_ptr<Piece> nextPiece; // Use shared_ptr for next piece (potential preview)
    bool gameOver;

public:
    // Constructor (consider using PieceBag for next piece)
    GameState(int score, std::shared_ptr<Piece> currentPiece, int currentLevel, PieceBag& pieceBag)
        : score(score), currentPiece(std::move(currentPiece)), currentLevel(currentLevel) {
        nextPiece = pieceBag.getNextPiece(); // Get next piece from PieceBag
        gameOver = false;
    }

    // Accesseurs (modify return types if needed)
    int getScore() const {
        return score;
    }

    const std::shared_ptr<Piece>& getCurrentPiece() const {
        return currentPiece;
    }

    int getCurrentLevel() const {
        return currentLevel;
    }

    const std::shared_ptr<Piece>& getNextPiece() const {
        return nextPiece;
    }

    bool isGameOver() const {
        return gameOver;
    }

    // Mutators
    void setScore(int score) {
        this->score = score;
    }

    // Consider separate method to update current piece using PieceBag
    void updateCurrentPiece(PieceBag& pieceBag) {
        currentPiece = std::move(pieceBag.getNextPiece()); // Get next piece and transfer ownership
        nextPiece = pieceBag.getNextPiece(); // Update next piece for preview (optional)
    }

    void setCurrentLevel(int level) {
        currentLevel = level;
    }

    void setGameOver(bool isOver) {
        gameOver = isOver;
    }
};

#endif // GAMESTATE_HPP
