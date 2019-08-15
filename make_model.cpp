#include "make_model.h"

Make_Model::Make_Model()
{

}

QStandardItemModel *Make_Model::fill(QString sql_str)
{
    QSqlQuery res = DB_Adapter::query(sql_str);

    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;

    QStringList horizontalHeader;
    int i;

    QSqlRecord localRecord = res.record();
    for (i=0; i<localRecord.count(); ++i)
    {
        QString fieldName = localRecord.fieldName(i);
        qDebug() << fieldName;
        horizontalHeader.append(fieldName);
    }
    model->setHorizontalHeaderLabels(horizontalHeader);
    int curent_row = 0;
    while (res.next())
    {
        for (i=0; i<localRecord.count(); ++i)
        {
           item = new QStandardItem(QString(res.value(i).toString()));
           model->setItem(curent_row, i,item);
        }
        curent_row++;
    }
    return model;
}

