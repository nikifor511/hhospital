#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QSqlQuery q = DB_Adapter::query("select * from patients");
//    while (q.next())
//    {
//        qDebug() << q.value(1).toString() << "/n";
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    LoginDialog *login_dlg = new LoginDialog;
    login_dlg->exec();
}
