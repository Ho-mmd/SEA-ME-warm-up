#ifndef RACINGGAME_H
#define RACINGGAME_H

#include <QWidget>
#include <QLabel>
#include <QMap>
#include <QThread>
#include <QKeyEvent>

class PlayerInputThread : public QThread {
    Q_OBJECT

public:
    PlayerInputThread(int playerNum, QMap<int, bool> &keyState);

signals:
    void movePlayer(int playerNum, int direction);

protected:
    void run() override;

private:
    int playerNum;
    QMap<int, bool> &keyState;
};

class RacingGame : public QWidget {
    Q_OBJECT

public:
    RacingGame(QWidget *parent = nullptr);
    ~RacingGame();
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

public slots:
    void onMovePlayer(int playerNum, int direction);

private:
    QLabel *player1;
    QLabel *player2;
    QLabel *endLabel;
    PlayerInputThread *player1Thread;
    PlayerInputThread *player2Thread;

    QMap<int, bool> keyState;

    void checkBoundary();
    void checkWinCondition();
};

#endif // RACINGGAME_H
