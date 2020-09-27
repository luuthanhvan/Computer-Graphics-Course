#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnDrawEx_clicked(){
    ui->GraphicsPresenter->mode = 1;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawCar_clicked(){
    ui->GraphicsPresenter->mode = 2;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnAnimation_clicked(){
    ui->GraphicsPresenter->mode = 3;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnDrawSolarSys_clicked(){
    ui->GraphicsPresenter->mode = 4;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnReset_clicked(){
    ui->GraphicsPresenter->mode = 0;
    ui->GraphicsPresenter->repaint();
}
