#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QMessageBox>

class MySocket
{
public:
    MySocket();
    bool doConnect();
    ~MySocket();
    QByteArray socketRead();
    void socketWrite(QByteArray data);


private:
    QTcpSocket *socket;
};

#endif // MYSOCKET_H
