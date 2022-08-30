#include "window.h"
#include "ui_window.h"
#include <QThread>

Window::Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window)
{
    score=0;
    gosx=450/2;
    gosy=480/2;
    gosx1=450/2;
    gosy1=480/2;
    gosx2=450/2;
    gosy2=480/2;
    gosx3=450/2;
    gosy3=480/2;
    playerX=410/2;
    playerY=360;
    ghostmoving=false;
    ghostmoving1=false;
    ghostmoving2=false;
    ghostmoving3=false;
    scareState=false;
    scareState1=false;
    scareState2=false;
    scareState3=false;
    start=false;
    direction=0;
    move=false;
    delayb=false;
    playing=false;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);



    scene->setSceneRect(0,0,640,480);
    ui->graphicsView->setSceneRect(scene->sceneRect());
    player=new Pacman;
    playerX=410/2;
    playerY=410;


    text=new TextManagment;
    text->ending=false;
    scene->addItem(text);
    text->setZValue(7);




}
void Window::startGame()
{
    gosx=450/2;
    gosy=480/2;
    gosx1=450/2;
    gosy1=480/2;
    gosx2=450/2;
    gosy2=480/2;
    gosx3=450/2;
    gosy3=480/2;
    playerX=410/2;
    playerY=360;
    map=new Map;
    ghost=new Ghost;
    ghost1=new Ghost;
    ghost2=new Ghost;
    ghost3=new Ghost;

    ghost1->setColor("orange");
    ghost2->setColor("red");
    ghost3->setColor("blue");
    points=map->getPoints();
    powerPoints=map->getPowerPoints();
    //Ball *ball[1000];

    //QVector<Ball *> balls(ballpoints.size());
//    balls.resize(ballpoints.size());


    point=new Point;
    powerPoint=new PowerPoint;
    point->setPoints(points);
    scene->removeItem(text);

    powerPoint->setPoints(powerPoints);
    scene->addItem(map);
    scene->addItem(player);
    scene->addItem(ghost);
    scene->addItem(ghost1);
    scene->addItem(ghost2);
    scene->addItem(ghost3);
    scene->addItem(text);
    //scene->removeItem(text);
    text->playing=true;
    ghostmoving=false;
    ghostmoving1=false;
    ghostmoving2=false;
    ghostmoving3=false;
    direction=0;
    move=false;
    ghoststart=false;
    ghoststart1=false;
    ghoststart2=false;
    ghoststart3=false;

//    ghost->setZValue(6);
//    ghost1->setZValue(5);
//    ghost2->setZValue(4);
//    ghost3->setZValue(3);
//    pacman->setZValue(2);
//    pac_map->setZValue(1);

    state=0;
    state1=0;
    state2=0;
    state3=0;
   timer = new QTimer(this);
   ghoststimer=new QTimer(this);
   connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
   connect(ghoststimer, SIGNAL(timeout()), this,SLOT(ghostupdater()));
   this->show();
   scene->update();
   this->update();
   delayb=true;


       timer->start(25);
       ghoststimer->start(40);
       this->setFocus();





}
void Window::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(3);
    while( QTime::currentTime() < dieTime ){}
    delayb=false;
    //QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void Window::endGame()
{
    text->ending=true;
    text->playing=false;
    scene->removeItem(map);
    scene->removeItem(player);
    scene->removeItem(ghost);
    scene->removeItem(ghost1);
    scene->removeItem(ghost2);
    scene->removeItem(ghost3);
    score=0;
    playing=false;
    scene->update();
}



