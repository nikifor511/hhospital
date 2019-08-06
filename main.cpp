#include "mainwindow.h"
#include <QApplication>

//#include "db_adapter.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    DB_Adapter* dba = new DB_Adapter();
//    dba->query("select * from patients");

    return a.exec();
}
