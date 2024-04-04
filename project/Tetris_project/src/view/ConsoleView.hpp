#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP

#include "../model/TetrisModel.h" // Include necessary headers
#include "../model/observer.h"
#include <string>
#include <iostream>
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BOLD "\033[1m"
#define RESET "\033[0m"
/**
 * @class ConsoleView
 * @brief Represents the console view of the Tetris game.
 *
 * The ConsoleView class is responsible for displaying the game state and board
 * in the console for the user to interact with.
 */
class ConsoleView : public Observer {
public:
    /**
     * @brief Updates the view based on changes in the observable object.
     * @param observable Pointer to the observable object.
     */
    void update(Observable* observable) override {
        auto model = dynamic_cast<TetrisModel*>(observable);
        if (model) {
            displayBoard(model);
            displayLevel(model);
            displayScore(model);
        } else {
            std::cerr << "Error: Invalid observable type!" << std::endl;
        }
    }

    /**
     * @brief Displays the welcome message when the game starts.
     */
    void displayWelcome() {
        std::cout << std::endl;
        std::cout << "\033[1;1H";

        for (int i = 0; i < 40; ++i) {
            std::cout << "\033[35m=";
        }
        std::cout << std::endl;

        std::cout << "\033[1m";
        std::cout << "  \033[32m Welcome \033[31m to \033[34mthe \033[36mTetris \033[33mgame !";
        std::cout << "\033[0m" << std::endl;

        for (int i = 0; i < 40; ++i) {
            std::cout << "\033[35m=";
        }
        std::cout << std::endl << std::endl;

        std::cout << "\033[34mPress a key command to make a move..." << std::endl;
        std::cin.get();
    }

    void displayCommands() {
        std::cout << "\n\033[1mTetris Commands:\033[0m\n";
        std::cout << "r - Rotate the current piece clockwise.\n";
        std::cout << "a - Rotate the current piece counter-clockwise.\n";
        std::cout << "q - Move the current piece left.\n";
        std::cout << "s - Move the current piece down.\n";
        std::cout << "d - Move the current piece right.\n";
        std::cout << "x - Drop the current piece to the bottom.\n";
        std::cout << "Enter your command: " << std::endl;
    }

private:
    /**
     * @brief Displays the game board.
     * @param model Pointer to the TetrisModel object.
     */
    void displayBoard(TetrisModel* model) {
        std::cout << std::endl;
        const GameBoard& board = model->getBoard();
        for (int i = 0; i < board.getCols() + 2; ++i) {
            std::cout << "#";
        }
        std::cout << std::endl;

        for (int row = 0; row < board.getRows(); ++row) {
            std::cout << "#";
            for (int col = 0; col < board.getCols(); ++col) {
                std::shared_ptr<Piece> piece = board.getPieceAt(row, col);
                if (piece != nullptr) {
                    std::cout << "X"; // For now, print "X" to represent a piece
                } else {
                    std::cout << " ";
                }
            }
            std::cout << "#" << std::endl;
        }
        for (int i = 0; i < board.getCols() + 2; ++i) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }

    /**
     * @brief Displays the current level of the game.
     * @param model Pointer to the TetrisModel object.
     */
    void displayLevel(TetrisModel* model) {
        const GameState& state = model->getState();
        int level = state.getCurrentLevel();
        std::string difficulty = "Easy";
        if (level > 5) difficulty = "Medium";
        if (level > 10) difficulty = "Hard";

        std::cout << "\033[1m" << YELLOW << "Level: " << RESET << level << " (" << difficulty << ")" << std::endl;
    }

    /**
     * @brief Displays the current score of the game.
     * @param model Pointer to the TetrisModel object.
     */
    void displayScore(TetrisModel* model) {
        const GameState& state = model->getState();
        std::cout << "\033[1m" << GREEN << "Current Score: " << state.getScore() << "\033[0m" << std::endl;
    }
};

#endif // CONSOLEVIEW_HPP
