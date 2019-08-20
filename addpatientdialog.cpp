#include "addpatientdialog.h"
#include "ui_addpatientdialog.h"

#include <QFileDialog>


AddPatientDialog::AddPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPatientDialog)
{
    ui->setupUi(this);
}

AddPatientDialog::~AddPatientDialog()
{
    delete ui;
}

void AddPatientDialog::on_ChoosePhotoButton_clicked()
{

}
