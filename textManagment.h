#ifndef TEXTMANAGMENT_H
#define TEXTMANAGMENT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class TextManagment : public QGraphicsItem
{
public:
    TextManagment();
     QRectF boundingRect() const;
     void setGameOver(bool ending);
      void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
      bool ending,playing;
      int tx,ty,tw,th,score;
};

#endif // TEXTMANAGMENT_H
