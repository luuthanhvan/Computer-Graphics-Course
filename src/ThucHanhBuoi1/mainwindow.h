#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BtnDrawSquareCircle_clicked();

    void on_BtnReset_clicked();

    void on_BtnDrawCircleSquare_clicked();

    void on_BtnDrawTaijitu_clicked();

    void on_BtnDrawChessboard_clicked();

    void on_BtnDrawHouse_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
