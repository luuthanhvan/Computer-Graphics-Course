#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <secondwindow.h>
#include <thirdwindow.h>
#include <fourthwindow.h>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BtnDrawHook_clicked();

    void on_BtnDrawRect_clicked();

    void on_BtnDrawRect45_clicked();

    void on_BtnDrawSquare_clicked();

    void on_BtnDrawTriangle_clicked();

    void on_BtnDrawPolyspirals_clicked();

    void on_BtnDrawRosette_clicked();

    void on_BtnDrawSky_clicked();

    void on_BtnReset_clicked();

    void on_BtnDrawPolygons_clicked();

private:
    Ui::MainWindow *ui;
    SecondWindow *secondWin;
    ThirdWindow *thirdWin;
    FourthWindow *fourthWin;
};

#endif // MAINWINDOW_H
