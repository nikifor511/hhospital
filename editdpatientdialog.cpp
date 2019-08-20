#include "editpatientdialog.h"
#include "ui_editpatientdialog.h"

#include <QFileDialog>


EditPatientDialog::EditPatientDialog(QWidget *parent, bool isEdit) :
    QDialog(parent),
    ui(new Ui::EditPatientDialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(NULL);
    ui->graphicsView->setScene(scene);
    pixmap_item = new QGraphicsPixmapItem();
    scene->addItem(pixmap_item);
    this->isEdit = isEdit;
}

EditPatientDialog::~EditPatientDialog()
{
    delete ui;
}

void EditPatientDialog::on_ChoosePhotoButton_clicked()
{
    m_fileName = QFileDialog::getOpenFileName(this, "Get Any File");
    ui->FilePathLabel->setText(m_fileName);

    QPixmap *photo = new QPixmap(m_fileName);
    pixmap_item->setVisible(true);
    pixmap_item->setPixmap(*photo);
    scene->setSceneRect(0, 0, photo->width(), photo->height());
    ui->graphicsView->fitInView(pixmap_item, Qt::KeepAspectRatio);
    ui->graphicsView->setScene(scene);


}
