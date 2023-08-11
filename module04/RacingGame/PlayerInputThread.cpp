// PlayerInputThread.cpp
#include <QApplication>
#include <racinggame.h>

void PlayerInputThread::run() {
    while(true) {
        int direction = -1;
        if(playerNum == 1) {
            if(QApplication::keyboardModifiers() & Qt::Key_W) direction = 0;  // Up
            else if(QApplication::keyboardModifiers() & Qt::Key_S) direction = 1;  // Down
            else if(QApplication::keyboardModifiers() & Qt::Key_A) direction = 2;  // Left
            else if(QApplcation::keyboardModifiers() & Qt::Key_D) direction = 3;  // Right
        } else {
            if(QApplication::keyboardModifiers() & Qt::Key_Up) direction = 0;
            else if(QApplication::keyboardModifiers() & Qt::Key_Down) direction = 1;
            else if(QApplication::keyboardModifiers() & Qt::Key_Left) direction = 2;
            else if(QApplication::keyboardModifiers() & Qt::Key_Right) direction = 3;
        }

        if(direction != -1) emit movePlayer(playerNum, direction);

        QThread::msleep(50);  // Reduce CPU usage
    }
}