void Window::playerMove()
{
    QPoint p;
    if(nextdirection!=direction){
        switch(nextdirection)
        {
            case 1:
            p.setX(playerX-5);
            p.setY(playerY);

            if(map->moveChance(p)){
                direction=nextdirection;
                nextdirection=0;

            }
            break;

            case 4:
            p.setX(playerX+5);
            p.setY(playerY);
            if(map->moveChance(p)){
                direction=nextdirection;
                nextdirection=0;

            }
            break;
            case 3:
            p.setX(playerX);
            p.setY(playerY+5);
            if(map->moveChance(p)){
                direction=nextdirection;
                nextdirection=0;

            }
            break;

            case 2:
            p.setX(playerX);
            p.setY(playerY-5);
            if(map->moveChance(p)){
                direction=nextdirection;
                nextdirection=0;

            }
            break;
        }

    }
        switch(direction)
        {
            case 1:
            p.setX(playerX-5);
            p.setY(playerY);
            player->setDirection(direction);

            if(map->moveChance(p)){
                playerX-=5;


                move=true;

            }else{
                move=false;
            }

                break;

            case 4:
            player->setDirection(direction);
            p.setX(playerX+5);
            p.setY(playerY);
            if(map->moveChance(p)){
                playerX+=5;

                move=true;

            }else{
                move=false;
            }

                break;
            case 3:
            player->setDirection(direction);
            p.setX(playerX);
            p.setY(playerY+5);
            if(map->moveChance(p)){
                playerY+=5;
                move=true;

            }else{
                move=false;
            }

                break;
            case 2:
            player->setDirection(direction);
            p.setX(playerX);
            p.setY(playerY-5);
            if(map->moveChance(p)){
                playerY-=5;
                move=true;

            }else{
                move=false;
            }

                break;
        }


        if(playerX<=0){
            playerX=450;
            playerY=230;
        }else if(playerX>=450){
            playerX=0;
            playerY=230;
        }
    player->setX(playerX);
    player->setY(playerY);
//    pacman->setPos(pacx - 15, pacy - 15);


}

