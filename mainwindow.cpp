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

void MainWindow::on_fpsSpinBox_valueChanged(int arg1)
{
    if (arg1 == 0)
        ui->fpsLabel->setText("About: NO LIMIT FPS");

    else
    {
        ui->fpsLabel->setText("About: " + QString::number(1000 / arg1) + " MAX FPS");
    }
}


void MainWindow::on_fpsPushButton_clicked()
{
    fpsBreaker.setFpsLimit(ui->fpsSpinBox->value());
}
