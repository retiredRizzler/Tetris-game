#include "GameWindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

GameWindow::GameWindow(QWidget *parent, TetrisModel* model, bool usePrefilled, int level)
        : QMainWindow(parent), model(model)
{
    setWindowTitle("Tetris - Game");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Game board widget
    gameBoardWidget = new GameBoardWidget(this);
    layout->addWidget(gameBoardWidget, 1);

    // Game info labels
    QHBoxLayout *infoLayout = new QHBoxLayout();
    scoreLabel = new QLabel(this);
    scoreLabel->setFont(QFont("Arial", 16, QFont::Bold));
    infoLayout->addWidget(scoreLabel);

    levelLabel = new QLabel(this);
    levelLabel->setFont(QFont("Arial", 16, QFont::Bold));
    infoLayout->addWidget(levelLabel);

    layout->addLayout(infoLayout);

    //Quit and pause button, pause is not implemented yet
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *quitButton = new QPushButton("Quit", this);
    quitButton->setFont(QFont("Arial", 14));
    connect(quitButton, &QPushButton::clicked, this, &GameWindow::quitGame);
    buttonLayout->addWidget(quitButton);

    QPushButton *pauseButton = new QPushButton("Pause", this);
    pauseButton->setFont(QFont("Arial", 14)); // Adjust button font size
    connect(pauseButton, &QPushButton::clicked, this, &GameWindow::pauseGame);
    buttonLayout->addWidget(pauseButton);

    layout->addLayout(buttonLayout);
    centralWidget->setLayout(layout);

    model->getState().setCurrentLevel(level);
    if (usePrefilled) {
        model->fillBoardWithRandomPieces();
    }
    model->startGame();
    model->updateGame();
}


GameWindow::~GameWindow()
{
    delete gameBoardWidget;
    delete scoreLabel;
    delete levelLabel;
}

void GameWindow::quitGame()
{
    close();
}

void GameWindow::pauseGame()
{
    // Implement pause functionality
}

void GameWindow::update(Observable* observable)
{
    auto model = dynamic_cast<TetrisModel*>(observable);
    if (model) {
        gameBoardWidget->updateBoard();
        scoreLabel->setText("Score: " + QString::number(model->getState().getScore()));
        levelLabel->setText("Level: " + QString::number(model->getState().getCurrentLevel()));
    }
}
