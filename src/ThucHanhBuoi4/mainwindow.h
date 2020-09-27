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
    void on_BtnDrawEx_clicked();

    void on_BtnDrawCar_clicked();

    void on_BtnAnimation_clicked();

    void on_BtnDrawSolarSys_clicked();

    void on_BtnReset_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
