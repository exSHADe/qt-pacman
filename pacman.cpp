#include "pacman.h"
#include <QMatrix>

Pacman::Pacman()
{
    animestate=0;

    x=410/2;
    y=360;
    direction=4;
    right1.load(":/images/pacclose.png");
    right2.load(":/images/pacopen1.png");
    right3.load(":/images/pacopen2.png");
    right4.load(":/images/pacopen3.png");

    up1.load(":/images/paccloseu.png");
    up2.load(":/images/pacopen1u.png");
    up3.load(":/images/pacopen2u.png");
    up4.load(":/images/pacopen3u.png");

    down1.load(":/images/pacclosed.png");
    down2.load(":/images/pacopen1d.png");
    down3.load(":/images/pacopen2d.png");
    down4.load(":/images/pacopen3d.png");

    left1.load(":/images/pacclosel.png");
    left2.load(":/images/pacopen1l.png");
    left3.load(":/images/pacopen2l.png");
    left4.load(":/images/pacopen3l.png");
}
QRectF Pacman::boundingRect() const
{
    return QRect(x-15, y-15, 20, 20);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawRect(pacx-15,pacy-15,30,30);
    //painter->setOpacity(0.5);
//    QMatrix matrix;
//         matrix.translate(0, 0);
//        // matrix.rotate(5);
//         matrix.scale(0.1, 1.0);
//         painter->setMatrix(matrix);

    switch(direction){
        case 1:
            if(animestate<2){
                painter->drawPixmap(x-15,y-15,30,30,left1);
            }else if(animestate<4){
                painter->drawPixmap(x-15,y-15,30,30,left2);
            }else if(animestate<6){
                painter->drawPixmap(x-15,y-15,30,30,left3);
            }else if(animestate<8){
                painter->drawPixmap(x-15,y-15,30,30,left4);
            }
            break;
        case 4:
            if(animestate<2){
                painter->drawPixmap(x-15,y-15,30,30,right1);
            }else if(animestate<4){
                painter->drawPixmap(x-15,y-15,30,30,right2);
            }else if(animestate<6){
                painter->drawPixmap(x-15,y-15,30,30,right3);
            }else if(animestate<8){
                painter->drawPixmap(x-15,y-15,30,30,right4);
            }
            break;
        case 3:
            if(animestate<2){
                painter->drawPixmap(x-15,y-15,30,30,down1);
            }else if(animestate<4){
                painter->drawPixmap(x-15,y-15,30,30,down2);
            }else if(animestate<6){
                painter->drawPixmap(x-15,y-15,30,30,down3);
            }else if(animestate<8){
                painter->drawPixmap(x-15,y-15,30,30,down4);
            }
            break;
        case 2:
            if(animestate<2){
                painter->drawPixmap(x-15,y-15,30,30,up1);
            }else if(animestate<4){
                painter->drawPixmap(x-15,y-15,30,30,up2);
            }else if(animestate<6){
                painter->drawPixmap(x-15,y-15,30,30,up3);
            }else if(animestate<8){
                painter->drawPixmap(x-15,y-15,30,30,up4);
            }
            break;
    }

}

void Pacman::advance()
{
    if(animestate>6){
        animestate=0;
    }else{
        animestate++;
    }
}

void Pacman::setX(int X)
{
    x=X;
}

void Pacman::setY(int Y)
{
    y=Y;
}

void Pacman::setDirection(int dir)
{
    direction=dir;
}




