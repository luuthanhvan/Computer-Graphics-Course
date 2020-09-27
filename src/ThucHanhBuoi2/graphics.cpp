#include <iostream>
#include "graphics.h"
#include <QPainter>
#include <QPoint>
#include <QPolygon>
#include <QPen>
#include <math.h>

using namespace std;

graphics::graphics(QWidget *parent) : QWidget(parent){}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
//    testTranslation(painter);
//    testRotation(painter);

        if(mode == 1)
            drawThousandsOfStars(painter);
        if(mode == 2)
            drawPentagon(painter);
        if(mode == 3)
            drawFlower(painter);
        if(mode == 4)
            drawTaijitu(painter);
        if(rosette == 5)
            drawRosette(painter, 5);
        if(rosette == 11)
            drawRosette(painter, 11);
        if(rosette == 20)
            drawRosette(painter, 20);
        if(mode == 5)
            drawNationalFlag(painter);
        if(mode == 6)
            drawVillage(painter);
        if(mode == 7)
            drawCircle(painter);
        if(mode == 8)
            drawTaijituWithColor(painter);
        if(mode == 9)
            drawSierpinskiGasket(painter);
        if(mode == 10)
            drawGingerbreadMan(painter);
}

QPoint graphics::translation(QPoint p, int px, int py){
    QPoint pnew;
    pnew.setX(p.x() + px);
    pnew.setY(p.y() + py);
    return pnew;
}

void graphics::testTranslation(QPainter &painter){
    QPoint p(0,0);
    int px = 10;
    int py = 10;
    int w = 100;
    int h = 100;
    QPoint pnew1 = translation(p, px, py);
    painter.drawRect(pnew1.x(), pnew1.y(), w, h);

    QPoint pnew2 = translation(pnew1, 3*px, 3*py);
    painter.setPen(Qt::red);
    painter.drawRect(pnew2.x(), pnew2.y(), w, h);

    painter.setPen(Qt::green);
    painter.drawLine(pnew1.x(), pnew1.y(), pnew2.x(), pnew2.y());
    painter.drawLine(pnew1.x()+w, pnew1.y(), pnew2.x()+w, pnew2.y());
    painter.drawLine(pnew1.x(), pnew1.y()+h, pnew2.x(), pnew2.y()+h);
    painter.drawLine(pnew1.x()+w, pnew1.y()+h, pnew2.x()+w, pnew2.y()+h);
}

/* Spin a point (p) around any point (c) with an angle (delta)
 * p <QPoint>: a point
 * c <QPoint>: center point
 * delta <int>: an angle
*/
QPoint graphics::rotation(QPoint p, QPoint c, int delta){
    QPoint pnew;
    double angle=delta*3.14/180; // convert to radians
    pnew.setX(c.x()+(p.x()-c.x())*cos(angle) - (p.y()-c.y())*sin(angle));
    pnew.setY(c.y()+(p.x()-c.x())*sin(angle) + (p.y()-c.y())*cos(angle));
    return pnew;
}

