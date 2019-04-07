#include "mysocket.h"

MySocket::MySocket()
{
    socket = new QTcpSocket;
}

MySocket::~MySocket()
{
    socket->close();
}
bool MySocket::doConnect()
{
    socket->connectToHost("192.168.1.150",1234);
    if(socket->waitForConnected(10000))
        return true;
    else  return false;
}
QByteArray MySocket::socketRead()
{
    socket->waitForReadyRead(1000);
    QByteArray data=socket->readAll();
    socket->flush();
    return data;
}

void MySocket::socketWrite(QByteArray data)
{
    socket->write(data);
    socket->waitForBytesWritten(-1);
    socket->flush();
}
