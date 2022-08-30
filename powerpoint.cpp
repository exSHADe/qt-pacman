#include "powerpoint.h"

PowerPoint::PowerPoint()
{
    ppx=0;
    ppy=0;
    ppw=5;
    pph=5;

    generatePowers();
}

QRectF PowerPoint::boundingRect() const
{
    return QRect(0, 0, 450, 550);
}

void PowerPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i=0;i<points.size();i++){
        painter->drawPixmap(points[i].x()-5, points[i].y()-5, ppMap);
    }
}

void PowerPoint::setPoints(QVector<QPoint> points)
{
    this->points.clear();
    this->points=points;
}

void PowerPoint::drawPower(QPainter *painter)
{
    for(int i=0;i<points.size();i++){
        painter->drawPixmap(points[i].x()-5, points[i].y()-5, ppMap);
    }
}

void PowerPoint::generatePowers()
{
    QRect bounds = QRect(0, 0, 10, 10);
    QPainter painter;


    ppMap = QPixmap(bounds.size());
    ppMap.fill(Qt::transparent);
    painter.begin(&ppMap);

    QPen pen=QPen(Qt::yellow);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);
    painter.setBrush(Qt::red);
    painter.drawEllipse(0, 0, 10, 10);
}
