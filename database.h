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
    //bool validate(string user, string password );
    static void addUsers();
    static void printUsers();

signals:

public slots:


private:

};

#endif // DATABASE_H
