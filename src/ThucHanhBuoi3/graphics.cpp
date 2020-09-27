#include "graphics.h"
#include <math.h>
#include <QPainter>
#include <QPointF>
#include <QColor>

graphics::graphics(QWidget *parent) : QWidget(parent){}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
//    testMoveFunc(painter);
    if(mode == 1)
        hookshaped(painter);
    if(mode == 2)
        rectangle(painter);
    if(mode == 3)
        rectangle(painter, 45);
    if(mode == 4)
        square(painter);
    if(mode == 5)
        triangle(painter);
    if(mode == 6)
        polyspirals(painter, 89.5, 4);
    if(mode == 7)
        polyspirals(painter, -89.5, 4);
    if(mode == 8)
        polyspirals(painter, -60, 1);
    if(mode == 9)
        polyspirals(painter, 144, 4);
    if(mode == 10)
        polyspirals(painter, -170, 4);
    if(mode == 11)
        drawPolygons(painter, 3, (width()/2)-100, (height()/2)+50, 200);
    if(mode == 12)
        drawPolygons(painter, 4, (width()/2)-100, (height()/2)+50, 200);
    if(mode == 13)
        drawPolygons(painter, 5, (width()/2)-100, (height()/2)+100, 200);
    if(mode == 14)
        drawPolygons(painter, 6, (width()/2)-100, (height()/2)+150, 200);
    if(mode == 15)
        drawPolygons(painter, 12, (width()/2)-50, (height()/2)+150, 100);
    if(mode == 16)
        drawPolygons(painter, 18, (width()/2)-50, (height()/2)+280, 100);
    if(mode == 17)
        drawPolygons(painter, 40, (width()/2), (height()/2)+230, 40);
    if(mode == 18)
        rosette(painter, 5, 200, (width()/2)-100, (height()/2)+100);
    if(mode == 19)
        rosette(painter, 12, 100, (width()/2)-50, (height()/2)+150);
    if(mode == 20)
        rosette(painter, 20, 50, width()/2, (height()/2)+150);
    if(mode == 21)
        drawSky(painter);
//    drawSnowflakes(painter);
}

QPointF graphics::move(QPointF p, double dist, int dir){
    QPointF pnew;
    pnew.setX(p.x() + dist*cos(M_PI*dir/180));
    pnew.setY(p.y() + dist*sin(M_PI*dir/180));
    return pnew;
}

void graphics::testMoveFunc(QPainter &painter){
    painter.drawLine(0,0,200,0);

    QPointF a(100,100), b, c, d, e, f;

    b.setX(move(a, 100, 0).x());
    b.setY(move(a, 100, 0).y());
    painter.setPen(Qt::blue);
    painter.drawLine(a.x(), a.y(), b.x(), b.y());

    c.setX(move(a, 100, -45).x());
    c.setY(move(a, 100, -45).y());
    painter.setPen(Qt::red);
    painter.drawLine(a.x(), a.y(), c.x(), c.y());

    d.setX(move(a, 100, 45).x());
    d.setY(move(a, 100, 45).y());
    painter.drawLine(a.x(), a.y(), d.x(), d.y());

    e.setX(move(a, 100, -90).x());
    e.setY(move(a, 100, -90).y());
    painter.setPen(Qt::green);
    painter.drawLine(a.x(), a.y(), e.x(), e.y());

    f.setX(move(a, 100, 90).x());
    f.setY(move(a, 100, 90).y());
    painter.setPen(Qt::yellow);
    painter.drawLine(a.x(), a.y(), f.x(), f.y());
}

void graphics::hookshaped(QPainter &painter){
    p.setX(100);
    p.setY(100);
    QPointF p1, p2, p3;

    int dis = 50; // distance
    int dir = 0; // direct

    p1.setX(move(p, dis, dir).x());
    p1.setY(move(p, dis, dir).y());
    painter.setPen(Qt::blue);
    painter.drawLine(p.x(), p.y(), p1.x(), p1.y());

    p2.setX(move(p1, dis, dir+90).x());
    p2.setY(move(p1, dis, dir+90).y());
    painter.drawLine(p1.x(), p1.y(), p2.x(), p2.y());

    p3.setX(move(p2, dis*3, dir+180).x());
    p3.setY(move(p2, dis*3, dir+180).y());
    painter.drawLine(p2.x(), p2.y(), p3.x(), p3.y());
}

void graphics::rectangle(QPainter &painter){
    p.setX(100);
    p.setY(200);

    int dis = 50; // distance
    int dir = 0; // direct
    QPoint startPoint;
    painter.setPen(Qt::blue);

    for(int i = 0; i < 4; i++){
        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis*3, dir);
        painter.drawLine(startPoint, p);
        dir += -90;

        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis, dir);
        painter.drawLine(startPoint, p);
        dir += -90;

        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis, dir);
        painter.drawLine(startPoint, p);
        dir += -90;
    }
}

void graphics::rectangle(QPainter &painter, int angle){
    p.setX(100);
    p.setY(200);

    int dis = 50; // distance
    int dir = angle; // direct
    QPoint startPoint;
    painter.setPen(Qt::blue);

    for(int i = 0; i < 4; i++){
        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis*3, dir);
        painter.drawLine(startPoint, p);
        dir += -90;

        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis, dir);
        painter.drawLine(startPoint, p);
        dir += -90;

        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis, dir);
        painter.drawLine(startPoint, p);
        dir += -90;
    }
}

