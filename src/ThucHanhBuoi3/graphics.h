#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QPointF>

class graphics : public QWidget
{
    Q_OBJECT
public:
    graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

    QPointF p; // the begining of the turtle
    double direct = 0;
    int mode = 0;

    QPointF move(QPointF p, double dist, int dir); // point, distance, direct
    void testMoveFunc(QPainter &painter);
    void hookshaped(QPainter &painter); // mode = 1
    void rectangle(QPainter &painter); // mode = 2
    void rectangle(QPainter &painter, int angle); // mode = 3
    void square(QPainter &painter); // mode = 4
    void triangle(QPainter &painter); // mode = 5
    void polyspirals(QPainter &painter, float angle, int incr); // mode = 6, 7, 8, 9, 10, 11
    void drawPolygons(QPainter &painter, int nbEdges, int x, int y, int dist);
    void rosette(QPainter &painter, int nbEdges, int dist, int x, int y); // mode = 12, 13, 14, 15
    void drawStar(QPainter &painter, int x, int y, int dist, const char* color);
    void drawStarHexagon(QPainter &painter, int x, int y, int distH, int distS);
    void drawSky(QPainter &painter); // mode = 16
    void drawSnowflakes(QPainter &painter);
};

#endif // GRAPHICS_H
