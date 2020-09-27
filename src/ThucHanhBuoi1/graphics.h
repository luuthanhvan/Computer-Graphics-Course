#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QWidget>

class graphics: public QWidget{
    Q_OBJECT

    public:
        explicit graphics(QWidget *parent = 0);
        void paintEvent(QPaintEvent *);
        void DrawSquareCircle(QPainter &painter);
        void DrawCircleSquare(QPainter &painter);
        void DrawTaijitu(QPainter &painter);
        void DrawHouse(QPainter &painter);
        void DrawChessboard(QPainter &painter);
        void eightSym(int x, int y, int xc, int yc, char* color);
        void circ(int xc, int yc, int R, char* color);
        void circMidPoint(int xc, int yc, int R, char* color);
        int mode = 0;
    signals:

    public slots:

};

#endif // GRAPHICS_H
