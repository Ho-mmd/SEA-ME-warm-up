#include "racinggame.h"
#include <QPainter>
#include <QApplication>

PlayerInputThread::PlayerInputThread(int playerNum, QMap<int, bool> &keyState)
    : playerNum(playerNum), keyState(keyState) {}

void PlayerInputThread::run() {
    while(true) {
        int direction = -1;
        if(playerNum == 1) {
            if(keyState[Qt::Key_W]) direction = 0;  // Up
            else if(keyState[Qt::Key_S]) direction = 1;  // Down
            else if(keyState[Qt::Key_A]) direction = 2;  // Left
            else if(keyState[Qt::Key_D]) direction = 3;  // Right
        } else {
            if(keyState[Qt::Key_Up]) direction = 0;
            else if(keyState[Qt::Key_Down]) direction = 1;
            else if(keyState[Qt::Key_Left]) direction = 2;
            else if(keyState[Qt::Key_Right]) direction = 3;
        }

        if(direction != -1) emit movePlayer(playerNum, direction);

        QThread::msleep(50);
    }
}

RacingGame::RacingGame(QWidget *parent) : QWidget(parent) {
    this->setFixedSize(400, 400);

    player1 = new QLabel(this);
    player2 = new QLabel(this);
    endLabel = new QLabel(this);

    player1->setGeometry(10, 190, 20, 20);
    player1->setStyleSheet("background-color: red;");

    player2->setGeometry(10, 190, 20, 20);
    player2->setStyleSheet("background-color: blue;");

    endLabel->setGeometry(150, 190, 100, 20);
    QFont font = endLabel->font();
    font.setPointSize(6);
    endLabel->setFont(font);
    endLabel->hide();

    player1Thread = new PlayerInputThread(1, keyState);
    player2Thread = new PlayerInputThread(2, keyState);

    connect(player1Thread, &PlayerInputThread::movePlayer, this, &RacingGame::onMovePlayer);
    connect(player2Thread, &PlayerInputThread::movePlayer, this, &RacingGame::onMovePlayer);

    player1Thread->start();
    player2Thread->start();
}

RacingGame::~RacingGame() {
    player1Thread->terminate();
    player2Thread->terminate();
    delete player1Thread;
    delete player2Thread;
}

void RacingGame::keyPressEvent(QKeyEvent *event) {
    keyState[event->key()] = true;
}

void RacingGame::keyReleaseEvent(QKeyEvent *event) {
    keyState[event->key()] = false;
}

void RacingGame::onMovePlayer(int playerNum, int direction) {
    QLabel *player = (playerNum == 1) ? player1 : player2;
    int x = player->x();
    int y = player->y();

    switch(direction) {
        case 0:  // Up
            y -= 5;
            break;
        case 1:  // Down
            y += 5;
            break;
        case 2:  // Left
            x -= 5;
            break;
        case 3:  // Right
            x += 5;
            break;
    }

    player->move(x, y);
    checkBoundary();
    checkWinCondition();
}

void RacingGame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen(Qt::black, 2);

    painter.setPen(pen);

    // 경계를 그립니다.
    painter.drawRect(0, 0, 400, 400);

    // 출발선과 도착선을 그립니다.
    painter.drawLine(10, 0, 10, 400);  // 출발선
    painter.drawLine(390, 0, 390, 400);  // 도착선

    QWidget::paintEvent(event);
}

void RacingGame::checkBoundary() {
    if (player1->x() < 0 || player1->x() > this->width() ||
        player1->y() < 0 || player1->y() > this->height()) {
        endLabel->setText("Player 2 Wins!");
        endLabel->show();
    } else if (player2->x() < 0 || player2->x() > this->width() ||
               player2->y() < 0 || player2->y() > this->height()) {
        endLabel->setText("Player 1 Wins!");
        endLabel->show();
    }
}

void RacingGame::checkWinCondition() {
    if (player1->x() > 380 && player1->y() > 180 && player1->y() < 220) {
        endLabel->setText("Player 1 Wins!");
        endLabel->show();
    } else if (player2->x() > 380 && player2->y() > 180 && player2->y() < 220) {
        endLabel->setText("Player 2 Wins!");
        endLabel->show();
    }
}
