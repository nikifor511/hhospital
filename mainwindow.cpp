#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DB_Adapter::query("select * from patients");
}

MainWindow::~MainWindow()
{
    delete ui;
}
