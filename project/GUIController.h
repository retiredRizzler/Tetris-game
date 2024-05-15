#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include "model/TetrisModel.h"
#include "startwindow.h"
#include "mainwindow.h"
#include "model/Observer.h"
#include "model/TetrisModel.h"
#include <QObject>
#include <QTimer>
#include <QMutex>

class GUIController : public QObject, public Observer
{
    Q_OBJECT

private:
    TetrisModel model;
    StartWindow startWindow;
    MainWindow mainWindow;
    //RestartWindow restartWindow;
    QTimer timerInterval;
    QTimer timerDuration;
    int levelCurrent;

    bool eventFilter(QObject *obj, QEvent *event) override;
    void update(Observable* observable) override;
    void stopTimers();
    void handleEndGame(QString message = "");

private slots:
    void playButtonHandler();
    void intervalAction();
    void restartGame();
    void quitGame();
    int getSpeed();

public:
    explicit GUIController(QObject *parent = nullptr);
};

#endif // GUICONTROLLER_H
