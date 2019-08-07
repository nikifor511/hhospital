#ifndef MAKEANAPPOINTMENTDIALOG_H
#define MAKEANAPPOINTMENTDIALOG_H

#include <QDialog>
#include "db_adapter.h"

namespace Ui {
class MakeAnAppointmentDialog;
}

class MakeAnAppointmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MakeAnAppointmentDialog(QWidget *parent = nullptr, int id_patient = 0);
    ~MakeAnAppointmentDialog();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MakeAnAppointmentDialog *ui;
};

#endif // MAKEANAPPOINTMENTDIALOG_H
