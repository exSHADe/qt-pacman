#include "textManagment.h"

TextManagment::TextManagment()
{
    ending=false;
    tw=350;
    th=50;
    tx=450/2-tw/2;
    ty=480/2-th/2;
    score=0;
    playing=false;
}

QRectF TextManagment::boundingRect() const
{
    return QRect(tx, ty, tw, th);
}

void TextManagment::setGameOver(bool over)
{
    this->ending=over;
}

void TextManagment::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::white);
    painter->setPen(pen);
    QFont font=painter->font() ;



    QBrush brush(Qt::red);
    painter->setBrush(brush);
    if(!playing){
        font.setPointSize ( 18 );
         painter->setFont(font);
        if(ending){

             painter->drawText( tx+120,ty-70, "GAME OVER." );
             painter->drawText( tx+70,ty-50, "PRESS ENTER TO PLAY." );
            painter->drawText( boundingRect(),Qt::AlignCenter, "SCORE : "+QString::number(score) );
            // painter->drawText( x,y+20, "PRESS ENTER TO PLAY." );

        }else{
            painter->drawText( boundingRect(),Qt::AlignCenter, "PRESS SPACE TO START" );
        }
    }else{
        font.setPointSize ( 13 );
        painter->setFont(font);
         painter->drawText( 50,15, "SCORE : "+QString::number(score));
    }

}
