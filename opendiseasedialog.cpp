#include "opendiseasedialog.h"
#include "ui_opendiseasedialog.h"

OpenDiseaseDialog::OpenDiseaseDialog(QWidget *parent, int id_patient) :
    QDialog(parent),
    ui(new Ui::OpenDiseaseDialog)
{
    ui->setupUi(this);

    QString sql_str = "select \"Surname\", \"Name\", \"Patronymic\" from patients where \"ID\" = " +  QString::number(id_patient);
    qDebug() << sql_str;
    QSqlQuery res = DB_Adapter::query(sql_str);
    ui->IDPatientLineEdit->setText(QString::number(id_patient));
    res.next();
    ui->FIOPatientLineEdit->setText(res.value(0).toString() + " " + res.value(1).toString() + " " + res.value(2).toString());

    sql_str = "select \"ID\", \"Surname\", \"Name\", \"Patronymic\" from doctors";
    res = DB_Adapter::query(sql_str);
    while (res.next())
    {
        ui->FIODoctorComboBox->addItem(res.value(0).toString() + ">" + res.value(1).toString() + " " + res.value(2).toString() + " " + res.value(3).toString());
    }

    ui->dateEdit->setDate(QDate::currentDate());
}

OpenDiseaseDialog::~OpenDiseaseDialog()
{
    delete ui;
}



void OpenDiseaseDialog::on_FIODoctorComboBox_currentIndexChanged(int index)
{
    QString str_combo_box = ui->FIODoctorComboBox->itemText(ui->FIODoctorComboBox->currentIndex());
    QStringList str_combo_box_words = str_combo_box.split(">");
    ui->IDDoctorLineEdit->setText(str_combo_box_words[0]);
}

void OpenDiseaseDialog::on_CancelPushButton_clicked()
{
    this->close();
}

void OpenDiseaseDialog::on_OpenDiseasePushButton_clicked()
{
    QString sql_str = "insert into diseases (\"DoctorID\", \"PatientID\", \"DateBegin\", \"Description\") values (" +
            ui->IDDoctorLineEdit->text() + ", " + ui->IDPatientLineEdit->text() + ", '" +ui->dateEdit->date().toString("yyyy-MM-dd") + "', '" + ui->DescriptionTextEdit->toPlainText() + "')";
    qDebug() << sql_str;
    QSqlQuery res = DB_Adapter::query(sql_str);

}
