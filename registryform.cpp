#include "registryform.h"
#include "ui_registryform.h"
#include <QMessageBox>

RegistryForm::RegistryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistryForm)
{
    ui->setupUi(this);
    ui->PatientsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->DiseasesTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabWidget->setCurrentIndex(0);
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
    ui->PatientsTableView->setModel(Make_Model::fill(sql_str));
    ui->PatientsTableView->resizeRowsToContents();
    ui->PatientsTableView->resizeColumnsToContents();
}

void RegistryForm::on_AddPatientPushButton_clicked()
{

}

void RegistryForm::on_OpenDiseasePushButton_clicked()
{
    if (ui->PatientsTableView->currentIndex().row() == -1)
    {
        QMessageBox msgBox;
        msgBox.setText("Choose the patient");
        msgBox.exec();
        return;
    }
    int id_patient = ui->PatientsTableView->model()->data(ui->PatientsTableView->model()->index(ui->PatientsTableView->currentIndex().row(), 0, QModelIndex()), Qt::DisplayRole).toInt();
    OpenDiseaseDialog *open_disease_dlg = new OpenDiseaseDialog(nullptr, id_patient);
    open_disease_dlg->exec();
}

void RegistryForm::on_AddVisitPushButton_clicked()
{
    if (ui->PatientsTableView->currentIndex().row() == -1)
    {
        QMessageBox msgBox;
        msgBox.setText("Choose the patient");
        msgBox.exec();
        return;
    }
    int id_patient = ui->PatientsTableView->model()->data(ui->PatientsTableView->model()->index(ui->PatientsTableView->currentIndex().row(), 0, QModelIndex()), Qt::DisplayRole).toInt();
    MakeAnAppointmentDialog *make_an_appointment_dlg = new MakeAnAppointmentDialog(nullptr, id_patient);
    make_an_appointment_dlg->exec();
}

void RegistryForm::on_PatientsTableView_doubleClicked(const QModelIndex &index)
{
    qDebug() << "Double click";
    int id_patient = ui->PatientsTableView->model()->data(ui->PatientsTableView->model()->index(ui->PatientsTableView->currentIndex().row(), 0, QModelIndex()), Qt::DisplayRole).toInt();
    qDebug() << id_patient;

    ui->tabWidget->setCurrentIndex(1);
    ui->IDPatientLineEdit->setText(QString::number(id_patient));
    QString sql_str = "select \"Surname\", \"Name\", \"Patronymic\" from patients where \"ID\" = " + QString::number(id_patient);
    QSqlQuery res = DB_Adapter::query(sql_str);
    res.next();
    ui->FIOPatientLineEdit->setText(res.value(0).toString() + " " + res.value(1).toString() + " " + res.value(2).toString());

    sql_str = "select * from diseases where \"PatientID\" = " + QString::number(id_patient);
    ui->DiseasesTableView->setModel(Make_Model::fill(sql_str));
    ui->DiseasesTableView->resizeRowsToContents();
    ui->DiseasesTableView->resizeColumnsToContents();
}
