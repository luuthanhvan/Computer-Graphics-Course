#include <cmath>
#include "graphics.h"
#include <QPainter>
#include <QPixmap>
#include <QRect>
#include <QPen>
#include <QPoint>
#include <QFont>
#include <QPainterPath>
#include <QString>

graphics::graphics(QWidget *parent): QWidget(parent){
    position = 0;
    posImage = 0;
    h = 0.0;
    m = 0.0;
    s = 0.0;
    size = 0;
    opacity = 0.0;
    timerId = startTimer(100);
}

void graphics::timerEvent(QTimerEvent *){
    position += 1;
    posImage += 1;
    size += 1;
    opacity += 0.1;
    if(opacity == 1.0)
        opacity = 0.0;
    if(size == 10)
        size = 0;
    if(posImage == 10)
        posImage = 0;
    s += 6; // 360/60
    m += 0.1; // 360/(60*2)
    h += 0.00167; // 360/(60*3)
    repaint();
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // mode is equal zero for reseting to draw, mode is not equal zero for drawing shapes
    if(mode == 1)
        drawMegaman(painter);
    if(mode == 2)
        drawWatch(painter);
    if(mode == 3)
        drawSkyNight(painter);
}

void graphics::drawMegaman(QPainter &painter){
    QPixmap spritesheet("../../images/Megaman.png"); // load image
    double wImage = spritesheet.width()/10; // width of small images
    double hImage = spritesheet.height(); // height of small images
    int r = 5;
    // tao mot cua so co toa do va kich thuoc phu hop voi tung anh nho
    QRect displayWindow(wImage*posImage, 0, wImage, hImage);
    // tao mot cua o hien thi tai vi tri position
    QRect pos(position*r, height()/2, wImage, hImage);
    painter.drawPixmap(pos, spritesheet, displayWindow);
}

QPoint graphics::rotation(QPoint p, QPoint c, int delta){
    QPoint pnew;
    double angle=delta*3.14/180; // convert to radians
    pnew.setX(c.x()+(p.x()-c.x())*cos(angle) - (p.y()-c.y())*sin(angle));
    pnew.setY(c.y()+(p.x()-c.x())*sin(angle) + (p.y()-c.y())*cos(angle));
    return pnew;
}

void graphics::drawWatch(QPainter &painter){
    QPen pen;
    int x = width()/2;
    int y = height()/2;
    int r = 600;

    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.setBrush(Qt::blue);

    // draw the border of the watch
    painter.drawRoundedRect(x-(r/2), y-(r/2), r, r, 100, 100);

    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.setBrush(Qt::white);

    // draw a circle
    painter.drawEllipse(x-(r/2), y-(r/2), r, r);

    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.setBrush(Qt::black);

    // draw numbers on the watch
    int size = 40;
    QPainterPath path;
    QFont font("Georgia", size);
    QString str;
    QPoint pCenter, pNew, p;

    pCenter.setX(x);
    pCenter.setY(y);

    p.setX(x-(size/2));
    p.setY(y+(size)-(r/2));

    str = QString::number(12);
    path.addText(p, font, str);
    painter.drawPath(path);

    for(int i = 1; i < 4; i++){
        pNew = rotation(p, pCenter, (360/12));
        str = QString::number(i);
        path.addText(pNew, font, str);
        painter.drawPath(path);
        p.setX(pNew.x());
        p.setY(pNew.y());
    }

    for(int i = 4; i < 7; i++){
        pNew = rotation(p, pCenter, (360/12));
        str = QString::number(i);
        path.addText(pNew, font, str);
        painter.drawPath(path);
        p.setX(pNew.x());
        p.setY(pNew.y()+(size/2));
    }

    p.setX(x-(size/2));
    p.setY(y+(r/2)-(size/2));

    for(int i = 7; i < 10; i++){
        pNew = rotation(p, pCenter, (360/12));
        str = QString::number(i);
        path.addText(pNew, font, str);
        painter.drawPath(path);
        p.setX(pNew.x());
        p.setY(pNew.y());
    }

    for(int i = 10; i < 12; i++){
        pNew = rotation(p, pCenter, (360/12));
        str = QString::number(i);
        path.addText(pNew, font, str);
        painter.drawPath(path);
        p.setX(pNew.x());
        p.setY(pNew.y()+(size/2));
    }

    QPoint p1, p2, p3;
    QPoint pStart1, pStart2, pStart3;

    // hour
    pStart1.setX(pCenter.x());
    pStart1.setY(pCenter.y()-180);
    p1 = rotation(pStart1, pCenter, h);
    pen.setColor(Qt::black);
    pen.setWidth(6);
    painter.setPen(pen);
    painter.drawLine(pCenter, p1);

    // minute
    pStart2.setX(pCenter.x());
    pStart2.setY(pCenter.y()-220);
    p2 = rotation(pStart2, pCenter, m);
    pen.setColor(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawLine(pCenter, p2);

    // second
    pStart3.setX(pCenter.x());
    pStart3.setY(pCenter.y()-240);
    p3 = rotation(pStart3, pCenter, s);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.drawLine(pCenter, p3);
}

void graphics::drawStar(QPainter &painter, int x, int y, int r, const QColor &color, double opacity){
    QPoint pCenter(x, y);
    QPoint p(pCenter.x(), pCenter.y()-r);
    QPolygon polygon;
    polygon << QPoint(p.x(), p.y());
    for(int i = 1; i <= 4; i++){
        p = rotation(p, pCenter, 72);
        polygon << QPoint(p.x(), p.y());
    }
    QPen pen;
    pen.setColor(QColor(color));
    painter.setPen(pen);
    painter.setOpacity(opacity);
    painter.drawLine(polygon.value(0), polygon.value(2));
    painter.drawLine(polygon.value(0), polygon.value(3));
    painter.drawLine(polygon.value(1), polygon.value(3));
    painter.drawLine(polygon.value(1), polygon.value(4));
    painter.drawLine(polygon.value(2), polygon.value(4));
}

int graphics::random(int num){
    return rand()%num;
}

void graphics::drawSkyNight(QPainter &painter){

    int w = width();
    int h = height();
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, w, h);

    for(int i = 1; i < 500; i++){
        drawStar(painter, random(w), random(h), size, QColor(random(255), random(255), random(255)), opacity);
    }
}
