#ifndef MAP_H
#define MAP_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QVector>
#include "point.h"
#include "powerpoint.h"
class Map : public QGraphicsItem
{

public:
    Map();
    Point *point;
    PowerPoint *powerPoint;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance();
    void generatePoints();
    void AddPathPoints(int, int, int, int);
    bool moveChance(QPoint);
    void fillPlayerPoints(int pacx,int pacy);
    void setPoints(QVector<QPoint> points);
    void setPowerPoints(QVector<QPoint> points);

    void changeGeometry() { prepareGeometryChange(); }

    QVector<QPoint> getPoints();
    QVector<QPoint> getPowerPoints();
    QPixmap mapSheet;
    QVector<QPoint> playerPoints,points;
    QVector<QPoint> powerPoints;
};

#endif // MAP_H
