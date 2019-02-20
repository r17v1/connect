#include "database.h"
#include<iostream>

Database::Database(QObject *parent) : QObject(parent)
{
}

void Database::initialize()
{
    loadUsers();
    loadFriends();
    loadMessages();
    printUsers();
}
void Database::loadUsers()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  //database witth SQLITE driver
    db.setDatabaseName("F:/ServerFiles/accounts.db");        //path to the .db file that will hold all informations
    if(!db.open())qDebug()<<"Failed to connect to database!";//opens the database
    QSqlQuery query;
    string command="select * from login";                   //querry
    query.exec(command.c_str());                            //executes the querry

    while(query.next())                                    //fetches all the results 1 by 1
    {
        User *u=new User;
        u->setLoginDetails(query.value(0).toString().toStdString(),query.value(1).toString().toStdString());
        global::users[query.value(0).toString().toStdString()]=u;
    }
    db.close();                                            //closes the database
}

void Database::loadFriends()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  //database witth SQLITE driver
    db.setDatabaseName("F:/ServerFiles/accounts.db");        //path to the .db file that will hold all informations
    if(!db.open())qDebug()<<"Failed to connect to database!";//opens the database
    QSqlQuery query;
    string command="select * from friendlist";                   //querry
    query.exec(command.c_str());                            //executes the querry

    while(query.next())                                    //fetches all the results 1 by 1
    {
        //adds the other person as friend to both user's list and tells the function that this is an old friend
        global::users[query.value(0).toString().toStdString()]->addFriend(query.value(1).toString().toStdString(),true);
        global::users[query.value(1).toString().toStdString()]->addFriend(query.value(0).toString().toStdString(),true);
    }
    db.close();                                            //closes the database
}

void Database::loadMessages()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  //database witth SQLITE driver
    db.setDatabaseName("F:/ServerFiles/accounts.db");        //path to the .db file that will hold all informations
    if(!db.open())qDebug()<<"Failed to connect to database!";//opens the database
    QSqlQuery query;
    string command="select * from message";                   //querry
    query.exec(command.c_str());                            //executes the querry

    while(query.next())                                    //fetches all the results 1 by 1
    {
        string sender   =   query.value(0).toString().toStdString();
        string receiver =   query.value(1).toString().toStdString();
        string message  =   query.value(2).toString().toStdString();

        //adds message to both users list and lets them know who the sender/receiver is and lets the function know that this is an old message.
        global::users[sender]->addMessage("me",receiver,message,true);
        global::users[receiver]->addMessage(sender,"me",message,true);
    }
    db.close();                                            //closes the database
}



void Database::sqlQuerry(string q)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  //database witth SQLITE driver
    db.setDatabaseName("F:/ServerFiles/accounts.db");        //path to the .db file that will hold all informations
    if(!db.open())qDebug()<<"Failed to connect to database!";//opens the database
    QSqlQuery query;
    query.exec(q.c_str());
    db.commit();
    db.close();

}


void Database::printUsers()                                //prints all users
{
    for(auto i:global::users )
    {
        std::cout<<i.first<<std::endl;
    }
}

