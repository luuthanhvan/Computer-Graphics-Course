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

void MainWindow::on_BthDrawMegaman_clicked(){
    ui->GraphicsPresenter->mode = 1;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BthDrawWatch_clicked(){
    ui->GraphicsPresenter->mode = 2;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BthDrawSky_clicked(){
    ui->GraphicsPresenter->mode = 3;
    ui->GraphicsPresenter->repaint();
}

void MainWindow::on_BtnReset_clicked(){
    ui->GraphicsPresenter->mode = 0;
    ui->GraphicsPresenter->repaint();
}
