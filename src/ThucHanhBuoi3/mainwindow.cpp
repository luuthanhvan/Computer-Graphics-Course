#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_BtnDrawHook_clicked(){
    ui->GraphicsPresenter->mode = 1;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawRect_clicked(){
    ui->GraphicsPresenter->mode = 2;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawRect45_clicked(){
    ui->GraphicsPresenter->mode = 3;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawSquare_clicked(){
    ui->GraphicsPresenter->mode = 4;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawTriangle_clicked(){
    ui->GraphicsPresenter->mode = 5;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawPolyspirals_clicked(){
    secondWin = new SecondWindow(this);
    secondWin->show();
}

void MainWindow::on_BtnDrawPolygons_clicked(){
    thirdWin = new ThirdWindow(this);
    thirdWin->show();
}

void MainWindow::on_BtnDrawRosette_clicked(){
    fourthWin = new FourthWindow(this);
    fourthWin->show();
}

void MainWindow::on_BtnDrawSky_clicked(){
    ui->GraphicsPresenter->mode = 21;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnReset_clicked(){
    ui->GraphicsPresenter->mode = 0;
    ui->GraphicsPresenter->repaint();
}
