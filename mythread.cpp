#include "mythread.h"
#include<iostream>

//constructor
MyThread::MyThread(int id, QObject *parent):
    QThread (parent)
{
    this->socketDescriptor=id;
    user=nullptr;

}

//connects to the socket of anything that wants to connect to the server
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

    exec();

}

void MyThread::readyRead()
{
    QByteArray  data = socket->readAll();
    string command;

    //the first 8 chars of the incomming data from client represents the request command. The for loop extracts that.
    command=data.toStdString().substr(0,8); //login---[user][pass]
                                            //^       ^ start point(0) to size of substring string(8)


    //login--- is a 8 char long command that handles login request
    //if user !=nullptr it means that the user is already logged in
    if(command=="login---" && user==nullptr)
    {
        string user;
        string pass;
        bool loginFlag=false;

        size_t start=data.toStdString().find_first_of('['); //login---[user][pass]
                                                           //         ^

        size_t end=data.toStdString().find_first_of(']');//login---[user][pass]
                                                        //              ^

        size_t last=data.toStdString().find_last_of(']');//login---[user][pass]
                                                         //                   ^

        //gets username and password from the string whose format is login---[username][password]
        if(start!=string::npos&&end!=string::npos&&last!=string::npos) //if any index was not found format was incorrect.
        {
            user=data.toStdString().substr(start+1,end-start-1);  // start from index('[')+1 and size of sub str will index('[')-index-1
            pass=data.toStdString().substr(end+2,last-end-2);     // start from index(']')+2 cuz "][" and size of sub str will be index(']')-index-2

            if(global::users.find(user)!=global::users.end())     //checks if username exists
            {
                if(global::users[user]->login(pass))              //checks if the password matches
                {
                    this->user=global::users[user];
                    connect(this->user,SIGNAL(needUpdate()),this,SLOT(updateUser())); //if this->user recieved anything updateUser() will be called
                    loginFlag=true;
                }
            }

        }

        loginFlag?write("loginT--"):write("loginF--"); //tells the client wheather login is true or false

    }


    //NOTE if user==nullptr it means no one is logged in. so next commands wont be accepted.
    else if(user!=nullptr&&command=="message-") //handles incoming messages if the first 8 char code is message-
    {   
        size_t start=data.toStdString().find_first_of('['); //message-[user][mesg]
                                                           //         ^

        size_t end=data.toStdString().find_first_of(']');//message-[user][mesg]
                                                        //              ^

        size_t last=data.toStdString().find_last_of(']');//message-[user][msg]
                                                         //                  ^

        if(start!=string::npos && end!=string::npos && last !=string::npos)
        {
            string message;
            string recipent;
            //deciphers username of person to whom the message will be sent, and the message it self
            //the format is message-[username of recipent][message] eg message-[r17v1]["hello"]

            recipent=data.toStdString().substr(start+1,end-start-1);//start from index('[')+1 and size of sub str will index('[')-index-1
            message=data.toStdString().substr(end+2,last-end-2);    //start from index(']')+2 cuz "][" and size of sub str will be index(']')-index-2


            //adds a new message to both users lists. Also lets them know who the sender is and who will recieve, and that this is not an old message
            global::users[recipent]->addMessage(this->user->getID(),"me",message,false);
            this->user->addMessage("me",recipent,message,false);

            Database::sqlQuerry( "insert into message values(\'"+this->user->getID()+"\', \'"+recipent +"\', \'"+message+"\');");



        }

    }


    else if(user!=nullptr&&command=="update--") //update command, probably will be automated and removed later. If the client wants
                                                //to update its incoming messages or new friends, the client sends the request update--
    {
        this->user->update(socket);
    }



    else if(user!=nullptr&&command=="initdata")//sends initial infos(old messages,friend list etc) to client
    {
        user->initData(socket);
    }


    qDebug()<<socketDescriptor<<" Data in: "<< data;

}

void MyThread::disconnected()
{
    qDebug()<<socketDescriptor<<" Client disconnected";
    if(user!=nullptr)
    {
        user->logOut();
        user=nullptr;
    }
    socket->deleteLater();
    exit(0);
}

void MyThread::write(QByteArray str) //sends the user data (str)
{
    socket->write(str);
    socket->flush();
}



void MyThread::updateUser()
{
    user->update(socket);
}
