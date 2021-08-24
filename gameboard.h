#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "chessboard.h"
#include "clickablelabel.h"
#include "gamelogic.h"
#include "infoboard.h"
#include <QMainWindow>

class Data;

class Gameboard: public QWidget {
    Q_OBJECT

private:
    Infoboard* infoboard;
    Chessboard* chessboard;
    ClickableLabel* chessLabel[5][12];
    void createUI();
    bool isGameStarted;

    QMap<int, QString> dict = {{1, "01"}, {2, "02"}, {3, "03"}, {4, "04"}, {5, "05"},
                               {6, "06"}, {7, "07"}, {8, "08"}, {9, "09"}, {10, "10"},
                               {11, "11"}, {12, "12"}};

public:
    Gameboard(QWidget *parent = nullptr);
    ~Gameboard();
    void render(int);
    void setChessboard(Chessboard*);

signals:
    void sendMoved(QString);

public slots:
    void onChessClicked(int, int);
    void show();
};

#endif // GAMEBOARD_H