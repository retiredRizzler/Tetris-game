// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameWindow.h"
#include "ConfigWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the "Start Game" button click event to show the configuration window
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::showConfigWindow);

    // Connect the "Quit" button click event to quit the application
    connect(ui->quitButton, &QPushButton::clicked, this, &MainWindow::quitGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showConfigWindow()
{
    ConfigWindow *configWindow = new ConfigWindow(this);

    // Connect the startGameRequested signal from ConfigWindow to startGame slot in MainWindow
    connect(configWindow, &ConfigWindow::startGameRequested, this, &MainWindow::startGame);

    configWindow->show();
}

void MainWindow::startGame(int width, int height, bool usePrefilled, int level)
{
    //First try to find a way to initialyze GameWindow in TetrisGame constrtuctor then
    // Check if it's better to use TetrisModel onstead of TetrisGame
    TetrisGame game(width, height);
    //GameWindow gameWindow(this, &game, usePrefilled, level);
    //gameWindow.show();
}

void MainWindow::quitGame()
{
    close();
}
