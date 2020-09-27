#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <secondwindow.h>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BtnDrawStars_clicked();

    void on_BtnReset_clicked();

    void on_BtnDrawFlower_clicked();

    void on_BtnDrawPentagon_clicked();

    void on_BtnDrawTaijitu_clicked();

    void on_BtnDrawRosettes_clicked();

    void on_BtnDrawNationalFlag_clicked();

    void on_BtnDrawVillage_clicked();

    void on_BtnDrawTaijituColor_clicked();

    void on_BtnDrawSG_clicked();

    void on_BtnDrawGM_clicked();

private:
    Ui::MainWindow *ui;
    SecondWindow *secondWin;
};

#endif // MAINWINDOW_H
