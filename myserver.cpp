#include "myserver.h"

MyServer::MyServer(QObject *parent):
    QTcpServer (parent)
{

}

void MyServer::startServer()
{
    Database::addUsers();
    Database::printUsers();

    if(!this->listen(QHostAddress::Any,1234))
        qDebug()<<"Could not start server!";
    else {
        qDebug()<<"Listening...";
    }
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<< socketDescriptor<<" is connecting...";

    MyThread *thread= new MyThread(socketDescriptor,this);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
//    threads.push_back(thread);
//    thread->addToWrite("hello");
}

void MyServer::updateThreads()
{

}
