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
    qDebug() <<data.size();

    //the first 8 chars of the incomming data from client represents the request command. The for loop extracts that.
    command=data.toStdString().substr(0,8); //login---[user][pass]
                                            //^       ^ start point(0) to size of substring string(8)


    //login--- is a 8 char long command that handles login request
    //if user !=nullptr it means that the user is already logged in
    if(command=="login---" && user==nullptr)
    {
        QString cmd(data), usr;
        int i=cmd.indexOf('[')+1;
        int k=cmd.indexOf(']');
        usr=cmd.mid(i,k-i);
        qDebug() << usr;

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
                    this->user->setUploadStatus(false);
                    this->user->setFolderPath(usr);
                    loginFlag=true;
                }
            }

        }

        loginFlag?write("loginT--"):write("loginF--"); //tells the client wheather login is true or false

    }

    if(command=="signup--" && user==nullptr)
    {
        QString cmd(data), usr;
        int i=cmd.indexOf('[')+1;
        int k=cmd.indexOf(']');
        usr=cmd.mid(i,k-i);
        qDebug() << usr;

        string user;
        string pass;
        bool signupFlag=false;

        size_t start=data.toStdString().find_first_of('['); //signup--[user][pass]
                                                           //         ^

        size_t end=data.toStdString().find_first_of(']');//signup--[user][pass]
                                                        //              ^

        size_t last=data.toStdString().find_last_of(']');//signup--[user][pass]
                                                         //                   ^

        //gets username and password from the string whose format is signup--[username][password]
        if(start!=string::npos&&end!=string::npos&&last!=string::npos) //if any index was not found format was incorrect.
        {
            user=data.toStdString().substr(start+1,end-start-1);  // start from index('[')+1 and size of sub str will index('[')-index-1
            pass=data.toStdString().substr(end+2,last-end-2);     // start from index(']')+2 cuz "][" and size of sub str will be index(']')-index-2

            if(global::users.find(user)==global::users.end())     //checks if username exists
            {
                if(user!="me" && user.size()>0 && pass.size()>0)
                {
                    Database::sqlQuerry("insert into login values(\'"+user+"\' , \'"+pass+"\');");
                    User *nuser=new User;
                    nuser->setLoginDetails(user,pass);
                    nuser->setFolderPath(usr);
                    global::users[user]=nuser;
                    signupFlag=true;
                }
            }

        }

        signupFlag?write("signupT-"):write("signupF-"); //tells the client wheather signup is true or false

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
            Database::sqlQuerry( "insert into message values(\'"+this->user->getID()+"\', \'"+recipent +"\', \'"+message+"\');");

            //adds a new message to both users lists. Also lets them know who the sender is and who will recieve, and that this is not an old message
            this->user->addMessage("me",recipent,message,false);
            global::users[recipent]->addMessage(this->user->getID(),"me",message,false);






        }

        write("ok------");

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

    //File receiving from User; format = "download[filename][filesize][receiver]"
    else if(user!=nullptr&&command=="download"&&user->getUploadStatus()==false)
    {
        file = new FileReceiver;
        filesync=0;
        user->setUploadStatus(true);
        QString cmd(data) , filename, filesize;
        int i=cmd.indexOf('[')+1;
        int k=cmd.indexOf(']');
        filename=cmd.mid(i,k-i);
        qDebug() << filename;

        k+=2;
        i=cmd.indexOf(']',k);
        filesize = cmd.mid(k,i-k);
        qDebug() << filesize;


        bool ok;
        file->setFilePath(filename,user->getFolderPath(), filesize.toLongLong(&ok,10));           //set user folder path for storing file;
        socket->write("upload--");
        socket->flush();


    }
    else if(user!=nullptr&&command=="endofile"&&user->getUploadStatus()==true)
    {
        if(file->checkHealthCloseFile())
        {
            socket->write("dwnloded");
            socket->flush();
            qDebug() <<"file uploaded";
        }
        else {
            socket->write("dwnlodff");
            socket->flush();
            qDebug() <<"file not uploaded";
        }
        user->setUploadStatus(false);
    }
    else if(user!=nullptr&&user->getUploadStatus()==true)
    {
        QString cmd(data);
        bool ok;
        int i=cmd.indexOf('[')+1;
        int k=cmd.indexOf(']');
        long long sz=cmd.mid(i,k-i).toLongLong(&ok,10);
        data.remove(0,k-i+2);
        qDebug()<<data.size()<<" "<<sz;

        file->fileWrite(data);
        if(data.size()<sz)
            filesync+=data.size();
        if(filesync==sz||data.size()==sz)
        {
            filesync=0;
            socket->write("upload--");
            socket->flush();
        }
    }
    else if (user!=nullptr&&command=="addfrnd-")//adds contact, format addfrnd-[username]
    {
        size_t start=data.toStdString().find_first_of('[');
        size_t end=data.toStdString().find_last_of(']');
        std::string username=data.toStdString().substr(start+1,end-start-1);

        if(global::users.find(username)!=global::users.end())
        {
            if(this->user->isFriend(username)==false)
            {
                user->addFriend(username);
                global::users[username]->addFriend(user->getID());
                Database::sqlQuerry("insert into friendlist values (\'"+user->getID()+"\', \'"+username+"\');");

                write("addfrndT");
            }
            else write("addfrndF");
        }
        else write("addfrndF");


    }


//    else
//    {
//        write("invalid-");
//    }

//    qDebug()<<socketDescriptor<<" Data in: "<< data;

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
