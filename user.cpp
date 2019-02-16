#include "user.h"
#include<iostream>

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
        socket->waitForBytesWritten(1000);
        pendingFriends.pop();
    }

    while(pendingMessages.size())
    {
        //std::cout<<pendingMessages.front()<<std::endl;
        socket->write(pendingMessages.front().c_str());
        socket->waitForBytesWritten(3000);
        pendingMessages.pop();
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

void User::addMessage(string sender, string message) //adds a message to the message que. After automation this might no longer be required
{
    string format ="message-";
     format += "["+sender+"]";
     format +="["+message+"]";
     //std::cout<<format<<std::endl;
    messages.push_back(format);
    pendingMessages.push(format);
}

void User::addFriend(string id)                        //adds a friend to the friend que. After automation this might no longer be required
{

    string format="friend--";
    format+= '['+id+']';
    friends.push_back(format);
    pendingFriends.push(format);
}

bool User::isValid()                                   //returns wheather user is logged in or not
{
    return validity;
}

string User::getID()                                    //returns the user name
{
    return username;
}