void graphics::testRotation(QPainter &painter){
    /*
    QPoint p(10,10);
    QPoint c(100,100);
    int delta = 45;
    painter.drawLine(p.x(), p.y(), c.x(), c.y());

    QPoint pnew = rotation(p, c, delta);
    painter.drawLine(pnew.x(), pnew.y(), c.x(), c.y());

    pnew = rotation(pnew, c, delta);
    painter.drawLine(pnew.x(), pnew.y(), c.x(), c.y());

    pnew = rotation(pnew, c, delta);
    painter.drawLine(pnew.x(), pnew.y(), c.x(), c.y());

    pnew = rotation(pnew, c, delta);
    painter.drawLine(pnew.x(), pnew.y(), c.x(), c.y());

    pnew = rotation(pnew, c, delta);
    painter.drawLine(pnew.x(), pnew.y(), c.x(), c.y());

    pnew = rotation(pnew, c, delta);
    painter.drawLine(pnew.x(), pnew.y(), c.x(), c.y());

    pnew = rotation(pnew, c, delta);
    painter.drawLine(pnew.x(), pnew.y(), c.x(), c.y()); */
    /*
    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::blue);
    painter.setPen(pen);
    painter.setBrush(Qt::yellow);*/

    /*
    QPoint c(100, 100);
    int r = 50;
    QPoint p(c.x(), c.y()-r);
//    cout << "p.x = " << p.x() << "\tp.y = " << p.y(); // p.x() = 100, p.y() = 50
    QPoint pnew = rotation(p, c, 360/6);
//    cout << "pnew.x = " << pnew.x() << "\tpnew.y = " << pnew.y(); // pnew.x = 147, pnew.y = 84
    painter.drawEllipse(pnew, r, r);

    pnew = rotation(p, c, 2*(360/6));
    painter.drawEllipse(pnew, r, r);

    pnew = rotation(p, c, 3*(360/6));
    painter.drawEllipse(pnew, r, r);

    pnew = rotation(p, c, 4*(360/6));
    painter.drawEllipse(pnew, r, r);

    pnew = rotation(p, c, 5*(360/6));
    painter.drawEllipse(pnew, r, r);

    pnew = rotation(p, c, 6*(360/6));
    painter.drawEllipse(pnew, r, r); */

    /*
    int dist = 50;
    QPoint c(100, 100);
    QPoint p(c.x(), c.y()-dist);

    QPolygon polygon;
    QPoint pnew = rotation(p, c, 360/8);
    polygon << QPoint(pnew.x(), pnew.y());

    pnew = rotation(p, c, 2*(360/8));
    polygon << QPoint(pnew.x(), pnew.y());

    pnew = rotation(p, c, 3*(360/8));
    polygon << QPoint(pnew.x(), pnew.y());

    pnew = rotation(p, c, 4*(360/8));
    polygon << QPoint(pnew.x(), pnew.y());

    pnew = rotation(p, c, 5*(360/8));
    polygon << QPoint(pnew.x(), pnew.y());

    pnew = rotation(p, c, 6*(360/8));
    polygon << QPoint(pnew.x(), pnew.y());

    pnew = rotation(p, c, 7*(360/8));
    polygon << QPoint(pnew.x(), pnew.y());

    pnew = rotation(p, c, 8*(360/8));
    polygon << QPoint(pnew.x(), pnew.y());

    painter.drawPolygon(polygon); */
}

QPoint graphics::scale(QPoint p, QPoint c, int sx, int sy){
    QPoint pnew;
    pnew.setX(p.x()*sx + c.x()*(1-sx));
    pnew.setY(p.y()*sy + c.y()*(1-sy));
    return pnew;
}

QPoint graphics::symmetryX(QPoint p){
    QPoint pnew;
    pnew.setX(p.x());
    pnew.setY(-p.y());
    return pnew;
}

QPoint graphics::symmetryY(QPoint p){
    QPoint pnew;
    pnew.setX(-p.x());
    pnew.setY(p.y());
    return pnew;
}

int graphics::random(int n){
    return rand()%n;
}

void graphics::drawThousandsOfStars(QPainter &painter){
    for(int i = 1; i <= 1000; i++){
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(random(255), random(255), random(255)));
        painter.drawEllipse(random(1000), random(1000), 3, 3);
    }
}

void graphics::drawFlower(QPainter &painter){
    painter.setBrush(QColor(random(255), random(255), random(255)));
//    int x = random(width());
//    int y = random(height());
    int x = width()/2;
    int y = height()/2;

    int d=150; // diameter
    int r=d/3; // radius
    QPoint c(x,y);
    QPoint p(x, y-r);
    for(int i=1; i <= 6; i++){
        QPoint pnew = rotation(p, c, i*60);
        painter.drawEllipse(pnew, r, r);
    }
}

void graphics::drawPentagon(QPainter &painter){
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    painter.setPen(pen);

    QPolygon polygon;
    int x = width()/2;
    int y = height()/2;
    QPoint p(x,y-100);
    QPoint c(x,y); // center point
    polygon << QPoint(p.x(), p.y());
    for(int i = 1; i <= 5; i++){
        QPoint pnew = rotation(p, c, i*72);
        polygon << QPoint(pnew.x(), pnew.y());
    }
    painter.drawPolygon(polygon);
    // draw a star in the pentagon
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.drawLine(polygon.value(0), polygon.value(3));
    painter.drawLine(polygon.value(0), polygon.value(2));
    painter.drawLine(polygon.value(1), polygon.value(4));
    painter.drawLine(polygon.value(1), polygon.value(3));
    painter.drawLine(polygon.value(2), polygon.value(4));
}


