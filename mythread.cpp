#include "mythread.h"
#include<iostream>

MyThread::MyThread(int id, QObject *parent)://constructor
    QThread (parent)
{
    this->socketDescriptor=id;
    user=NULL;

}

void MyThread::run() //simply connects to the socket of anything that wants to connect to the server
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

    exec();

}

void MyThread::readyRead()
{
    QByteArray  data = socket->readAll();

    string command;
    for(int i=0;i<8;i++)                //the first 8 chars of the incomming string represents the command
        command.push_back(data[i]);
    string request=data.toStdString();



    if(command=="login---" && user==NULL)  //login--- is a 8 char long command that handles login request
    {
        cout<<request<<endl;

        string user;
        string pass;
        //the loops desipher username and password from the string whose format is login---[username][password]
        for(int i=request.find_first_of('[')+1;i<request.size()&& request[i]!=']';i++)
        {
            user.push_back(request[i]);
        }
        for(int i=request.find_last_of('[')+1;i<request.size()&& request[i]!=']';i++)
        {
            pass.push_back(request[i]);
        }

        //cout <<"u:"<< user<<" "<<pass<<endl;
        if(global::users.find(user)==global::users.end()) //checks if username exists
        {
            write("Failed!");
        }
        else if(global::users[user]->login(pass))       //checks if the password matches
        {
            write("Success!");
            this->user=global::users[user];
        }
        else write("Failed!");
    }


    //NOTE if user==NULL it means no one is logged in. so next commands wont be accepted.



    else if(user!=NULL&&command=="message-") //handles incoming messages if the first 8 char code is message-
    {
        int i;
        string message;
        string recipent;
        //deciphers username of person to whom the message will be sent, and the message it self
        //the format is message-[username of recipent][message] eg message-[r17v1]["hello"]
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

        global::users[recipent]->addMessage(this->user->getID(),message);//pends the message to the recipent's user class. and also tells
                                                                         //that class the username of who the sender is i.e. the username
                                                                         //of the person to whom this thread belongs to
    }






    else if(user!=NULL&&command=="update--") //update command, probably will be automated and removed later. Simply if the client wants
                                             //to update its incoming messages or new friends, the client sends the request update--
    {
        this->user->update(socket);
    }



    else if(user!=NULL&&command=="initdata")
    {

    }


    qDebug()<<socketDescriptor<<" Data in: "<< data;

}

void MyThread::disconnected()
{
    qDebug()<<socketDescriptor<<" Client disconnected";
    socket->deleteLater();
    exit(0);
}

void MyThread::write(QByteArray str) //sends the user data
{
    socket->write(str);
    socket->waitForBytesWritten(1000);
}


