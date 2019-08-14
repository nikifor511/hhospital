#include "db_adapter.h"

DB_Adapter::DB_Adapter()
{

}

QSqlQuery DB_Adapter::query(QString query_str)
{
    QSqlDatabase my_db = QSqlDatabase::addDatabase("QPSQL");
    my_db.setHostName("ec2-54-247-189-1.eu-west-1.compute.amazonaws.com");
    my_db.setPort(5432);
    my_db.setDatabaseName("dcpfkt2qs5euq2");
    my_db.setUserName("cmacmnazbqrjzn");
    my_db.setPassword("e17043de401bf4e7a84d5c538641c68c37769d817c7337238d778feb754998ee");
    if (my_db.open())
       {
          qDebug() << query_str;
       }
    QSqlQuery sql_query(query_str);
    my_db.close();
    return sql_query;
}