void graphics::square(QPainter &painter){
    p.setX(300);
    p.setY(300);

    int dis = 50; // distance
    int dir = 0; // direct
    QPoint startPoint;
    painter.setPen(Qt::blue);

    for(int i = 0; i <= 4; i++){
        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis*i, dir);
        painter.drawLine(startPoint, p);
        dir += -90;

        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis*i, dir);
        painter.drawLine(startPoint, p);
        dir += -90;

        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis*i, dir);
        painter.drawLine(startPoint, p);
        dir += -90;

        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis*i, dir);
        painter.drawLine(startPoint, p);
        dir += -90;
    }
}

void graphics::triangle(QPainter &painter){
    p.setX(200);
    p.setY(300);

    int dis = 100; // distance
    int dir = 0; // direct
    QPoint startPoint;
    painter.setPen(Qt::blue);

    for(int i = 0; i < 4; i++){
        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis*2, dir);
        painter.drawLine(startPoint, p);
        dir += -120;
    }

    startPoint.setX(p.x());
    startPoint.setY(p.y());
    p = move(p, dis, dir);
    painter.drawLine(startPoint, p);
    dir += -120;

    for(int i = 0; i < 4; i++){
        startPoint.setX(p.x());
        startPoint.setY(p.y());
        p = move(p, dis , dir);
        painter.drawLine(startPoint, p);
        dir += 120;
    }
}

void graphics::polyspirals(QPainter &painter, float angle, int incr){
    int w = width();
    int h = height();
    QPointF middle(w/2, h/2), p, pnew;
    painter.setPen(Qt::blue);

    float dir = 0.0;
    int dist = incr;

    p.setX(middle.x());
    p.setY(middle.y());

    for(int i = 0; i < 150; i++){
        pnew = move(p, dist, dir);
        painter.drawLine(pnew, p);
        dir += angle;
        dist += incr;
        p.setX(pnew.x());
        p.setY(pnew.y());
    }
}

void graphics::drawPolygons(QPainter &painter, int nbEdges, int x, int y, int dist){
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    painter.setPen(pen);

    QPointF p, pnew;
    QPolygon polygon;

    p.setX(x);
    p.setY(y);

    for(int i = nbEdges; i > 0; i--){
        pnew = move(p, dist, i*(360/nbEdges));
        painter.drawLine(pnew, p);
        p.setX(pnew.x());
        p.setY(pnew.y());
        polygon << QPoint(pnew.x(), pnew.y());
    }
}

void graphics::rosette(QPainter &painter, int nbEdges, int dist, int x, int y){
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    painter.setPen(pen);

    QPointF p, pnew;
    QPolygon polygon;

    p.setX(x);
    p.setY(y);

    for(int i = nbEdges; i > 0; i--){
        pnew = move(p, dist, i*(360/nbEdges));
        painter.drawLine(pnew, p);
        p.setX(pnew.x());
        p.setY(pnew.y());
        polygon << QPoint(pnew.x(), pnew.y());
    }

    for(int i = 0; i < nbEdges; i++){
        for(int j = 0; j < nbEdges; j++){
            painter.drawLine(polygon.value(i), polygon.value(j));
        }
    }
}

void graphics::drawStar(QPainter &painter, int x, int y, int dist, const char* color){
    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(color));
    painter.setPen(pen);

    QPointF p, pnew;
    QPolygon polygon;

    p.setX(x+dist/2);
    p.setY(y+dist/2);
    polygon << QPoint(p.x(), p.y());

    for(int i = 1; i <= 4; i++){
        pnew = move(p, dist, -i*(360/5));
        p.setX(pnew.x());
        p.setY(pnew.y());
        polygon << QPoint(pnew.x(), pnew.y());
    }

    painter.drawLine(polygon.value(0), polygon.value(2));
    painter.drawLine(polygon.value(0), polygon.value(3));
    painter.drawLine(polygon.value(1), polygon.value(3));
    painter.drawLine(polygon.value(1), polygon.value(4));
    painter.drawLine(polygon.value(2), polygon.value(4));
}

void graphics::drawStarHexagon(QPainter &painter, int x, int y, int distH, int distS){
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    painter.setPen(pen);

    QPointF p, pnew;
    QPolygon polygon;

    p.setX(x-(distH/2));
    p.setY(y+(distH+(distH/2)));

    for(int i = 10; i > 0; i--){
        pnew = move(p, distH, i*(360/10));
        drawStar(painter, pnew.x(), pnew.y(), distS, "#ff0000");
        p.setX(pnew.x());
        p.setY(pnew.y());
        polygon << QPoint(pnew.x(), pnew.y());
    }
}

void graphics::drawSky(QPainter &painter){
    drawStar(painter, width()/2, height()/2, 150, "#0000ff");
    drawStarHexagon(painter, width()/2, height()/2, 120, 20);
    drawStarHexagon(painter, width()/2, height()/2, 190, 40);
}

void graphics::drawSnowflakes(QPainter &painter){
    int L = 400;
    QPoint p1, p2;
    int x = width()/2;
    int y = height()/2;
    p1.setX(x);
    p1.setY(y);

    p2.setX(L*4/10);
    p2.setY(y);
    painter.drawLine(p1, p2);


}
