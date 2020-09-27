#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_BtnReset_clicked(){
    ui->GraphicsPresenter->mode = 0;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawStars_clicked(){
    ui->GraphicsPresenter->mode = 1;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawPentagon_clicked(){\
    ui->GraphicsPresenter->mode = 2;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawFlower_clicked(){
    ui->GraphicsPresenter->mode = 3;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawTaijitu_clicked(){
    ui->GraphicsPresenter->mode = 4;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawRosettes_clicked(){
    secondWin = new SecondWindow(this);
    secondWin->show();
}

void MainWindow::on_BtnDrawNationalFlag_clicked(){
    ui->GraphicsPresenter->mode = 5;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawVillage_clicked(){
    ui->GraphicsPresenter->mode = 6;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawTaijituColor_clicked(){
    ui->GraphicsPresenter->mode = 8;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawSG_clicked(){
    ui->GraphicsPresenter->mode = 9;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawGM_clicked(){
    ui->GraphicsPresenter->mode = 10;
    ui->GraphicsPresenter->repaint();
}
