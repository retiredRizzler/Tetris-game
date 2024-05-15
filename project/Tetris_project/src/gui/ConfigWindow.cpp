// configwindow.cpp
#include <QVBoxLayout>
#include "configwindow.h"

ConfigWindow::ConfigWindow(QWidget *parent) :
        QWidget(parent)
{
    setWindowTitle("Game configurations");

    widthLabel = new QLabel("Width:", this);
    heightLabel = new QLabel("Height:", this);
    levelLabel = new QLabel("Level:", this);
    prefilledLabel = new QLabel("Prefilled Board:", this);

    widthSpinBox = new QSpinBox(this);
    heightSpinBox = new QSpinBox(this);
    levelSpinBox = new QSpinBox(this);

    prefilledYesRadio = new QRadioButton("Yes", this);
    prefilledNoRadio = new QRadioButton("No", this);

    startButton = new QPushButton("Start Game", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(widthLabel);
    layout->addWidget(widthSpinBox);
    layout->addWidget(heightLabel);
    layout->addWidget(heightSpinBox);
    layout->addWidget(levelLabel);
    layout->addWidget(levelSpinBox);
    layout->addWidget(prefilledLabel);
    layout->addWidget(prefilledYesRadio);
    layout->addWidget(prefilledNoRadio);
    layout->addWidget(startButton);

    setLayout(layout);

    connect(startButton, &QPushButton::clicked, this, &ConfigWindow::startGame);
}

ConfigWindow::~ConfigWindow()
{
    delete widthLabel;
    delete heightLabel;
    delete levelLabel;
    delete prefilledLabel;
    delete widthSpinBox;
    delete heightSpinBox;
    delete levelSpinBox;
    delete prefilledYesRadio;
    delete prefilledNoRadio;
    delete startButton;}

void ConfigWindow::startGame()
{
    int width = widthSpinBox->value();
    int height = heightSpinBox->value();
    bool usePrefilled = prefilledYesRadio->isChecked();
    int level = levelSpinBox->value();

    emit startGameRequested(width, height, usePrefilled, level);
}
