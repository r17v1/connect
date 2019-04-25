#include "mysocket.h"

extern MySocket *exsocket;

MySocket::MySocket(QObject *parent):QObject (parent)
{
    socket = new QTcpSocket;
    state = false;
     connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
     connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
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
    socket->connectToHost("192.168.1.150",1234);
    if(socket->waitForConnected(1000))
    {
        state=true;
        return true;
    }
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
    //qDebug()<<data;

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
    else if(data.mid(0,8)=="file----")
        emit newFile(data);
    else if(data.mid(0,8)=="upload--")
        emit fileUpload();
    else if(data.mid(0,8)=="dwnloded")
        emit fileUpStatus(true);
    else if(data.mid(0,8)=="dwnlodff")
        emit fileUpStatus(false);
    else if(data.mid(0,8)=="filesize")
    {
        data.remove(0,8);
        QString cmd(data);
        bool ok;
        emit fileSize(cmd.toLongLong(&ok,10));
    }
    else if(data.mid(0,8)=="endofile")
        emit fileUpStatus(true);
    else
        emit filedata(data);

}


void MySocket::disconnected()
{
    state=false;
    emit connectionLost();
}

void MySocket::socketWrite(QByteArray data)
{
    socket->write(data);
    socket->waitForBytesWritten(-1);
    socket->flush();
}

bool MySocket::isconnected()
{
    return state;
}
