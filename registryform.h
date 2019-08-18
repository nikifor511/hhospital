#ifndef REGISTRYFORM_H
#define REGISTRYFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include "db_adapter.h"
#include "makeanappointmentdialog.h"
#include "opendiseasedialog.h"
#include "make_model.h"

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

    void on_RegistryTableView_doubleClicked(const QModelIndex &index, const bool isBack);

    void on_BackPushButton_clicked();

private:
    Ui::RegistryForm *ui;
    int table_index;
    int tmp_id_patients, tmp_id_diseases;

};

#endif // REGISTRYFORM_H
