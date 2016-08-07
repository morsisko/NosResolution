#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fpsbreaker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_fpsSpinBox_valueChanged(int arg1);

    void on_fpsPushButton_clicked();

private:
    Ui::MainWindow *ui;
    FpsBreaker fpsBreaker;
};

#endif // MAINWINDOW_H
