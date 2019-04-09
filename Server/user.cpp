#include "user.h"
#include<iostream>
#include <QDir>

User::User(QObject *parent) : QObject(parent)
{
    validity=false;
}

void User::setLoginDetails(string id, string password) //sets the required username and password
{
    username=id;
    this->password=password;
}
void User::update(QTcpSocket *socket)                 //updates messages and friend lists.
{
    while(pendingFriends.size())
    {
        socket->write(pendingFriends.front().c_str());
        socket->flush();
        pendingFriends.pop();
        socket->waitForReadyRead(1000);
       // socket->readAll();
    }

    while(pendingMessages.size())
    {
        //std::cout<<pendingMessages.front()<<std::endl;
        socket->write(pendingMessages.front().c_str());
        socket->flush();
        pendingMessages.pop();
        socket->waitForReadyRead(1000);
        //socket->readAll();
    }
}

bool User::login(string password)                     //allows log in if password matches
{
    if(this->password==password)
    {
        validity=true;
    }
    return validity;
}

bool User::isFriend(std::string fid)
{
    string format="friend--";
    format+= '['+fid+']';
    return find(friends.begin(),friends.end(),format)!=friends.end();
}

void User::addMessage(string sender,string receiver, string message,bool old) //adds a message to the message que. After automation this might no longer be required
{
    string format ="message-["+sender+"]["+receiver+"]["+message+"]";

     //std::cout<<format<<std::endl;
    messages.push_back(format);
    if (old==false) //if this is a new message only then this message needs to be sent to the client
    {
        pendingMessages.push(format);
        emit needUpdate();
    }
}

void User::addFriend(string id,bool old)                        //adds a friend to the friend que
{

    string format="friend--";
    format+= '['+id+']';
    friends.push_back(format);

    if(!old)
    {
        pendingFriends.push(format);
        emit needUpdate();
    }
}

bool User::isValid()                                   //returns wheather user is logged in or not
{
    return validity;
}

string User::getID()                                    //returns the user name
{
    return username;
}

void User::logOut()
{
    validity=false;
}

void User::initData(QTcpSocket *socket)
{
    for(auto i:messages)
    {
        socket->write(i.c_str());
        socket->flush();
        socket->waitForReadyRead(-1);
        socket->readAll();
    }
    for(auto i:friends)
    {
        socket->write(i.c_str());
        socket->flush();
        socket->waitForReadyRead(-1);
        socket->readAll();
    }
}

QString User::getFolderPath()
{
    return folder;
}
void User::setFolderPath(QString usr)
{
    QDir dir;
    folder = "C:/ConnectServer/"+usr;
    if(dir.mkdir(folder)==false)                       //Creating users repository for uploaded files;
        std::cout<<"Cannot create new directory\n";
}
void User::setUploadStatus(bool stat)
{
    uploadstat=stat;
    return;
}
bool User::getUploadStatus()
{
    return uploadstat;
}
