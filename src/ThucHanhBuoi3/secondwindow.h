#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();

private slots:
    void on_BtnDrawPolysprials1_clicked();

    void on_BtnDrawPolysprials2_clicked();

    void on_BtnDrawPolysprials3_clicked();

    void on_BtnDrawPolysprials4_clicked();

    void on_BtnDrawPolysprials5_clicked();

    void on_BtnReset_clicked();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
