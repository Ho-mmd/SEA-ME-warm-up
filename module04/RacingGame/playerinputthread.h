// PlayerInputThread.h
class PlayerInputThread : public QThread {
    Q_OBJECT
public:
    PlayerInputThread(int playerNum);
    void run() override;

signals:
    void movePlayer(int playerNum, int direction);

private:
    int playerNum;
};
