#ifndef POWERPOINT_H
#define POWERPOINT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class PowerPoint : public QGraphicsItem
{
public:
    PowerPoint();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPoints(QVector<QPoint> points);
    void drawPower(QPainter *painter);
    void removePower(QPoint p);

    void generatePowers();
    void changeGeometry() { prepareGeometryChange(); }

    int ppx,ppy;
    int ppw,pph;
    QVector<QPoint> points;
    QPixmap ppMap;
};

#endif // POWERPOINT_H