void graphics::drawRosette(QPainter &painter, int n){
    QPen pen;
    pen.setColor(Qt::blue);
    painter.setPen(pen);

    int x = width()/2;
    int y = height()/2;
    QPolygon polygon;
    QPoint p(x, y-100);
    QPoint c(x, y);
    polygon << QPoint(p.x(), p.y());
    for(int i = 1; i <= n; i++){
        QPoint pnew = rotation(p, c, i*(360/n));
        polygon << QPoint(pnew.x(), pnew.y());
    }
    painter.drawPolygon(polygon);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            painter.drawLine(polygon.value(i), polygon.value(j));
        }
    }
}

void graphics::drawTaijitu(QPainter &painter){
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);

    int x = width()/2;
    int y = height()/2;
    int r = 200; //  radius of the large circle
    int r1 = r/2; // radius of two small circles

    // x and y coordinate of the small circle on the left
    int xLeft = x-r;
    int yLeft = y-r1;

    // x and y coordinate of the small circle on the right
    int xRight = x;
    int yRight = y-r1;

    // the center point of the large circle
    QPoint c(x,y);


    painter.drawEllipse(c, r, r); // draw a large circle

    painter.drawArc(xLeft, yLeft, r, r, 0, -(180*16));

    xRight = symmetryX(QPoint(xLeft, yLeft)).x();
    yRight = symmetryY(QPoint(xLeft, yLeft)).y();
    xRight = translation(QPoint(xRight, yRight), r, 0).x();

    painter.drawArc(xRight, yRight, r, r, 0, (180*16));


    QPoint pLeft(x-r/2, y); // the center point of the small circle on the left
    QPoint pRight(x+r/2, y); // the center point of the small circle on the left
    painter.drawEllipse(pLeft, r/10, r/10);
    painter.drawEllipse(pRight, r/10, r/10);
}

void graphics::drawTaijituWithColor(QPainter &painter){
    QPen pen;
    pen.setColor(Qt::black);
    painter.setPen(pen);
    int x = width()/2;
    int y = height()/2;
    int r = 200; //  radius of the large circle
    int r1 = r/2; // radius of two small circles

    // the center point of the large circle
    QPoint c(x,y);
    int startAngle = 0;
    int spanAngle = 180*16;

    painter.drawEllipse(c, r, r); // draw a large circle

    // fill a half circle above
    painter.setBrush(Qt::black);
    painter.drawChord(c.x()-r, c.y()-r, r*2, r*2, startAngle, spanAngle);

    // fill a half circle below
    painter.setBrush(Qt::white);
    painter.drawChord(c.x()-r, c.y()-r, r*2, r*2, startAngle, -spanAngle);

    // x and y coordinate of the small circle on the left
    int xLeft = x-r; // xLeft = 137
    int yLeft = y-r1; // yLeft = 170

    painter.setBrush(Qt::black);
    painter.drawChord(xLeft, yLeft, r, r, startAngle, -spanAngle);

    // x and y coordinate of the small circle on the right
    int xRight = symmetryX(QPoint(xLeft, yLeft)).x();
    int yRight = symmetryY(QPoint(xLeft, yLeft)).y();

    QPoint pnew = translation(QPoint(xRight, yRight), r+2, 0);
    xRight = pnew.x();

    pen.setColor(Qt::white);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::white);

    painter.drawChord(xRight, yRight, r-3, r, startAngle, spanAngle);

    QPoint pLeft(x-r/2, y); // the center point of the small circle on the left
    QPoint pRight(x+r/2, y); // the center point of the small circle on the left

    painter.drawEllipse(pLeft, r/10, r/10);
    painter.setBrush(Qt::black);
    painter.drawEllipse(pRight, r/10, r/10);
}

void graphics::drawStar(QPainter &painter, const QColor &color){
    QPolygon poly;
    int x = width()/3;
    int y = height()/4;

    poly << QPoint(x, y+85) << QPoint(x+75, y+75)
         << QPoint(x+100, y+10) << QPoint(x+125, y+75)
         << QPoint(x+200, y+85) << QPoint(x+150, y+125)
         << QPoint(x+160, y+190) << QPoint(x+100, y+150)
         << QPoint(x+40, y+190) << QPoint(x+50, y+125)
         << QPoint(x, y+85);

    QPen pen(color);
    painter.setPen(pen);

    // Brush
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);

    // Fill polygon
    QPainterPath path;
    path.addPolygon(poly);

    // Draw polygon
    painter.drawPolygon(poly);
    painter.fillPath(path, brush);
}

