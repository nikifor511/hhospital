#include "makeanappointmentdialog.h"
#include "ui_makeanappointmentdialog.h"

MakeAnAppointmentDialog::MakeAnAppointmentDialog(QWidget *parent, int id_patient) :
    QDialog(parent),
    ui(new Ui::MakeAnAppointmentDialog)
{
    ui->setupUi(this);
    QString sql_str = "select \"Surname\", \"Name\", \"Patronymic\" from patients where \"ID\" = " +  QString::number(id_patient);
    qDebug() << sql_str;
    QSqlQuery res = DB_Adapter::query(sql_str);
    ui->IDPatientLineEdit->setText(QString::number(id_patient));
    res.next();
    ui->FIOPatientLineEdit->setText(res.value(0).toString() + " " + res.value(1).toString() + " " + res.value(2).toString());
    sql_str = "select \"Surname\", \"Name\", \"Patronymic\" from doctors";
    res = DB_Adapter::query(sql_str);
    while (res.next())
    {
        ui->FIODoctorComboBox->addItem(res.value(0).toString() + " " + res.value(1).toString() + " " + res.value(2).toString());
    }
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

MakeAnAppointmentDialog::~MakeAnAppointmentDialog()
{
    delete ui;
}

void MakeAnAppointmentDialog::on_comboBox_currentIndexChanged(int index)
{

}
