//THIS CLASS WILL PROBABLY ONLY CONTAIN STATIC FUNCTIONS THAT GETS DATABASE STUFF DONE
#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include<list>
#include<string>
#include<QtSql>
#include<QDebug>
#include "user.h"
#include "global.h"
using namespace std;

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    static void initialize();
    static void sqlQuerry(string q);

private:
    static void loadUsers();                             //loads all users from database to the users map
    static void loadMessages();
    static void loadFriends();

    static void printUsers();                           //prints all user names


signals:

public slots:




};

#endif // DATABASE_H
