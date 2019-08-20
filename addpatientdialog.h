#ifndef ADDPATIENTDIALOG_H
#define ADDPATIENTDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>

namespace Ui {
class AddPatientDialog;
}

class AddPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPatientDialog(QWidget *parent = nullptr);
    ~AddPatientDialog();

private slots:
    void on_ChoosePhotoButton_clicked();

private:
    Ui::AddPatientDialog *ui;
    QNetworkAccessManager *m_manager;
    QString m_fileName;
    QFile *m_file;
};

#endif // ADDPATIENTDIALOG_H
