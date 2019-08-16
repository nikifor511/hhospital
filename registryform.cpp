#include "registryform.h"
#include "ui_registryform.h"
#include <QMessageBox>


RegistryForm::RegistryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistryForm)
{
    ui->setupUi(this);
    ui->RegistryTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableNameLabel->setText("Patients");
    table_index = 0;
}

RegistryForm::~RegistryForm(){
    delete ui;
}

void RegistryForm::on_SearchPatientPushButton_clicked()
{
    QString fio_str = ui->searchPatientLineEdit->text().replace(QRegExp("[ ]{2,}")," ");
    fio_str.remove(QRegExp("\\s+$"));
    qDebug() << fio_str;
    QStringList FIO = fio_str.split(" ");
    foreach (QString n, FIO)
        qDebug() << n;
    QString sql_str;
    switch (FIO.length()) {
        case 2:
        {
            sql_str = "select * from patients where \"Surname\" = '" + FIO[0] + "' and \"Name\" = '" + FIO[1] + "'";
            qDebug() << sql_str;
            break;
        }
        case 3:
        {
            sql_str = sql_str = "select * from patients where \"Surname\" = '" + FIO[0] + "' and \"Name\" = '" + FIO[1] + "' and \"Patronymic\" = '" + FIO[2] + "'";
            qDebug() << sql_str;
            break;
        }
        default:
        {
            sql_str = "select * from patients where \"Surname\" = '" + FIO[0] + "'";
            qDebug() << sql_str;
            break;
        }
    }
    table_index = 0;
    ui->RegistryTableView->setModel(Make_Model::fill(sql_str));
    ui->RegistryTableView->resizeRowsToContents();
    ui->RegistryTableView->resizeColumnsToContents();
}

void RegistryForm::on_AddPatientPushButton_clicked()
{

}

void RegistryForm::on_OpenDiseasePushButton_clicked()
{
    if (ui->RegistryTableView->currentIndex().row() == -1)
    {
        QMessageBox msgBox;
        msgBox.setText("Choose the patient");
        msgBox.exec();
        return;
    }
    int id_patient = ui->RegistryTableView->model()->data(ui->RegistryTableView->model()->index(ui->RegistryTableView->currentIndex().row(), 0, QModelIndex()), Qt::DisplayRole).toInt();
    OpenDiseaseDialog *open_disease_dlg = new OpenDiseaseDialog(nullptr, id_patient);
    open_disease_dlg->exec();
}

void RegistryForm::on_AddVisitPushButton_clicked()
{
    if (ui->RegistryTableView->currentIndex().row() == -1)
    {
        QMessageBox msgBox;
        msgBox.setText("Choose the patient");
        msgBox.exec();
        return;
    }
    int id_patient = ui->RegistryTableView->model()->data(ui->RegistryTableView->model()->index(ui->RegistryTableView->currentIndex().row(), 0, QModelIndex()), Qt::DisplayRole).toInt();
    MakeAnAppointmentDialog *make_an_appointment_dlg = new MakeAnAppointmentDialog(nullptr, id_patient);
    make_an_appointment_dlg->exec();
}

void RegistryForm::on_RegistryTableView_doubleClicked(const QModelIndex &index)
{
    int id_value = ui->RegistryTableView->model()->data(ui->RegistryTableView->model()->index(ui->RegistryTableView->currentIndex().row(), 0, QModelIndex()), Qt::DisplayRole).toInt();
    QString sql_str;
    QSqlQuery res;

    switch (table_index)
    {
        case (0):
            ui->IDPatientLineEdit->setText(QString::number(id_value));
            sql_str = "select \"Surname\", \"Name\", \"Patronymic\" from patients where \"ID\" = " + QString::number(id_value);
            res = DB_Adapter::query(sql_str);
            res.next();
            ui->FIOPatientLineEdit->setText(res.value(0).toString() + " " + res.value(1).toString() + " " + res.value(2).toString());
            sql_str = "select * from diseases where \"PatientID\" = " + QString::number(id_value);
            ui->RegistryTableView->setModel(Make_Model::fill(sql_str));
            ui->RegistryTableView->resizeRowsToContents();
            ui->RegistryTableView->resizeColumnsToContents();
            table_index = 1;
            ui->TableNameLabel->setText("Diseases");
            break;

        case (1):
            ui->IDDiseaseLineEdit->setText(QString::number(id_value));
            sql_str = "select \"DateBegin\", \"Description\" from diseases where \"ID\" = " + QString::number(id_value);
            res = DB_Adapter::query(sql_str);
            res.next();
            ui->DescriptionDiseaseLineEdit->setText(res.value(0).toString());
            ui->BeginDateEdit->setDate(res.value(1).toDate());
            sql_str = "select * from visits where \"DiseaseID\" = " + QString::number(id_value);
            ui->RegistryTableView->setModel(Make_Model::fill(sql_str));
            ui->RegistryTableView->resizeRowsToContents();
            ui->RegistryTableView->resizeColumnsToContents();
            table_index = 2;
            ui->TableNameLabel->setText("Visits");
            break;
    }

    int u =9;
    u++;





}
