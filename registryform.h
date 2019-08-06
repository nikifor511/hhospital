#ifndef REGISTRYFORM_H
#define REGISTRYFORM_H

#include <QWidget>
#include "db_adapter.h"

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
    void on_pushButton_clicked();

private:
    Ui::RegistryForm *ui;
};

#endif // REGISTRYFORM_H