void Window::ghostsmove()
{
    QPoint p;
    //int ir=qrand()%ballpoints.size();
//    QVector<QPoint> points;








    if(!ghostmoving){
        ghostdir=(qrand()%4)+1;
    }else{
            //nextghostdir=(qrand()%4)+1;
        if(ghostdir==4 &&gosy<playerY || ghostdir==1 && gosy>playerY){
            if(ghostdir==1 && gosy>playerY){
                        nextghostdir=2;
            }else if(ghostdir==4 &&gosy<playerY){
                nextghostdir=3;
            }

        }else if(ghostdir==3 && gosx<playerX || ghostdir==2 && gosx>playerX){
            if(ghostdir==2 && gosx>playerX){
                        nextghostdir=1;
            }else if(ghostdir==3 && gosx<playerX){
                nextghostdir=4;
            }
        }

        }



    if(nextghostdir!=ghostdir){
        switch(nextghostdir)
        {
            case 1:
            p.setX(gosx-5);
            p.setY(gosy);

            if(map->moveChance(p)){
                ghostdir=nextghostdir;
                nextghostdir=0;

            }

                break;

            case 4:
            p.setX(gosx+5);
            p.setY(gosy);
            if(map->moveChance(p)){
                ghostdir=nextghostdir;
                nextghostdir=0;

            }

                break;
            case 3:
            p.setX(gosx);
            p.setY(gosy+5);
            if(map->moveChance(p)){
                ghostdir=nextghostdir;
                nextghostdir=0;

            }

                break;
            case 2:
            p.setX(gosx);
            p.setY(gosy-5);
            if(map->moveChance(p)){
                ghostdir=nextghostdir;
                nextghostdir=0;

            }

                break;
        }

    }
        switch(ghostdir)
        {
            case 1:
            p.setX(gosx-5);
            p.setY(gosy);
            ghost->setDirection(ghostdir);

            if(map->moveChance(p)){
                gosx-=5;


                ghostmoving=true;

            }else{
                ghostmoving=false;
            }

                break;

            case 4:
            ghost->setDirection(ghostdir);
            p.setX(gosx+5);
            p.setY(gosy);
            if(map->moveChance(p)){
                gosx+=5;

                ghostmoving=true;

            }else{
                ghostmoving=false;
            }

                break;
            case 3:
            ghost->setDirection(ghostdir);
            p.setX(gosx);
            p.setY(gosy+5);
            if(map->moveChance(p)){
                gosy+=5;
                ghostmoving=true;

            }else{
                ghostmoving=false;
            }

                break;
            case 2:
            ghost->setDirection(ghostdir);
            p.setX(gosx);
            p.setY(gosy-5);
            if(map->moveChance(p)){
                gosy-=5;
                ghostmoving=true;

            }else{
                ghostmoving=false;
            }

                break;
        }


        if(gosx<=0){
            gosx=450;
            gosy=230;
        }else if(gosx>=450){
            gosx=0;
            gosy=230;
        }
    ghost->setX(gosx);
    ghost->setY(gosy);

}
void Window::ghostsmove1()
{
    QPoint p;
    //int ir=qrand()%ballpoints.size();
//    QVector<QPoint> points;






        if(!ghostmoving1){
            ghostdir1=(qrand()%4)+1;
        }else{
                //nextghostdir=(qrand()%4)+1;
            if(ghostdir1==4 &&gosy1<playerY || ghostdir1==1 && gosy1>playerY){
                if(ghostdir1==1 && gosy>playerY){
                            nextghostdir1=2;
                }else if(ghostdir1==4 &&gosy1<playerY){
                    nextghostdir1=3;
                }

            }else if(ghostdir1==3 && gosx1<playerX || ghostdir1==2 && gosx1>playerX){
                if(ghostdir1==2 && gosx1>playerX){
                            nextghostdir1=1;
                }else if(ghostdir1==3 && gosx1<playerX){
                    nextghostdir1=4;
                }
            }

            }


    if(nextghostdir1!=ghostdir1){
        switch(nextghostdir1)
        {
            case 1:
            p.setX(gosx1-5);
            p.setY(gosy1);

            if(map->moveChance(p)){
                ghostdir1=nextghostdir1;
                nextghostdir1=0;

            }

                break;

            case 4:
            p.setX(gosx1+5);
            p.setY(gosy1);
            if(map->moveChance(p)){
                ghostdir1=nextghostdir1;
                nextghostdir1=0;

            }

                break;
            case 3:
            p.setX(gosx1);
            p.setY(gosy1+5);
            if(map->moveChance(p)){
                ghostdir1=nextghostdir1;
                nextghostdir1=0;

            }

                break;
            case 2:
            p.setX(gosx1);
            p.setY(gosy1-5);
            if(map->moveChance(p)){
                ghostdir1=nextghostdir1;
                nextghostdir1=0;

            }

                break;
        }

    }
        switch(ghostdir1)
        {
            case 1:
            p.setX(gosx1-5);
            p.setY(gosy1);
            ghost1->setDirection(ghostdir1);

            if(map->moveChance(p)){
                gosx1-=5;


                ghostmoving1=true;

            }else{
                ghostmoving1=false;
            }

                break;

            case 4:
            ghost1->setDirection(ghostdir1);
            p.setX(gosx1+5);
            p.setY(gosy1);
            if(map->moveChance(p)){
                gosx1+=5;

                ghostmoving1=true;

            }else{
                ghostmoving1=false;
            }

                break;
            case 3:
            ghost1->setDirection(ghostdir1);
            p.setX(gosx1);
            p.setY(gosy1+5);
            if(map->moveChance(p)){
                gosy1+=5;
                ghostmoving1=true;

            }else{
                ghostmoving1=false;
            }

                break;
            case 2:
            ghost1->setDirection(ghostdir1);
            p.setX(gosx1);
            p.setY(gosy1-5);
            if(map->moveChance(p)){
                gosy1-=5;
                ghostmoving1=true;

            }else{
                ghostmoving1=false;
            }

                break;
        }


        if(gosx1<=0){
            gosx1=450;
            gosy1=230;
        }else if(gosx1>=450){
            gosx1=0;
            gosy1=230;
        }
    ghost1->setX(gosx1);
    ghost1->setY(gosy1);

}

