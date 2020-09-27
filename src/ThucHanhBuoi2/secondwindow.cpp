#include <stdlib.h>
#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_BthReset_clicked(){
    ui->GraphicsPresenter->rosette = 0;
    ui->GraphicsPresenter->repaint();
}

void SecondWindow::on_BtnDrawRosette5_clicked(){
    ui->GraphicsPresenter->rosette = 5;
    ui->GraphicsPresenter->repaint();
}

void SecondWindow::on_BtnDrawRosette11_clicked(){
    ui->GraphicsPresenter->rosette = 11;
    ui->GraphicsPresenter->repaint();
}

void SecondWindow::on_BtnDrawRosette20_clicked(){
    ui->GraphicsPresenter->rosette = 20;
    ui->GraphicsPresenter->repaint();
}
