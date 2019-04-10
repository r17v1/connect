#include "mysocket.h"

extern MySocket *exsocket;

MySocket::MySocket(QObject *parent):QObject (parent)
{
    socket = new QTcpSocket;
     connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

MySocket::~MySocket()
{

    socket->close();
}
void MySocket::wrr(int i)
{
    socket->waitForReadyRead(i);
}

bool MySocket::doConnect()
{
    socket->connectToHost("localhost",1234);
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

void MySocket::readyRead()
{

    QByteArray data=socket->readAll();
     qDebug()<<data;

    if(data.mid(0,8)=="loginT--")
            emit login(true);

    else if(data.mid(0,8)=="loginF--")
        emit login(false);

    else if(data.mid(0,8)=="signupT-")
            emit signup(true);
    else if(data.mid(0,8)=="signupF-")
            emit signup(false);

    else if(data.mid(0,8)=="friend--")
    { emit newFriend(data.mid(9,data.size()-10));
        qDebug()<<"on data";
        socketWrite("ok");
    }
    else if(data.mid(0,8)=="message-")
    {
      emit newMsg(data);

        //qDebug()<<"on msg";
        socketWrite("ok");
    }
    else if(data.mid(0,8)=="upload--")
        emit fileUpload();
    else if(data.mid(0,8)=="dwnloded")
        emit fileUpStatus(true);
    else if(data.mid(0,8)=="dwnlodff")
        emit fileUpStatus(false);

}




void MySocket::socketWrite(QByteArray data)
{
    socket->write(data);
    socket->waitForBytesWritten(-1);
    socket->flush();
}
