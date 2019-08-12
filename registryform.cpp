#include "registryform.h"
#include "ui_registryform.h"

#include "QStandardItemModel"
#include "QStandardItem"

#include <QMessageBox>

RegistryForm::RegistryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistryForm)
{
    ui->setupUi(this);
}

RegistryForm::~RegistryForm()
{
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
    QSqlQuery res = DB_Adapter::query(sql_str);

    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;

    QStringList horizontalHeader;
    int i;

    QSqlRecord localRecord = res.record();
    for (i=0; i<localRecord.count(); ++i)
    {
        QString fieldName = localRecord.fieldName(i);
        qDebug() << fieldName;
        horizontalHeader.append(fieldName);
    }
    model->setHorizontalHeaderLabels(horizontalHeader);
    int curent_row = 0;
    while (res.next())
    {
        for (i=0; i<localRecord.count(); ++i)
        {
           item = new QStandardItem(QString(res.value(i).toString()));
           model->setItem(curent_row, i,item);
        }
        curent_row++;
    }
    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void RegistryForm::on_AddPatientPushButton_clicked()
{

}

void RegistryForm::on_OpenDiseasePushButton_clicked()
{
    if (ui->tableView->currentIndex().row() == -1)
    {
        QMessageBox msgBox;
        msgBox.setText("Choose the patient");
        msgBox.exec();
        return;
    }
    int id_patient = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 0, QModelIndex()), Qt::DisplayRole).toInt();
    OpenDiseaseDialog *open_disease_dlg = new OpenDiseaseDialog(nullptr, id_patient);
    open_disease_dlg->exec();
}

void RegistryForm::on_AddVisitPushButton_clicked()
{
    if (ui->tableView->currentIndex().row() == -1)
    {
        QMessageBox msgBox;
        msgBox.setText("Choose the patient");
        msgBox.exec();
        return;
    }
    int id_patient = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(), 0, QModelIndex()), Qt::DisplayRole).toInt();
    MakeAnAppointmentDialog *make_an_appointment_dlg = new MakeAnAppointmentDialog(nullptr, id_patient);
    make_an_appointment_dlg->exec();
}
