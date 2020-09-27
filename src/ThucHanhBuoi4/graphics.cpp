#include "graphics.h"
#include <QPainter>
#include <QBrush>
#include <QString>
#include <QPixmap>
#include <QPointF>
#include <QPolygon>
#include <QPoint>
#include <math.h>

// constructor
graphics::graphics(QWidget *parent):QWidget(parent){
    position = 0;
    timeID = startTimer(50);
    angle = 30;
}

void graphics::timerEvent(QTimerEvent *){
    position += 5;
    angle += 5;
    repaint();
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    // mode is equal zero for reseting to draw, mode is not equal zero for drawing shapes
    if(mode == 1)
        drawExample(painter);
    if(mode == 2)
        drawCar(painter);
    if(mode == 3)
        animationStarCircle(painter);
    if(mode == 4)
        drawSolarSystem(painter);
//    drawNightSky(painter);
}

void graphics::drawExample(QPainter &painter){
    int r = 100;
    painter.setBrush(QBrush("#b40000"));
    painter.drawRect(position, h/2, r, r); // move horizontal
    painter.drawRect(h/2, position, r, r); // move vertical
}

void graphics::drawCar(QPainter &painter){
    int r = 100;
    QString image = "../../images/car.png";
    painter.drawPixmap(position, h/2, 3*r, r, QPixmap(image));
}

QPointF graphics::rotation(QPointF p, QPointF c, int delta){
    QPointF pnew;
    double angle = delta*3.14/180; // convert to radian
    pnew.setX(c.x() + (p.x()-c.x())*cos(angle) - (p.y()-c.y())*sin(angle));
    pnew.setY(c.y() + (p.x()-c.x())*sin(angle) + (p.y()-c.y())*cos(angle));
    return pnew;
}

void graphics::animationCircle(QPainter &painter){
    int r = 10;
    int h = height()/2;
    int w = width()/2;
    pCenter.setX(w);
    pCenter.setY(h);

    pStart.setX(pCenter.x());
    pStart.setY(pCenter.y()-100);

    pNew = rotation(pStart, pCenter, angle);
    painter.setPen(Qt::blue);
    painter.drawEllipse(pCenter, r, r);
    painter.drawLine(pCenter, pNew);
    painter.drawEllipse(pNew, 2*r, 2*r);
}

void graphics::drawStar(QPainter &painter, QPointF pCenter, int r){
    QPointF p(pCenter.x(), pCenter.y()-r);
    QPolygon polygon;
    int angle = 72;
    polygon << QPoint(p.x(), p.y());
    for(int i = 1; i <= 4; i++){
        p = rotation(p, pCenter, angle);
        polygon << QPoint(p.x(), p.y());
    }
    painter.drawLine(polygon.value(0), polygon.value(2));
    painter.drawLine(polygon.value(0), polygon.value(3));
    painter.drawLine(polygon.value(1), polygon.value(3));
    painter.drawLine(polygon.value(1), polygon.value(4));
    painter.drawLine(polygon.value(2), polygon.value(4));
}

void graphics::animationStarCircle(QPainter &painter){
    int r = 10;
    int h = height()/2;
    int w = width()/2;
    pCenter.setX(w);
    pCenter.setY(h);

    pStart.setX(pCenter.x());
    pStart.setY(pCenter.y()-100);

    pNew = rotation(pStart, pCenter, angle);
    painter.setPen(Qt::blue);
    painter.drawEllipse(pCenter, r, r);
    painter.drawLine(pCenter, pNew);
    painter.drawEllipse(pNew, 2*r, 2*r);

    drawStar(painter, pCenter, r);
    drawStar(painter, pNew, 2*r);
}

void graphics::drawSolarSystem(QPainter &painter){
    int r = 100;
    int w = width(); // width of the device
    int h = height(); // height of the device

    int wSun = r; // width of the Sun
    int hSun = r; // height of the Sun
    int wEarth = r/2; // width of the Earth
    int hEarth = r/2; // height of the Earth
    int wMoon = r/4; // width of the Moon
    int hMoon = r/4; // height of the Moon

    QString sun = ("../../images/sun.png");
    QString earth = ("../../images/earth.png");
    QString moon = ("../../images/moon.png");

    pCenter.setX(w/2);
    pCenter.setY(h/2);

    int xSun = pCenter.x()- (wSun/2);
    int ySun = pCenter.y()- (hSun/2);

    painter.drawPixmap(xSun, ySun, wSun, hSun, QPixmap(sun));

    pStart.setX(pCenter.x()-wSun);
    pStart.setY(pCenter.y()-hSun);

    pNew = rotation(pStart, pCenter, angle/2);

    int xEarth = pNew.x() - (wEarth/2);
    int yEarth = pNew.y() - (hEarth/2);

    painter.drawPixmap(xEarth, yEarth, wEarth, hEarth, QPixmap(earth));

    pCenter.setX(pNew.x());
    pCenter.setY(pNew.y());

    pStart.setX(pCenter.x()-(wMoon*2));
    pStart.setY(pCenter.y()-(hMoon*2));

    pNew = rotation(pStart, pCenter, angle);

    int xMoon = pNew.x() - (wMoon/2);
    int yMoon = pNew.y() - (hMoon/2);

    painter.drawPixmap(xMoon, yMoon, wMoon, hMoon, QPixmap(moon));
}

int graphics::random(int num){
    return rand()%num;
}

void graphics::drawNightSky(QPainter &painter){
    int x = random(200);
    int y = random(200);
    QPointF point(x,y);
    int r = random(50);

    for(int i = 1; i <= 1000; i++){
        drawStar(painter, point, position+r);
    }
}
