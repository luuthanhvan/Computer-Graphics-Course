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
    void on_BtnDrawRosette5_clicked();

    void on_BtnDrawRosette11_clicked();

    void on_BtnDrawRosette20_clicked();

    void on_BthReset_clicked();
private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
