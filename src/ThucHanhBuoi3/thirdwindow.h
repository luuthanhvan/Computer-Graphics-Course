#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = 0);
    ~ThirdWindow();

private slots:

    void on_BtnDrawPolygon1_clicked();

    void on_BtnDrawPolygon2_clicked();

    void on_BtnDrawPolygon3_clicked();

    void on_BtnDrawPolygon4_clicked();

    void on_BtnDrawPolygon5_clicked();

    void on_BtnDrawPolygon6_clicked();

    void on_BtnDrawPolygon7_clicked();

    void on_BtnDrawPolygon8_clicked();

    void on_BtnReset_clicked();

private:
    Ui::ThirdWindow *ui;
};

#endif // THIRDWINDOW_H
