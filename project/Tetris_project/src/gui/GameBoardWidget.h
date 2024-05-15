#ifndef GAMEBOARDWIDGET_H
#define GAMEBOARDWIDGET_H

#include <QWidget>
#include "../model/TetrisModel.h"
#include "../model/GameBoard.h"

class GameBoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoardWidget(QWidget *parent = nullptr, TetrisModel *model = nullptr);

    // Function to update the game board
    void updateBoard();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int blockSize; // Size of each block on the board
    TetrisModel *model;
};

#endif // GAMEBOARDWIDGET_H
