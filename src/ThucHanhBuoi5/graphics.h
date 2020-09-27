#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QWidget>

class graphics: public QWidget{
    Q_OBJECT

    public:
        explicit graphics(QWidget *parent = 0);
        void paintEvent(QPaintEvent *);
        void timerEvent(QTimerEvent *);
        int mode = 0;
        double timerId;
        double position;
        double posImage;
        float h; // hour
        float m; // minutes
        float s; // second
        int size;
        double opacity;
        int random(int num);
        void drawMegaman(QPainter &painter);
        QPoint rotation(QPoint p, QPoint c, int delta);
        void drawWatch(QPainter &painter);
        void drawStar(QPainter &painter, int x, int y, int r, const QColor &color, double opacity);
        void drawSkyNight(QPainter &painter);
    signals:

    public slots:

};

#endif // GRAPHICS_H
