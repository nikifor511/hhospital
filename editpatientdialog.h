#ifndef EDITPATIENTDIALOG_H
#define EDITPATIENTDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "db_adapter.h"

namespace Ui {
class EditPatientDialog;
}

class EditPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditPatientDialog(QWidget *parent = nullptr, int id_patient = 0);
    ~EditPatientDialog();

private slots:
    void on_ChoosePhotoButton_clicked();

    void on_UploadPhotoButton_clicked();

    void uploadFinished(QNetworkReply *reply);  // Upload finish slot
    void uploadProgress(qint64 bytesSent, qint64 bytesTotal);  // Upload progress slot

private:
    Ui::EditPatientDialog *ui;
    QNetworkAccessManager *m_manager;
    QString m_fileName;
    QFile *m_file;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmap_item;
    int id_patient;



};

#endif // ADDPATIENTDIALOG_H
