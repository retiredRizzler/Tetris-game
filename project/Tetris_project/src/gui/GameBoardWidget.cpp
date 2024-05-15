#include "GameBoardWidget.h"
#include <QPainter>

GameBoardWidget::GameBoardWidget(QWidget *parent, TetrisModel *model) : QWidget(parent), model(model)
{
    // Set initial block size
    blockSize = 10; // Adjust this as needed
}

void GameBoardWidget::updateBoard()
{
    update(); // Trigger paintEvent to redraw the board
}

void GameBoardWidget::paintEvent(QPaintEvent *event)
{
    GameBoard& board = model->getBoard();
    Q_UNUSED(event); // Ignore compiler warning about unused variable, source : chat.openai

    QPainter painter(this);

    // Set pen color to black for drawing the border
    painter.setPen(Qt::black);

    // Draw the border rectangle around the entire grid
    painter.drawRect(0, 0, board.getCols() * blockSize, board.getRows() * blockSize);

    // Iterate through each cell in the game board
    for (int row = 0; row < board.getRows(); ++row) {
        for (int col = 0; col < board.getCols(); ++col) {
            // Draw a rectangle for each cell
            painter.drawRect(col * blockSize, row * blockSize, blockSize, blockSize);
            auto piece = board.getPieceAt(row, col);
            // If the cell is occupied by a piece, fill it with color
            if (piece != nullptr) {
                painter.fillRect(col * blockSize, row * blockSize, blockSize, blockSize, Qt::red); // Adjust color as needed
            }
        }
    }
}
