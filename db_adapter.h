#ifndef DB_ADAPTER_H
#define DB_ADAPTER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>



class DB_Adapter
{
public:
    DB_Adapter();
    static void query(QString query_str);
};

#endif // DB_ADAPTER_H
