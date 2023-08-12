#ifndef RACINGGAME_H
#define RACINGGAME_H

#include <QWidget>
#include <QLabel>
#include <QMap>
#include <QThread>
#include <QKeyEvent>

// PlayerInputThread class handles player input in a separate thread
class PlayerInputThread : public QThread {
    Q_OBJECT

public:
    // Constructor with player number and a reference to the key state map
    PlayerInputThread(int playerNum, QMap<int, bool> &keyState);

signals:
    // Signal to move the player
    void movePlayer(int playerNum, int direction);

protected:
    // Override QThread's run function
    void run() override;

private:
    int playerNum;                // Player number (1 or 2)
    QMap<int, bool> &keyState;   // Reference to the key state map
};

// RacingGame class represents the main game
class RacingGame : public QWidget {
    Q_OBJECT

public:
    // Constructor and Destructor
    RacingGame(QWidget *parent = nullptr);
    ~RacingGame();

    // Overridden from QWidget to handle custom drawing
    void paintEvent(QPaintEvent *event) override;

    // Overridden from QWidget to handle key press events
    void keyPressEvent(QKeyEvent *event) override;

    // Overridden from QWidget to handle key release events
    void keyReleaseEvent(QKeyEvent *event) override;

public slots:
    // Slot to handle player movement
    void onMovePlayer(int playerNum, int direction);

private:
    QLabel *player1;               // Player 1 label
    QLabel *player2;               // Player 2 label
    QLabel *endLabel;              // Label to display the winner
    PlayerInputThread *player1Thread; // Thread for player 1 input
    PlayerInputThread *player2Thread; // Thread for player 2 input

    QMap<int, bool> keyState;     // Map to store the state of pressed keys

    // Function to check if a player is out of bounds
    void checkBoundary();

    // Function to check if a player has won
    void checkWinCondition();
};

#endif // RACINGGAME_H
