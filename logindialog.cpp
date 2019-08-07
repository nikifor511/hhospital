#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_2_clicked()
{
    this->close();
}

void LoginDialog::on_pushButton_clicked()
{
    QMessageBox msgBox;
    if ((ui->loginLineEdit->text() == "") || (ui->passLineEdit->text() == ""))
    {

        msgBox.setText("Fill in all the fields!");
        msgBox.exec();
    }


    QString sql_str = "select login_user('";
    sql_str = sql_str + ui->loginLineEdit->text() + "', '" + ui->passLineEdit->text() + "')";
    qDebug() << sql_str;
    QSqlQuery res = DB_Adapter::query(sql_str);
    res.next();
    switch (res.value(0).toInt()) {
        case 1:
        {
            RegistryForm *registry_frm = new RegistryForm;
            registry_frm->setWindowModality(Qt::WindowModal);
            registry_frm->show();
            this->close();
            break;
        }

//        case 2:
//            break;
//        case 3:
//            break;
        default:
        {
            msgBox.setText("Check your login/password");
            msgBox.exec();
            break;
        }

    }
}
