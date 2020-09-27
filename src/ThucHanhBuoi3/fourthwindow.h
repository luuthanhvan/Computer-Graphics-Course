#ifndef FOURTHWINDOW_H
#define FOURTHWINDOW_H

#include <QDialog>

namespace Ui {
class FourthWindow;
}

class FourthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FourthWindow(QWidget *parent = 0);
    ~FourthWindow();

private slots:
    void on_BtnDrawRosette1_clicked();

    void on_BtnDrawRosette2_clicked();

    void on_BtnDrawRosette3_clicked();

    void on_BtnReset_clicked();

private:
    Ui::FourthWindow *ui;
};

#endif // FOURTHWINDOW_H
