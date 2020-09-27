#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_BtnDrawSquareCircle_clicked(){
    ui->GraphicsPresenter->mode = 1; // set mode = 1 to draw a square inside a circle
    ui->GraphicsPresenter->repaint(); // repaint() will call paintEvent
}

void MainWindow::on_BtnDrawCircleSquare_clicked(){
    ui->GraphicsPresenter->mode = 2;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawTaijitu_clicked(){
    ui->GraphicsPresenter->mode = 3;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawHouse_clicked(){
    ui->GraphicsPresenter->mode = 4;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawChessboard_clicked(){
    ui->GraphicsPresenter->mode = 5;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnReset_clicked(){
    ui->GraphicsPresenter->mode = 0; // set mode = 0 to reset
    ui->GraphicsPresenter->repaint();
}
