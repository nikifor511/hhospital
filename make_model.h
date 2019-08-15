#ifndef MAKE_MODEL_H
#define MAKE_MODEL_H

#include "QStandardItemModel"
#include "db_adapter.h"


class Make_Model
{
public:
    Make_Model();
    static QStandardItemModel *fill(QString sql_str);


};

#endif // MAKE_MODEL_H
