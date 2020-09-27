#include "graphics.h"
#include <cmath>
#include <QPainter>
#include <QPen>
#include <QRectF>
#include <QColor>
#include <QPointF>
#include <QPainterPath>

graphics::graphics(QWidget *parent):QWidget(parent){}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    // mode is equal zero for reseting to draw, mode is not equal zero for drawing shapes
    if(mode == 1)
        DrawSquareCircle(painter);
    if(mode == 2)
        DrawCircleSquare(painter);
    if(mode == 3)
        DrawTaijitu(painter);
    if(mode == 4)
        DrawHouse(painter);
    if(mode == 5)
        DrawChessboard(painter);
}

// Draw a square inside a circle
void graphics::DrawSquareCircle(QPainter &painter){
    QPen pen;
    pen.setWidth(3);

    int x = 50; // init value for x-coordinate
    int y = 50; // init value for y-coordinate
    int width = 200; // specify width
    int height = 200; // specify height

    pen.setColor(Qt::red); // border color of the square
    painter.setPen(pen);

    painter.drawRect(x+40, y+40, width, height); // draw the square

    pen.setColor(Qt::blue); // border color of the circle
    painter.setPen(pen);

    painter.drawEllipse(x, y, width*sqrt(2), height*sqrt(2)); // draw the circle
}

// Draw a circle inside a square
void graphics::DrawCircleSquare(QPainter &painter){
    QPen pen;
    pen.setWidth(3);

    int x = 50; // init value for x-coordinate
    int y = 50; // init value for y-coordinate
    int width = 250; // specify width
    int height = 250; // specify height

    pen.setColor(Qt::blue); // border color of the square
    painter.setPen(pen);

    painter.drawRect(x, y ,width, height); // draw the square

    pen.setColor(Qt::red); // border color of the square
    painter.setPen(pen);

    painter.drawEllipse(x, y ,width, height); // draw the circle
}

/* Implementation the algorithm to draw a cirle */
/*
void graphics::eightSym(int x, int y, int xc, int yc, char* color){
    QPen pen;
    pen.setColor(color);
    pen.setWidth(2); // set default width
    QPainter painter(this);
    painter.setPen(pen);
    painter.drawPoint(xc + x, yc + y);
    painter.drawPoint(xc - x, yc + y);
    painter.drawPoint(xc + x, yc - y);
    painter.drawPoint(xc - x, yc - y);
    painter.drawPoint(xc + y, yc + x);
    painter.drawPoint(xc - y, yc + x);
    painter.drawPoint(xc + y, yc - x);
    painter.drawPoint(xc - y, yc - x);
}

// Simple algorithm to draw a circle
void graphics::circ(int xc, int yc, int R, char* color){
    int x, y;
    for(x = 0; x < (int)(R/sqrt(2)); x++){
        y = (int)sqrt((R*R) - (x*x));
        eightSym(x, y, xc, yc, color);
    }
}

// MidPoint algorithm to draw a circle
// xc: x-coordinate
// yc: y-coordinate
// R: radius
// color: border color
void graphics::circMidPoint(int xc, int yc, int R, char *color){
    int x = 0, y = R;
    int p = 1 - R;
    eightSym(x, y, xc, yc,color);
    while(x < y){
        x++;
        if(p < 0){
            p += (2 * x) + 3;
        }
        else{
            p += 2*(x-y) + 5;
            y--;
        }
        eightSym(x, y, xc, yc, color);
    }
} */

// draw a Taijitu
void graphics::DrawTaijitu(QPainter &painter){
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red); // border color
    painter.setPen(pen);

    int x = 20; // init value for x-coordinate of the large circle
    int y = 20; // init value for y-coordinate of the large circle
    int w = 300; // width of the large circle
    int h = 300; // height of the large circle

    painter.drawEllipse(x, y, w, h); // draw a large circle

    // calculating middle point of the large circle
    int xc = x + w/2;
    int yc = y + h/2;

    int w1 = 40; // width of two small circles
    int h1 = 40; // height of two small circles
    int r = w1/2; // radius of two small circles

    // toa do x cua hinh tron nho thu nhat = (1/4)*w + x (toa do x cua hinh tron lon)
    int x1 = x + (w*0.25);
    int y1 = yc; // toa do y cua hinh tron nho se trung voi vi tri toa do cua diem giua hinh tron lon

    painter.drawEllipse(x1-r, y1-r, w1, h1); // draw the first small circle

    // toa do x cua hinh tron nho thu hai = (3/4)*w + x
    int x2 = x + (w*0.75);
    int y2 = yc;

    painter.drawEllipse(x2-r, y2-r, w1, h1); // draw the rest small circle

    int startAngle = 0;
    int spanAngle = 180 * 16;

    painter.drawArc(x, y+(h/4), w/2, h/2, startAngle, -spanAngle);
    painter.drawArc(xc, y+(h/4), w/2, h/2, startAngle, spanAngle);
}

void graphics::DrawHouse(QPainter &painter){
    QPen pen;
    pen.setWidth(2);
    pen.setColor("#453bf7");
    painter.setPen(pen);

    int x = 120;
    int y = 80;
    int h = 220;
    int roofH = 100; // roof height
    int w = 140;
    QPointF points1[6] = {
        QPointF(x, roofH+y),
        QPointF(w/2+x, y),
        QPointF(w+x, roofH+y),
        QPointF(w+x, h+y),
        QPointF(x, h+y),
        QPointF(x, roofH+y)
    };

    painter.drawPolygon(points1, 6); // draw border of the house

    int widthW = 20; // width of window
    int heightW = 20; // height of window

    painter.drawRect((w-(2*widthW))+x, (roofH+heightW)+y, widthW, heightW); // draw the window of the house

    int widthMW = 30; // width of main window
    int heightMW = 60; // height of main window

    painter.drawRect(widthMW+x, (roofH+heightMW)+y, widthMW, heightMW); // draw the main window of the house

    int heightC = 75; // height of the chimney
    int widthC = 15; // width of the chimney
    QPointF points2[4] = {
        QPointF(x+widthC, y+heightC),
        QPointF(x+widthC, y+widthC),
        QPointF(x+(widthC*2), y+widthC),
        QPointF(x+(widthC*2), y+(heightC-widthC))
    };

    painter.drawPolyline(points2, 4);
}

// Draw a chessboard
void graphics::DrawChessboard(QPainter &painter){
    int x, y, width, height;
    x = 40; // init value for x-coordinate
    y = 40; // init value for y-coordinate
    width = 40; // specify width for each cell
    height = 40; // specify height for each cell
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            if(i %2 != 0){ // odd lines
                if(j % 2 != 0){
                    painter.setBrush(QColor("#f0f3f7"));
                }
                else{
                    painter.setBrush(QColor("#424345"));
                }
                painter.drawRect(x, y, width, height);
                x += width; // increasing x in each for(i) loop
            }
            else { // even lines
                if(j % 2 != 0){
                    painter.setBrush(QColor("#424345"));
                }
                else{
                    painter.setBrush(QColor("#f0f3f7"));
                }
                painter.drawRect(x, y, width, height);
                x += width;
            }
        }
        x = 40; // reset x to init value
        y += height; // increasing y when for(j) loop end
    }
}
