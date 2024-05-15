#include "GUIController.h"

GUIController::GUIController(QObject *parent)
    : QObject(parent), mainWindow(model), model(10,20)
{

    model.registerObserver(this);

    mainWindow.installEventFilter(this);

    connect(startWindow.getUi().playButton, SIGNAL(clicked(bool)), this, SLOT(playButtonHandler()));
    //connect(restartWindow.getUi().replayPushButton, SIGNAL(clicked(bool)), this, SLOT(restartGame()));
    //connect(restartWindow.getUi().quitPushButton, SIGNAL(clicked(bool)), this, SLOT(quitGame()));
    connect(&timerInterval, &QTimer::timeout, this, &GUIController::intervalAction);
    connect(&timerDuration, &QTimer::timeout, this, &GUIController::stopTimers);
    levelCurrent = model.getState().getCurrentLevel();
    startWindow.show();
}

bool GUIController::eventFilter(QObject *obj, QEvent *event){

    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()) {
        case Qt::Key_Q:
            model.movePieceLeft();
            break;
        case Qt::Key_D:
            model.movePieceRight();
            break;
        case Qt::Key_S:
            model.movePieceDown();
            break;
        case Qt::Key_E:
            model.rotatePiece();
            break;
        case Qt::Key_A:
            model.rotatePiece(1);
            break;
        case Qt::Key_X:
            model.dropPiece();
            break;
        case Qt::Key_L:
            handleEndGame("You left the game!");
            break;
        default:
            break;
        }
    }
    // Pass the event to the parent object (view) for it to handle as well
    return QObject::eventFilter(obj, event);
}

void GUIController::update(Observable* observable) {
    auto model = dynamic_cast<TetrisModel*>(observable);
    if (model) {
        mainWindow.initialize();
        if(levelCurrent != model->getState().getCurrentLevel()){
        levelCurrent = model->getState().getCurrentLevel();
        timerInterval.setInterval((1000/60) * getSpeed());
    }
    }
}

    /**

    QString message;
    switch(model.getGameState()) {
    case GameState::LOSS:
        message = "You lost!";
        break;
    case GameState::SCOREWIN:
        message = "You won! Max score reached!";
        break;
    case GameState::LINESWIN:
        message = "You won! Max lines reached!";
        break;
    case GameState::TIMELOSS:
        message = "You lost! Time out!";
        break;
    default:
        return; // Do nothing for other states and continue playing
    }

    handleEndGame(message);
*/


int GUIController::getSpeed() {
    int speed;

        switch (model.getState().getCurrentLevel()) {
        case 1:
            speed = 60;
            break;
        case 2:
            speed = 53;
            break;
        case 3:
            speed = 49;
            break;
        case 4:
            speed = 45;
            break;
        case 5:
            speed = 41;
            break;
        case 6:
            speed = 37;
            break;
        case 7:
            speed = 33;
            break;
        case 8:
            speed = 28;
            break;
        case 9:
            speed = 23;
            break;
        case 10:
            speed = 18;
            break;
        case 11:
            speed = 13;
            break;
        case 12:
            speed = 9;
            break;
        case 13:
            speed = 9;
            break;
        case 14:
            speed = 8;
            break;
        case 15:
            speed = 7;
            break;
        case 16:
            speed = 6;
            break;
        case 17:
            speed = 5;
            break;
        case 18:
            speed = 4;
            break;
        case 19:
            speed = 3;
            break;
        case 20:
            speed = 2;
            break;
        default:
            if (model.getState().getCurrentLevel() > 20) {
                speed = 2;
            }
        }
        return speed;
}


void GUIController::stopTimers(){
    timerInterval.stop();
    timerDuration.stop();
}

void GUIController::playButtonHandler(){
    int width = startWindow.getWidthSpinBox();
    int height = startWindow.getHeightSpinBox();
    bool prefilled = startWindow.getPrefilledChoice();
    //model.resetGame(width, height, !prefilled);
    model.startGame();

    timerInterval.setInterval((1000/60) * getSpeed());
    timerInterval.start();
    timerDuration.start(model.getTimeDuration()*1000);

    startWindow.close();
    mainWindow.show();
}

void GUIController::intervalAction() {
    model.movePieceDown();
}

void GUIController::handleEndGame(QString message){
    stopTimers();
    mainWindow.close();
    //restartWindow.show();
    //restartWindow.showMessage(message);
}

void GUIController::restartGame(){
    startWindow.cleanRestart();
    //restartWindow.close();
    startWindow.show();
}

void GUIController::quitGame(){
    //restartWindow.close();
}
