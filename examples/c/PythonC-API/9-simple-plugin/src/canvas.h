#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPoint>
#include <QList>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    Canvas(QWidget *parent = 0);

    bool setPixel(int x, int y, bool set);
    bool pixel(int x, int y) const;

    int maxHeight() const;
    int maxWidth() const;

    static Canvas *instance() {
        if (m_canvas != 0) 
            return m_canvas;
        m_canvas = new Canvas;
        return m_canvas;
    }

protected:
    void paintEvent(QPaintEvent *event);

private:
    QList<QPoint> m_points;
    static Canvas *m_canvas;
};

#endif // CANVAS_H
