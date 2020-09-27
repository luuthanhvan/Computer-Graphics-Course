#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QPoint>

class graphics : public QWidget {
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    int mode = 0;
    int rosette = 0;
    int random(int n);
    QPoint randomPoint(QPoint *p);

    QPoint translation(QPoint p, int px, int py);
    QPoint rotation(QPoint p, QPoint c, int delta);
    QPoint scale(QPoint p, QPoint c, int sx, int sy);
    QPoint symmetryX(QPoint p);
    QPoint symmetryY(QPoint p);

    void testTranslation(QPainter &painter);
    void testRotation(QPainter &painter);
    void testScale(QPainter &painter);
    void testSymmetryX(QPainter &painter);
    void testSymmetryY(QPainter &painter);

    void drawThousandsOfStars(QPainter &painter); // mode = 1
    void drawPentagon(QPainter &painter); // mode = 2
    void drawFlower(QPainter &painter); // mode = 3
    void drawTaijitu(QPainter &painter); // mode = 4
    void drawRosette(QPainter &painter, int n); // rosette = 5 <=> n = 5 ...
    void drawNationalFlag(QPainter &painter); // mode = 5
    void drawStar(QPainter &painter, const QColor &color);
    void drawHouse(QPainter &painter, QPoint p, int w, int h);
    void drawReverseHouse(QPainter &painter);
    void drawVillage(QPainter &painter); // mode = 6
    void drawCircle(QPainter &painter); // mode = 7
    void drawTaijituWithColor(QPainter &painter); // mode = 8
    void drawSierpinskiGasket(QPainter &painter); // mode = 9
    void drawGingerbreadMan(QPainter &painter); // mode = 10
};

#endif // GRAPHICS_H
