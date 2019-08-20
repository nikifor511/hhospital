#ifndef EDITPATIENTDIALOG_H
#define EDITPATIENTDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsItem>


namespace Ui {
class EditPatientDialog;
}

class EditPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditPatientDialog(QWidget *parent = nullptr, bool isEdit = true);
    ~EditPatientDialog();

private slots:
    void on_ChoosePhotoButton_clicked();

private:
    Ui::EditPatientDialog *ui;
    QNetworkAccessManager *m_manager;
    QString m_fileName;
    QFile *m_file;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmap_item;
    bool isEdit;


};

#endif // ADDPATIENTDIALOG_H
