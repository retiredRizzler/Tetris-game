#include "../model/TetrisModel.h"
#include "../model/observer.h"

class ConsoleView : public Observer {
public:
    void update(const Observable* observable) override {
        // Ensure observable is actually a TetrisModel
        const TetrisModel* model = dynamic_cast<const TetrisModel*>(observable);
        if (model) {
            displayBoard(*model);
            displayLevel(*model);
            displayScore(*model);
        } else {
            // Handle error: observable is not a TetrisModel
            std::cerr << "Error: Invalid observable type!" << std::endl;
        }
    }

private:
    void displayWelcome() {
        std::cout << "Welcome to the game!" << std::endl;
    }

    void displayBoard(TetrisModel& model) {
        const GameBoard& board = model.getBoard();
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

    void displayLevel(TetrisModel& model) {
        const GameState& state = model.getState();
        std::cout << "Current Level: " << state.getCurrentLevel() << std::endl;
    }

    void displayScore(TetrisModel& model) {
        const GameState& state = model.getState();
        std::cout << "Score: " << state.getScore() << std::endl;
    }
};
