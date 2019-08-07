#ifndef OPENDISEASEDIALOG_H
#define OPENDISEASEDIALOG_H

#include <QDialog>

namespace Ui {
class OpenDiseaseDialog;
}

class OpenDiseaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDiseaseDialog(QWidget *parent = nullptr);
    ~OpenDiseaseDialog();

private:
    Ui::OpenDiseaseDialog *ui;
};

#endif // OPENDISEASEDIALOG_H
