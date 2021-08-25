#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLabel>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QLineEdit>

class Client : public QDialog {
    Q_OBJECT
private:
    QLabel *label;
    QLineEdit* textBox;
    QDialogButtonBox *buttons;
    QGridLayout *grid;
    QString serverIP;
    QTcpSocket *clientSocket;

    bool isConnected;
    void createUI();

public:
    void sendDataSlot(QString);
    void showUI();
    explicit Client(QDialog *parent = nullptr);
    ~Client();

signals:
    void changeID(int);
    void colorDecided(int, int);
    void sendMessage(QString);
    void onChangePlayer();
    void changeChessNULL(int, int);
    void changeChess(int, int, int, int, int);
    void timeRemainDecided(int);
    void playerDecided(int);
    void start();
    void firstPlayer(int);
    void changeColor(int, int);

public slots:
    void setIP(QString);

private slots:
    void onConnection();
    void onDisconnection();
    void onReadyRead();

};

#endif // CLIENT_H
