#include "database.h"
#include<iostream>

Database::Database(QObject *parent) : QObject(parent)
{
}

void Database::addUsers()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("F:/ServerFiles/accounts.db");
    if(!db.open())qDebug()<<"Failed to connect to database!";
    QSqlQuery query;
    string command="select * from login";
    query.exec(command.c_str());

    while(query.next())
    {
        User *u=new User;
        u->setLoginDetails(query.value(0).toString().toStdString(),query.value(1).toString().toStdString());
        global::users[query.value(0).toString().toStdString()]=u;
    }
    db.close();
}


void Database::printUsers()
{
    for(auto i:global::users )
    {
        std::cout<<i.first<<std::endl;
    }
}