void graphics::drawNationalFlag(QPainter &painter){
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    painter.drawRect(0, 0, width(), height());
    drawStar(painter, Qt::yellow);
}

void graphics::drawHouse(QPainter &painter, QPoint p, int w, int h){
    QPen pen;
    pen.setWidth(2);
    pen.setColor("#453bf7");
    painter.setPen(pen);

    int x = p.x();
    int y = p.y();
    int roofH = h/2; // roof height
    QPoint points1[6] = {
        QPoint(x, roofH+y),
        QPoint(w/2+x, y),
        QPoint(w+x, roofH+y),
        QPoint(w+x, h+y),
        QPoint(x, h+y),
        QPoint(x, roofH+y)
    };

    painter.drawPolygon(points1, 6); // draw border of the house

    int widthW = w/6; // width of window
    int heightW = w/6; // height of window

    painter.drawRect((w-(2*widthW))+x, (roofH+heightW)+y, widthW, heightW); // draw the window of the house

    int widthMW = w/4; // width of main window
    int heightMW = roofH/2; // height of main window

    painter.drawRect(widthMW+x, (roofH+heightMW)+y, widthMW, heightMW); // draw the main window of the house

    int heightC = h/3; // height of the chimney
    int widthC = w/6; // width of the chimney
    QPointF points2[4] = {
        QPointF(x+widthC, y+heightC),
        QPointF(x+widthC, y+widthC),
        QPointF(x+(widthC*2), y+widthC),
        QPointF(x+(widthC*2), y+(heightC/2))
    };

    painter.drawPolyline(points2, 4);
}

void graphics::drawVillage(QPainter &painter){
    int w = 50;
    int h = 80;
    QPoint p(10,10);
    drawHouse(painter, p, w, h);

    QPoint pnew = translation(p, 60, 60);
    drawHouse(painter, pnew, 100, 140);

    pnew = translation(p, 200, 10);
    drawHouse(painter, pnew, 200, 200);

    pnew = translation(p, p.x(), 250);
    drawHouse(painter, pnew, 100, 250);

    pnew = translation(p, 200, 250);
    drawHouse(painter, pnew, 80, 170);

    pnew = translation(p, 280, 250);
    drawHouse(painter, pnew, 80, 170);

    pnew = translation(p, 400, 250);
    drawHouse(painter, pnew, 180, 200);

    pnew = translation(p, 450, 20);
    drawHouse(painter, pnew, 100, 200);
}

void graphics::drawCircle(QPainter &painter){
    int n = 90;
    painter.translate(200, 200);
    painter.setPen(Qt::blue);
    QPoint p(0, 100);
    painter.drawEllipse(p, 25, 50);
    for(int i = 1; i < n; i++){
        painter.rotate(360/n);
        painter.drawEllipse(p, 25, 50);
    }
}

QPoint graphics::randomPoint(QPoint *p){
    int index = random(3);
    return p[index];
}

void graphics::drawSierpinskiGasket(QPainter &painter){
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    painter.setPen(pen);

    int w = width();
    int h = height();

    QPoint P1(w/2,10);
    QPoint P2(10, h-100);
    QPoint P3(w-100, h-100);

    QPoint listPoints[3];
    listPoints[0] = P1;
    listPoints[1] = P2;
    listPoints[2] = P3;

    QPoint G0;
    G0 = randomPoint(listPoints);
    painter.drawPoint(G0.x(), G0.y());
    for(int i = 1; i <= 10000; i++){
        painter.drawPoint(G0);
        QPoint P;
        P = randomPoint(listPoints);
        // calculate x-coordinate and y-coordinate of Gn as the middle point of P and G0
        int x = (G0.x()+ P.x())/2;
        int y = (G0.y()+ P.y())/2;
        G0.setX(x);
        G0.setY(y);
    }
}

void graphics::drawGingerbreadMan(QPainter &painter){
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    painter.setPen(pen);

    QPoint P(115, 121);
    QPoint Q;
    Q.setX(P.x());
    Q.setY(P.y());
    for(int i = 1; i <= 10000; i++){
        painter.drawPoint(Q);
        int x = 40*(1 + 2*3) - Q.y() + abs(Q.x() - 40*3);
        int y = Q.x();
        Q.setX(x);
        Q.setY(y);
    }
}
