#include "mythread.h"
#include<iostream>

MyThread::MyThread(int id, QObject *parent):
    QThread (parent)
{
    this->socketDescriptor=id;
    user=NULL;

}

void MyThread::run()
{
    qDebug()<<socketDescriptor<<" Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug()<<socketDescriptor<<" Client connected";
    //socket->write("message-[r17v1][lol]");
    socket->waitForBytesWritten(3000);

    exec();

}

void MyThread::readyRead()
{
    QByteArray  data = socket->readAll();

    string command;
    for(int i=0;i<8;i++)
        command.push_back(data[i]);
    string request=data.toStdString();



    if(command=="login---")
    {
        cout<<request<<endl;

        string user;
        string pass;

        for(int i=request.find_first_of('[')+1;i<request.size()&& request[i]!=']';i++)
        {
            user.push_back(request[i]);
        }
        for(int i=request.find_last_of('[')+1;i<request.size()&& request[i]!=']';i++)
        {
            pass.push_back(request[i]);
        }

        //cout <<"u:"<< user<<" "<<pass<<endl;

        if(global::users[user]->login(pass))
        {
            write("Success!");
            this->user=global::users[user];
        }
        else write("Failed!");
    }
    else if(user->isValid()&&command=="message-")
    {
        int i;
        string message;
        string recipent;
        for(i=request.find_first_of('[')+1;request[i]!=']';i++)
        {
            recipent.push_back(request[i]);
        }

        int last=request.find_last_of(']');

        i++;
        i++;
        for(;i<last;i++)
        {
            message.push_back(request[i]);
        }

        cout<<recipent<<message<<endl;

        global::users[recipent]->addMessage(this->user->getID(),message);
    }
    else if(user->isValid()&&command=="update--")
    {
        this->user->update(socket);
    }
    else if(user->isValid()&&command=="initdata")
    {

    }


    qDebug()<<socketDescriptor<<" Data in: "<< data;

    while(pendingData.size()>0)
    {
        write(pendingData.front());
        pendingData.pop();
    }


}

void MyThread::disconnected()
{
    qDebug()<<socketDescriptor<<" Client disconnected";
    socket->deleteLater();
    exit(0);
}

void MyThread::write(QByteArray str)
{
    socket->write(str);
    socket->waitForBytesWritten(1000);
}

void MyThread::addToWrite(QByteArray str)
{
    pendingData.push(str);
}
