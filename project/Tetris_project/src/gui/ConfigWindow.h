// configwindow.h
#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QRadioButton>
#include <QPushButton>

class ConfigWindow : public QWidget
{
Q_OBJECT

public:
    explicit ConfigWindow(QWidget *parent = nullptr);
    ~ConfigWindow();

signals:
    void startGameRequested(int width, int height, bool usePrefilled, int level);

private slots:
    void startGame();

private:
    QLabel *widthLabel;
    QLabel *heightLabel;
    QLabel *levelLabel;
    QLabel *prefilledLabel;

    QSpinBox *widthSpinBox;
    QSpinBox *heightSpinBox;
    QSpinBox *levelSpinBox;

    QRadioButton *prefilledYesRadio;
    QRadioButton *prefilledNoRadio;

    QPushButton *startButton;
};

#endif // CONFIGWINDOW_H
