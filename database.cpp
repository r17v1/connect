#include "database.h"
#include<iostream>

Database::Database(QObject *parent) : QObject(parent)
{
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


void Database::printUsers()                                //prints all users
{
    for(auto i:global::users )
    {
        std::cout<<i.first<<std::endl;
    }
}

