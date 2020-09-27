#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) : QDialog(parent), ui(new Ui::SecondWindow){
    ui->setupUi(this);
}

SecondWindow::~SecondWindow(){
    delete ui;
}

void SecondWindow::on_BtnDrawPolysprials1_clicked(){
    ui->GraphicsPresenter->mode = 6;
    ui->GraphicsPresenter->repaint();
}

void SecondWindow::on_BtnDrawPolysprials2_clicked(){
    ui->GraphicsPresenter->mode = 7;
    ui->GraphicsPresenter->repaint();
}

void SecondWindow::on_BtnDrawPolysprials3_clicked(){
    ui->GraphicsPresenter->mode = 8;
    ui->GraphicsPresenter->repaint();
}

void SecondWindow::on_BtnDrawPolysprials4_clicked(){
    ui->GraphicsPresenter->mode = 9;
    ui->GraphicsPresenter->repaint();
}

void SecondWindow::on_BtnDrawPolysprials5_clicked(){
    ui->GraphicsPresenter->mode = 10;
    ui->GraphicsPresenter->repaint();
}

void SecondWindow::on_BtnReset_clicked(){
    ui->GraphicsPresenter->mode = 0;
    ui->GraphicsPresenter->repaint();
}