void Window::ghostsmove2()
{
    QPoint p;
    //int ir=qrand()%ballpoints.size();
//    QVector<QPoint> points;





        if(!ghostmoving2){
            ghostdir2=(qrand()%4)+1;
        }else{
                //nextghostdir=(qrand()%4)+1;
            if(ghostdir2==4 &&gosy2<playerY || ghostdir2==1 && gosy2>playerY){
                if(ghostdir2==1 && gosy2>playerY){
                            nextghostdir2=2;
                }else if(ghostdir2==4 &&gosy2<playerY){
                    nextghostdir2=3;
                }

            }else if(ghostdir2==3 && gosx2<playerX || ghostdir2==2 && gosx2>playerX){
                if(ghostdir2==2 && gosx2>playerX){
                            nextghostdir2=1;
                }else if(ghostdir2==3 && gosx2<playerX){
                    nextghostdir2=4;
                }
            }

            }


    if(nextghostdir2!=ghostdir2){
        switch(nextghostdir2)
        {
            case 1:
            p.setX(gosx2-5);
            p.setY(gosy2);

            if(map->moveChance(p)){
                ghostdir2=nextghostdir2;
                nextghostdir2=0;

            }

                break;

            case 4:
            p.setX(gosx2+5);
            p.setY(gosy2);
            if(map->moveChance(p)){
                ghostdir2=nextghostdir2;
                nextghostdir2=0;

            }

                break;
            case 3:
            p.setX(gosx2);
            p.setY(gosy2+5);
            if(map->moveChance(p)){
                ghostdir2=nextghostdir2;
                nextghostdir2=0;

            }

                break;
            case 2:
            p.setX(gosx2);
            p.setY(gosy2-5);
            if(map->moveChance(p)){
                ghostdir2=nextghostdir2;
                nextghostdir2=0;

            }

                break;
        }

    }
        switch(ghostdir2)
        {
            case 1:
            p.setX(gosx2-5);
            p.setY(gosy2);
            ghost2->setDirection(ghostdir2);

            if(map->moveChance(p)){
                gosx2-=5;


                ghostmoving2=true;

            }else{
                ghostmoving2=false;
            }

                break;

            case 4:
            ghost2->setDirection(ghostdir2);
            p.setX(gosx2+5);
            p.setY(gosy2);
            if(map->moveChance(p)){
                gosx2+=5;

                ghostmoving2=true;

            }else{
                ghostmoving2=false;
            }

                break;
            case 3:
            ghost2->setDirection(ghostdir2);
            p.setX(gosx2);
            p.setY(gosy2+5);
            if(map->moveChance(p)){
                gosy2+=5;
                ghostmoving2=true;

            }else{
                ghostmoving2=false;
            }

                break;
            case 2:
            ghost2->setDirection(ghostdir2);
            p.setX(gosx2);
            p.setY(gosy2-5);
            if(map->moveChance(p)){
                gosy2-=5;
                ghostmoving2=true;

            }else{
                ghostmoving2=false;
            }

                break;
        }


        if(gosx2<=0){
            gosx2=450;
            gosy2=230;
        }else if(gosx2>=450){
            gosx2=0;
            gosy2=230;
        }
    ghost2->setX(gosx2);
    ghost2->setY(gosy2);

}

void Window::ghostsmove3()
{
    QPoint p;
    //int ir=qrand()%ballpoints.size();
//    QVector<QPoint> points;






        if(!ghostmoving3){
            ghostdir3=(qrand()%4)+1;
        }else{
                //nextghostdir=(qrand()%4)+1;
            if(ghostdir3==4 &&gosy3<playerY || ghostdir3==1 && gosy3>playerY){
                if(ghostdir3==1 && gosy3>playerY){
                            nextghostdir3=2;
                }else if(ghostdir3==4 &&gosy3<playerY){
                    nextghostdir3=3;
                }

            }else if(ghostdir3==3 && gosx3<playerX || ghostdir3==2 && gosx3>playerX){
                if(ghostdir3==2 && gosx3>playerX){
                            nextghostdir3=1;
                }else if(ghostdir3==3 && gosx3<playerX){
                    nextghostdir3=4;
                }
            }

            }


    if(nextghostdir3!=ghostdir3){
        switch(nextghostdir3)
        {
            case 1:
            p.setX(gosx3-5);
            p.setY(gosy3);

            if(map->moveChance(p)){
                ghostdir3=nextghostdir3;
                nextghostdir3=0;

            }

                break;

            case 4:
            p.setX(gosx3+5);
            p.setY(gosy3);
            if(map->moveChance(p)){
                ghostdir3=nextghostdir3;
                nextghostdir3=0;

            }

                break;
            case 3:
            p.setX(gosx3);
            p.setY(gosy3+5);
            if(map->moveChance(p)){
                ghostdir3=nextghostdir3;
                nextghostdir3=0;

            }

                break;
            case 2:
            p.setX(gosx3);
            p.setY(gosy3-5);
            if(map->moveChance(p)){
                ghostdir3=nextghostdir3;
                nextghostdir3=0;

            }

                break;
        }

    }
        switch(ghostdir3)
        {
            case 1:
            p.setX(gosx3-5);
            p.setY(gosy3);
            ghost3->setDirection(ghostdir3);

            if(map->moveChance(p)){
                gosx3-=5;


                ghostmoving3=true;

            }else{
                ghostmoving3=false;
            }

                break;

            case 4:
            ghost3->setDirection(ghostdir3);
            p.setX(gosx3+5);
            p.setY(gosy3);
            if(map->moveChance(p)){
                gosx3+=5;

                ghostmoving3=true;

            }else{
                ghostmoving3=false;
            }

                break;
            case 3:
            ghost3->setDirection(ghostdir3);
            p.setX(gosx3);
            p.setY(gosy3+5);
            if(map->moveChance(p)){
                gosy3+=5;
                ghostmoving3=true;

            }else{
                ghostmoving3=false;
            }

                break;
            case 2:
            ghost3->setDirection(ghostdir3);
            p.setX(gosx3);
            p.setY(gosy3-5);
            if(map->moveChance(p)){
                gosy3-=5;
                ghostmoving3=true;

            }else{
                ghostmoving3=false;
            }

                break;
        }


        if(gosx3<=0){
            gosx3=450;
            gosy3=230;
        }else if(gosx3>=450){
            gosx3=0;
            gosy3=230;
        }
    ghost3->setX(gosx3);
    ghost3->setY(gosy3);

}


