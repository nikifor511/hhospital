#include "editpatientdialog.h"
#include "ui_editpatientdialog.h"

#include <QFileDialog>


EditPatientDialog::EditPatientDialog(QWidget *parent,  int id_patient) :
    QDialog(parent),
    ui(new Ui::EditPatientDialog)
{
    ui->setupUi(this);

    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished, this, &EditPatientDialog::uploadFinished);

    scene = new QGraphicsScene(NULL);
    ui->graphicsView->setScene(scene);
    pixmap_item = new QGraphicsPixmapItem();
    scene->addItem(pixmap_item);

    this->id_patient = id_patient;



    if (this->id_patient != 0)
    {
        QString sql_str = "select \"Surname\", \"Name\", \"Patronymic\", \"Birthday\", \"Address\", \"Gender\", \"InsurancePolicy\" from patients where \"ID\" = " +  QString::number(this->id_patient);
        QSqlQuery res = DB_Adapter::query(sql_str);
        res.next();
        ui->SurnameLineEdit->setText(res.value(0).toString());
        ui->NameLineEdit->setText(res.value(1).toString());
        ui->PatronymicLineEdit->setText(res.value(2).toString());
        ui->BirthdayDateEdit->setDate(res.value(3).toDate());
        ui->AddressLineEdit->setText(res.value(4).toString());
        if (res.value(5).toBool())
            ui->GenderComboBox->setCurrentIndex(0);
        else
            ui->GenderComboBox->setCurrentIndex(1);
        ui->InsurancePolicyLineEdit->setText(res.value(6).toString());

        QUrl url("ftp://nikifor.ucoz.net/img/3_photo.jpg");
        url.setUserName("enikifor");    // Set login
        url.setPassword("student511"); // Set пароль
        url.setPort(21);             // Protocol port, which we will work on
        QNetworkReply *reply = m_manager->get(QNetworkRequest(url));
    }
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

void EditPatientDialog::on_UploadPhotoButton_clicked()
{
    if (ui->FilePathLabel->text() != "<>")
    {

        m_file = new QFile(m_fileName);
        QFileInfo fileInfo(*m_file);
//        QUrl url("ftp://nikifor.ucoz.net/img/" + fileInfo.fileName());
        QUrl url("ftp://nikifor.ucoz.net/img/3_photo.jpg");
        url.setUserName("enikifor");    // Set login
        url.setPassword("student511"); // Set пароль
        url.setPort(21);             // Protocol port, which we will work on

        if (m_file->open(QIODevice::ReadOnly))
        {
            // Start upload
            //QNetworkReply *reply = m_manager->put(QNetworkRequest(url), m_file);
            QNetworkReply *reply = m_manager->get(QNetworkRequest(url));
            qDebug() << reply->readAll();

            // And connect to the progress upload signal
            connect(reply, &QNetworkReply::uploadProgress, this, &EditPatientDialog::uploadProgress);
        }
    }
}

void EditPatientDialog::uploadFinished(QNetworkReply *reply)
{
    // If the upload was successful without errors
    if (!reply->error())
    {
        // то закрываем файл
        m_file->close();
        m_file->deleteLater();  // delete object of file
        reply->deleteLater();   // delete object of reply
    }
}

void EditPatientDialog::uploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    // Display the progress of the upload
    ui->progressBar->setValue(100 * bytesSent/bytesTotal);
}
