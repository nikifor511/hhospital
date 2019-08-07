#include "opendiseasedialog.h"
#include "ui_opendiseasedialog.h"

OpenDiseaseDialog::OpenDiseaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDiseaseDialog)
{
    ui->setupUi(this);
}

OpenDiseaseDialog::~OpenDiseaseDialog()
{
    delete ui;
}
