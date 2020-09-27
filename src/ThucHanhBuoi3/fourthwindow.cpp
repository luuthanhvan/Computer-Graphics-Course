#include "fourthwindow.h"
#include "ui_fourthwindow.h"

FourthWindow::FourthWindow(QWidget *parent) : QDialog(parent), ui(new Ui::FourthWindow){
    ui->setupUi(this);
}

FourthWindow::~FourthWindow(){
    delete ui;
}

void FourthWindow::on_BtnDrawRosette1_clicked(){
    ui->GraphicsPresenter->mode = 18;
    ui->GraphicsPresenter->repaint();
}

void FourthWindow::on_BtnDrawRosette2_clicked(){
    ui->GraphicsPresenter->mode = 19;
    ui->GraphicsPresenter->repaint();
}

void FourthWindow::on_BtnDrawRosette3_clicked(){
    ui->GraphicsPresenter->mode = 20;
    ui->GraphicsPresenter->repaint();
}

void FourthWindow::on_BtnReset_clicked(){
    ui->GraphicsPresenter->mode = 0;
    ui->GraphicsPresenter->repaint();
}
