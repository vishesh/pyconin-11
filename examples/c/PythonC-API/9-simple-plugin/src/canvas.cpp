#include "canvas.h"

#include <QPainter>
#include <QDebug>

Canvas *Canvas::m_canvas = 0;

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{

}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::black);

    foreach(QPoint point, m_points) {
        painter.drawPoint(point.x(), point.y());
    }
}

int Canvas::maxHeight() const
{
    return this->height();
}

int Canvas::maxWidth() const
{
    return this->width();
}

bool Canvas::setPixel(int x, int y, bool set)
{
    if ( x > maxWidth() && y > maxHeight() ) {
        return false;
    }

    for (QList<QPoint>::Iterator it = m_points.begin();
                            it != m_points.end(); it++) {
        if ( (*it).x() == x && (*it).y() == y ) {
            if (set) {
                return true;
            }
            else {
                m_points.erase(it);
                return true;
            }
        }
    }

    if (set) {
        QPoint point(x, y);
        m_points.append(point);
    }

    return true;
}

bool Canvas::pixel(int x, int y) const
{
    foreach (QPoint point, m_points) {
        if (point.x() == x && point.y() == y)
            return true;
    }
    return false;
}


