#include "ftp_adapter.h"

#include<QCoreApplication>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QFile>

FTP_Adapter::FTP_Adapter()
{

}

void FTP_Adapter::GetFile(QString str, QString out)
{
    QUrl                     url(str);
     QNetworkAccessManager    manager(0);
     QNetworkReply *          reply =  manager.get(QNetworkRequest(url));
     QEventLoop               loop;

     QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
     loop.exec();

     QFile                    file(out);
     file.open(QIODevice::WriteOnly);
     file.write(reply->readAll());
     delete reply;
     return;
}
