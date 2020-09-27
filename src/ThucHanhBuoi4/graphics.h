#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QWidget>

class graphics: public QWidget{
    Q_OBJECT

    public:
        explicit graphics(QWidget *parent = 0);
        void paintEvent(QPaintEvent *);
        int mode = 0;

        void timerEvent(QTimerEvent *);
        double position;
        double timeID;

        int h = height();
        int w = width();
        void drawExample(QPainter &painter);
        void drawCar(QPainter &painter);

        QPointF pStart, pCenter, pNew;
        int angle;
        int random(int num);
        QPointF rotation(QPointF p, QPointF c, int delta);
        void rotateImage(QPainter &painter, QString image1, QString image2, int w, int h, int r);
        void animationCircle(QPainter &painter);
        void drawStar(QPainter &painter, QPointF pCenter, int r);
        void animationStarCircle(QPainter &painter);
        void drawSolarSystem(QPainter &painter);
        void drawNightSky(QPainter &painter);
    signals:

    public slots:

};

#endif // GRAPHICS_H
