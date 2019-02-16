#include "myserver.h"

MyServer::MyServer(QObject *parent):
    QTcpServer (parent)
{

}

void MyServer::startServer()
{
    Database::loadUsers();   //at the start of the server, all users added to the database(online or offline both) are loaded to the map.
    Database::printUsers(); //and then their usernames are printed for convenience.

    if(!this->listen(QHostAddress::Any,1234))   //Allows connection of anything that wants to connect to port 1234
        qDebug()<<"Could not start server!";
    else {
        qDebug()<<"Listening...";
    }
}

void MyServer::incomingConnection(qintptr socketDescriptor) //connects any incoming connection and creates a new thread for each of them
{
    qDebug()<< socketDescriptor<<" is connecting...";

    MyThread *thread= new MyThread(socketDescriptor,this);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}


