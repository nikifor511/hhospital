#ifndef OPENDISEASEDIALOG_H
#define OPENDISEASEDIALOG_H

#include <QDialog>
#include "db_adapter.h"

namespace Ui {
class OpenDiseaseDialog;
}

class OpenDiseaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDiseaseDialog(QWidget *parent = nullptr, int id_patient = 0);
    ~OpenDiseaseDialog();

private slots:

    void on_FIODoctorComboBox_currentIndexChanged(int index);

    void on_CancelPushButton_clicked();

    void on_OpenDiseasePushButton_clicked();

private:
    Ui::OpenDiseaseDialog *ui;
};

#endif // OPENDISEASEDIALOG_H
