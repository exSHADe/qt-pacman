#include "point.h"

Point::Point()
{
    ballx=0;
    bally=0;
    ballw=5;
    ballh=5;

    generatePoints();
}

QRectF Point::boundingRect() const
{
    return QRect(0, 0, 450, 550);
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i=0;i<points.size();i++){
        painter->drawPixmap( points[i].x(), points[i].y(), ballpix );
    }
}

void Point::drawPoints(QPainter *painter)
{
    for(int i=0;i<points.size();i++){
        painter->drawPixmap( points[i].x(), points[i].y(), ballpix );
    }
}

void Point::setPoints(QVector<QPoint> points)
{
    this->points.clear();
    this->points=points;
}

void Point::removePoint(QPoint p)
{

}

void Point::generatePoints()
{
    QRect bounds = QRect(0, 0, 3, 3);

    QPainter painter;

    ballpix = QPixmap(bounds.size());
    ballpix.fill(Qt::transparent);
    painter.begin(&ballpix);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(0, 0, 3, 3);

}


