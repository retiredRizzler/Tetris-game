#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP

#include <iostream>
//#include "GameBoard.hpp"
#include "GameState.hpp"

class ConsoleView {
public:
    // Method to display the welcome message
    static void displayWelcome() {
        std::cout << "Welcome to the game!" << std::endl;
    }

    // Method to display the game board
/*    static void displayBoard(const GameBoard& board) {

    }*/

    // Method to display the current level
    static void displayLevel(const GameState& state) {
        std::cout << "Current Level: " << state.getCurrentLevel() << std::endl;
    }

    // Method to display the current piece
    static void displayCurrentPiece(const GameState& state) {
        // Implémentation à ajouter car Piece ne peux pas être afficher
    }

    // Method to display the next piece
    static void displayNextPiece(const GameState& state) {
        // Implémentation à ajouter car Piece ne peux pas être afficher
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