void Window::rectGhostMove3()
{
    if(gosx3==450/2+40 || gosx3==450/2-40){
        if(ghostdir3==4){
            ghostdir3=1;
        }else{
            ghostdir3=4;
        }
    }
    if(ghostdir3==4){

        gosx3-=2;

    }else{

        gosx3+=2;
    }




    ghost3->setX(gosx3);
    ghost3->setY(gosy3);
}

void Window::rectGhostMove2()
{
    if(gosx2==450/2+40 || gosx2==450/2-40){
        if(ghostdir2==4){
            ghostdir2=1;
        }else{
            ghostdir2=4;
        }
    }
    if(ghostdir2==4){

        gosx2+=5;

    }else{

        gosx2-=5;
    }




    ghost2->setX(gosx2);
    ghost2->setY(gosy2);
}
void Window::rectGhostMove1()
{
    if(gosx1==450/2+40 || gosx1==450/2-40){
        if(ghostdir1==4){
            ghostdir1=1;
        }else{
            ghostdir1=4;
        }
    }
    if(ghostdir1==4){

        gosx1+=5;

    }else{

        gosx1-=5;
    }




    ghost1->setX(gosx1);
    ghost1->setY(gosy1);
}
void Window::rectGhostMove()
{
    if(gosx==450/2+40 || gosx==450/2-40){
        if(ghostdir==4){
            ghostdir=1;
        }else{
            ghostdir=4;
        }
    }
    if(ghostdir==4){

        gosx+=5;

    }else{

        gosx-=5;
    }




    ghost->setX(gosx);
    ghost->setY(gosy);
}

void Window::checklost()
{
    if(points.isEmpty()){
        timer->stop();
        ghoststimer->stop();
        endGame();
    }
    if(player->collidesWithItem(ghost) ||
            player->collidesWithItem(ghost1) ||
            player->collidesWithItem(ghost2) ||
            player->collidesWithItem(ghost3)){
        if(scareState){
            score+=100;
            if(player->collidesWithItem(ghost)){
                gosx=450/2;
                gosy=450/2;
                ghoststart=false;
            }
            if(player->collidesWithItem(ghost1)){
                gosx1=450/2;
                gosy1=450/2;
                ghoststart1=false;
            }
            if(player->collidesWithItem(ghost2)){
                gosx2=450/2;
                gosy2=450/2;
                ghoststart2=false;
            }
            if(player->collidesWithItem(ghost3)){
                gosx3=450/2;
                gosy3=450/2;
                ghoststart3=false;
            }

        }else{
            delay();
            timer->stop();
            ghoststimer->stop();
            endGame();

        }


    }




}



void Window::keyPressEvent(QKeyEvent *event)
{
   // if(isChanged){
        switch(event->key())
        {
            case Qt::Key_Left:

            if(!move){


                direction=1;

            }else{
               nextdirection=1;
            }

                break;
            case Qt::Key_Right:

            if(!move){


                direction=4;

            }else{

                nextdirection=4;
            }

                break;
            case Qt::Key_Down:
            if(!move){
                direction=3;
            }else{
               nextdirection=3;
            }



                break;
            case Qt::Key_Up:
            if(!move){
                direction=2;
            }else{
                nextdirection=2;
            }
                break;
        case Qt::Key_Space:
            if(!playing){
                startGame();
                playing=true;
            }else{
                endGame();
                startGame();
            }


            break;
            default:
                break;
                //QFrame::keyPressEvent(event);

        }
        // }


}

