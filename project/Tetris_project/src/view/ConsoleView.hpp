#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP

#include "../model/GameBoard.h"
#include "../model/GameSate.h"
#include <iostream>
#include <string>

class ConsoleView {
public:
    // Method to display the welcome message
    static void displayWelcome() {
        std::cout << "Welcome to the game!" << std::endl;
    }

    static void displayBoard(const GameBoard& board) {
        for (int i = 0; i < board.getCols() + 2; ++i) {
            std::cout << "#";
        }
        std::cout << std::endl;

        for (int row = 0; row < board.getRows(); ++row) {
            std::cout << "#";
            for (int col = 0; col < board.getCols(); ++col) {
                bool hasPiece = false;

                // Check for overlapping pieces and print "X" for any occupied space
                for (int r = 0; r < board.getRows(); ++r) {
                    for (int c = 0; c < board.getCols(); ++c) {
                        auto piece = board.getPieceAt(r, c);
                        if (piece != nullptr) {
                            for (const auto& pos : piece->getAbsolutePositions()) {
                                if (pos.getX() == row && pos.getY() == col) {
                                    hasPiece = true;
                                    std::cout << "X";
                                    break; // Exit inner loop if position found
                                }
                            }
                        }
                    }
                }
                if (!hasPiece) {
                    std::cout << " "; // Empty space
                }
            }
            std::cout << "#" << std::endl;
        }
        for (int i = 0; i < board.getCols() + 2; ++i) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }




    // Method to display the current level
    static void displayLevel(const GameState& state) {
        std::cout << "Current Level: " << state.getCurrentLevel() << std::endl;
    }

     // Method to display the score
    static void displayScore(const GameState& state) {
        std::cout << "Score: " << state.getScore() << std::endl;
    }

    // Method to display the game state
    static void displayState(const GameState& state) {
        if (state.isGameOver()) {
            std::cout << "Game Over!" << std::endl;
        } else {
            std::cout << "Game is still ongoing." << std::endl;
        }
    }

    // Method to display an error message
    static void displayError(const std::string& msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    // Method to display the end of the game
    static void displayEnd() {
        std::cout << "Game ended. Goodbye!" << std::endl;
    }
};

#endif // CONSOLEVIEW_HPP
