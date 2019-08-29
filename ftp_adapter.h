#ifndef FTP_ADAPTER_H
#define FTP_ADAPTER_H

#include <QString>

class FTP_Adapter
{
public:
    FTP_Adapter();
    static void GetFile(QString str, QString out);
};

#endif // FTP_ADAPTER_H
