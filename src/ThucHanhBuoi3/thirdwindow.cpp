#include "thirdwindow.h"
#include "ui_thirdwindow.h"

ThirdWindow::ThirdWindow(QWidget *parent) : QDialog(parent), ui(new Ui::ThirdWindow){
    ui->setupUi(this);
}

ThirdWindow::~ThirdWindow(){
    delete ui;
}

void ThirdWindow::on_BtnDrawPolygon1_clicked(){
    ui->GraphicsPresenter->mode = 11;
    ui->GraphicsPresenter->repaint();
}

void ThirdWindow::on_BtnDrawPolygon2_clicked(){
    ui->GraphicsPresenter->mode = 12;
    ui->GraphicsPresenter->repaint();
}

void ThirdWindow::on_BtnDrawPolygon3_clicked(){
    ui->GraphicsPresenter->mode = 13;
    ui->GraphicsPresenter->repaint();
}

void ThirdWindow::on_BtnDrawPolygon4_clicked(){
    ui->GraphicsPresenter->mode = 14;
    ui->GraphicsPresenter->repaint();
}

void ThirdWindow::on_BtnDrawPolygon5_clicked(){
    ui->GraphicsPresenter->mode = 15;
    ui->GraphicsPresenter->repaint();
}

void ThirdWindow::on_BtnDrawPolygon6_clicked(){
    ui->GraphicsPresenter->mode = 16;
    ui->GraphicsPresenter->repaint();
}

void ThirdWindow::on_BtnDrawPolygon7_clicked(){
    ui->GraphicsPresenter->mode = 17;
    ui->GraphicsPresenter->repaint();
}
