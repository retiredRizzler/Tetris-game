#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(TetrisModel& game, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    game(game),
    _scene(this)
{
    // Configure the scene and the graphical view
    ui->setupUi(this);
    QRect viewContentsRect = ui->gameBoard->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    ui->gameBoard->setScene(&_scene);

}

void MainWindow::initialize(){
    ui->gameBoard->scene()->clear();
    displayBoard();
    //displayCurrentBrick();
    ui->level->display(game.getState().getCurrentLevel());
    ui->score->display(game.getState().getScore());
    ui->lineCompleted->display(game.getTotalCompletedLine());
}

void MainWindow::displayBoard(){
    int height = game.getBoard().getCols();
    int width = game.getBoard().getRows();

    // Add rectangles to the scene based on the height and width of the board
    int rectSize = computeRectSize();

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            QRectF rect(col * rectSize, row * rectSize, rectSize, rectSize); // Position and size of the rectangle
            auto piece = game.getBoard().getPieceAt(row, col);

            if (piece != nullptr) {
            _scene.addRect(rect, QPen(Qt::black), QBrush(Qt::red)); // Add the rectangle to the scene
            } else {
                _scene.addRect(rect, QPen(Qt::black), QBrush(Qt::white));
            }
        }
    }
}


int MainWindow::computeRectSize(){
    int height = game.getBoard().getCols();
    int width = game.getBoard().getRows();
    int rectSize;

    if (height > width) {
        rectSize =ui->gameBoard->height() / height * 0.9;
    } else {
        rectSize = ui->gameBoard->width() / width * 0.9;
    }
    return rectSize;
}

MainWindow::~MainWindow()
{
    delete ui;
}
