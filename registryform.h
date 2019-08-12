#ifndef REGISTRYFORM_H
#define REGISTRYFORM_H

#include <QWidget>
#include "db_adapter.h"
#include "makeanappointmentdialog.h"
#include "opendiseasedialog.h"

namespace Ui {
class RegistryForm;
}

class RegistryForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegistryForm(QWidget *parent = nullptr);
    ~RegistryForm();

private slots:

    void on_SearchPatientPushButton_clicked();

    void on_AddPatientPushButton_clicked();

    void on_OpenDiseasePushButton_clicked();

    void on_AddVisitPushButton_clicked();

private:
    Ui::RegistryForm *ui;
};

#endif // REGISTRYFORM_H
