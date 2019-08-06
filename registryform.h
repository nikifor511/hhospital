#ifndef REGISTRYFORM_H
#define REGISTRYFORM_H

#include <QWidget>

namespace Ui {
class RegistryForm;
}

class RegistryForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegistryForm(QWidget *parent = nullptr);
    ~RegistryForm();

private:
    Ui::RegistryForm *ui;
};

#endif // REGISTRYFORM_H
