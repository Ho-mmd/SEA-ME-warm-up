#include "racinggame.h"
#include <QPainter>
#include <QApplication>

// PlayerInputThread Constructor
// playerNum: The player number (1 or 2)
// keyState: A reference to a map containing the current state of key presses
PlayerInputThread::PlayerInputThread(int playerNum, QMap<int, bool> &keyState)
    : playerNum(playerNum), keyState(keyState) {}

// Thread run function, checks for key presses and emits a signal to move the player
void PlayerInputThread::run() {
    while(true) {
        int direction = -1;
        if(playerNum == 1) {
            if(keyState[Qt::Key_W]) direction = 0;  // Up
            else if(keyState[Qt::Key_S]) direction = 1;  // Down
            else if(keyState[Qt::Key_A]) direction = 2;  // Left
            else if(keyState[Qt::Key_D]) direction = 3;  // Right
        } else {
            if(keyState[Qt::Key_Up]) direction = 0;  // Up
            else if(keyState[Qt::Key_Down]) direction = 1;  // Down
            else if(keyState[Qt::Key_Left]) direction = 2;  // Left
            else if(keyState[Qt::Key_Right]) direction = 3;  // Right
        }

        if(direction != -1)
            emit movePlayer(playerNum, direction);

        QThread::msleep(50); // Sleep to prevent excessive CPU usage
    }
}

// RacingGame Constructor
RacingGame::RacingGame(QWidget *parent) : QWidget(parent) {
    this->setFixedSize(400, 400); // Set window size

    player1 = new QLabel(this);
    player2 = new QLabel(this);
    endLabel = new QLabel(this);

    // Configure players and label
    player1->setGeometry(10, 190, 20, 20);
    player1->setStyleSheet("background-color: red;");
    player2->setGeometry(10, 190, 20, 20);
    player2->setStyleSheet("background-color: blue;");

    endLabel->setGeometry(150, 190, 100, 20);
    QFont font = endLabel->font();
    font.setPointSize(6);
    endLabel->setFont(font);
    endLabel->hide();

    // Create threads and connect signals to slots
    player1Thread = new PlayerInputThread(1, keyState);
    player2Thread = new PlayerInputThread(2, keyState);

    connect(player1Thread, &PlayerInputThread::movePlayer, this, &RacingGame::onMovePlayer);
    connect(player2Thread, &PlayerInputThread::movePlayer, this, &RacingGame::onMovePlayer);

    // Start player threads
    player1Thread->start();
    player2Thread->start();
}

// Destructor, terminates threads
RacingGame::~RacingGame() {
    player1Thread->terminate();
    player2Thread->terminate();
    delete player1Thread;
    delete player2Thread;
}

// Key press event handler, sets the state of the pressed key to true
void RacingGame::keyPressEvent(QKeyEvent *event) {
    keyState[event->key()] = true;
}

// Key release event handler, sets the state of the released key to false
void RacingGame::keyReleaseEvent(QKeyEvent *event) {
    keyState[event->key()] = false;
}

// Slot to move a player, called when a direction key is pressed
void RacingGame::onMovePlayer(int playerNum, int direction) {
    QLabel *player = (playerNum == 1) ? player1 : player2;
    int x = player->x();
    int y = player->y();

    switch(direction) { // Adjust coordinates based on direction
        case 0: y -= 5; break; // Up
        case 1: y += 5; break; // Down
        case 2: x -= 5; break; // Left
        case 3: x += 5; break; // Right
    }

    player->move(x, y);
    checkBoundary(); // Check if the player is out of bounds
    checkWinCondition(); // Check if a player has won
}

// Paint event handler, draws the boundaries and starting/finishing lines
void RacingGame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen(Qt::black, 2);

    painter.setPen(pen);

    // Draw boundaries
    painter.drawRect(0, 0, 400, 400);

    // Draw starting and finishing lines
    painter.drawLine(10, 0, 10, 400); // Starting line
    painter.drawLine(390, 0, 390, 400); // Finishing line

    QWidget::paintEvent(event);
}

// Check if a player is out of bounds, end the game if so
void RacingGame::checkBoundary() {
    if (player1->x() < 0 || player1->x() > this->width() ||
        player1->y() < 0 || player1->y() > this->height()) {
        endLabel->setText("Blue Wins!");
        endLabel->show();
    } else if (player2->x() < 0 || player2->x() > this->width() ||
               player2->y() < 0 || player2->y() > this->height()) {
        endLabel->setText("Red Wins!");
        endLabel->show();
    }
}

// Check if a player has reached the finish line, end the game if so
void RacingGame::checkWinCondition() {
    if (player1->x() > 380 && player1->y() > 180 && player1->y() < 220) {
        endLabel->setText("Red Wins!");
        endLabel->show();
    } else if (player2->x() > 380 && player2->y() > 180 && player2->y() < 220) {
        endLabel->setText("Blue Wins!");
        endLabel->show();
    }
}
