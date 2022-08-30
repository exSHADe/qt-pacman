#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

#include "pacman.h"
#include "map.h"
#include "point.h"
#include "ghost.h"
#include "powerpoint.h"
#include "textManagment.h"

namespace Ui {
class window;
}

class Window : public QDialog
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);

    void playerMove();

    void ghostsmove();
    void ghostsmove1();
    void ghostsmove2();
    void ghostsmove3();


    void rectGhostMove();
    void rectGhostMove1();
    void rectGhostMove2();
    void rectGhostMove3();

    void checklost();
    void delay();
    void startGame();
    void endGame();


    Pacman *player;
    Ghost *ghost;
    Ghost *ghost1;
    Ghost *ghost2;
    Ghost *ghost3;


    Map *map;
    Point *point;
    PowerPoint *powerPoint;
    TextManagment *text;

    int playerX,playerY,direction,nextdirection;

    int gosx,gosy,ghostdir,nextghostdir;
    int gosx1,gosy1,ghostdir1,nextghostdir1;
    int gosx2,gosy2,ghostdir2,nextghostdir2;
    int gosx3,gosy3,ghostdir3,nextghostdir3;

    bool move,ghostmoving,ghostmoving1,ghostmoving2,ghostmoving3;
    bool scareState,scareState1,scareState2,scareState3;

    int score,state3,state2,state1,state;

    bool start,delayb;
    bool ghoststart,ghoststart1,ghoststart2,ghoststart3;
    bool playing;

    QVector<QPoint> points;
    QVector<QPoint> powerPoints;

    ~Window();

public slots:
    void updater();
    void ghostupdater();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::window *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *ghoststimer;
};

#endif // WINDOW_H
