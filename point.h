#ifndef POINT_H
#define POINT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Point : public QGraphicsItem
{
public:
    Point();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawPoints(QPainter *painter);
    void setPoints(QVector<QPoint> points);
    void removePoint(QPoint p);

    void changeGeometry() { prepareGeometryChange(); }

    void generatePoints();

    int ballx,bally;
    int ballw,ballh;
    QPixmap ballpix;
    QRectF rec;
    QVector<QPoint> points;

};

#endif // POINT_H