int scarestate=0;
int soundstate=0;
void Window::updater()
{
    checklost();
    playerMove();





    for(int i=0;i<points.size();i++){
        if(player->x==points[i].x() && player->y==points[i].y()){
            points.remove(i);
            score++;
            text->score=score;
            //ui->lcdScore->display(score);
            //chomp->play("sounds/pacman_chomp.wav");
            //if(soundstate==0){chomp->play("sounds/pacman_chomp.wav");soundstate++;}
            //else{soundstate++;if(soundstate==12){soundstate=0;}}


        }
    }
    for(int i=0;i<powerPoints.size();i++){
        if(player->x==powerPoints[i].x() && player->y==powerPoints[i].y()){
            powerPoints.remove(i);
            if(scareState){scarestate=0;}
            scareState=true;
            //chomp->play("sounds/pacman_extrapac.wav");

        }
    }
    if(scareState){
        ghost->scare=true;
        ghost1->scare=true;
        ghost2->scare=true;
        ghost3->scare=true;
        scarestate+=1;
        if(scarestate==1){ghoststimer->setInterval(65);}
        if(scarestate==100){
            ghost->whiteb=true;
            ghost1->whiteb=true;
            ghost2->whiteb=true;
            ghost3->whiteb=true;

        }
        if(scarestate==150){
            scareState=false; scarestate=0; ghoststimer->setInterval( 35);
            ghost->whiteb=false;
            ghost1->whiteb=false;
            ghost2->whiteb=false;
            ghost3->whiteb=false;
        }
    }else{
        ghost->scare=false;
        ghost1->scare=false;
        ghost2->scare=false;
        ghost3->scare=false;
    }
    point->setPoints(points);
    powerPoint->setPoints(powerPoints);
    map->setPoints(points);
    map->setPowerPoints(powerPoints);
    map->fillPlayerPoints(playerX,playerY);
    player->advance();
    ghost->advance();
    ghost1->advance();
    ghost2->advance();
    ghost3->advance();


//    if(pacman->collidesWithPath(path)){
//       // timer->stop();
//    }
    this->setFocus();
    scene->update(map->boundingRect());
    if(delayb){delay();}
}

void Window::ghostupdater()
{
    if(ghoststart || ghoststart1 || ghoststart2 || ghoststart3){
        if(ghoststart){ghostsmove();}
        if(ghoststart1){ghostsmove1();}
        if(ghoststart2){ghostsmove2();}
        if(ghoststart3){ghostsmove3();}
    }
    if(gosx3==450/2){
        state++;
    }
    if(state==3){
        start=true;
        state=0;
    }
    if(!start){
        rectGhostMove3();
        rectGhostMove2();
        rectGhostMove1();
        rectGhostMove();

    }else if(!ghoststart3 || !ghoststart2 || !ghoststart1 || !ghoststart){
        QPoint p,p1,p2,p3;
        if(!ghoststart3){
            gosy3-=5;
            ghost3->setX(gosx3);
            ghost3->setY(gosy3);
            p3.setX(gosx3);
            p3.setY(gosy3);
            if(map->playerPoints.contains(p3)){ghoststart3=true;}
        }

        if(!ghoststart2){
            gosy2-=5;
            ghost2->setX(gosx2);
            ghost2->setY(gosy2);
            p2.setX(gosx2);
            p2.setY(gosy2);
            if(map->playerPoints.contains(p2)){ghoststart2=true;}
        }
        if(!ghoststart1){
            gosy1-=5;
            ghost1->setX(gosx1);
            ghost1->setY(gosy1);
            p1.setX(gosx1);
            p1.setY(gosy1);
            if(map->playerPoints.contains(p1)){ghoststart1=true;}
        }
        if(!ghoststart){
            gosy-=5;
            ghost->setX(gosx);
            ghost->setY(gosy);
            p.setX(gosx);
            p.setY(gosy);
            if(map->playerPoints.contains(p)){ghoststart=true;}
        }

    }
    if(delayb){delay();}
}


Window::~Window()
{
    delete ui;
}

