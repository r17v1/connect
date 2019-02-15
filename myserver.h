#ifndef MYSERVER_H
#define MYSERVER_H
#include<QTcpServer>
#include "mythread.h"
#include "global.h"
#include "database.h"
#include<list>
using namespace std;

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent=0);

    void startServer();

    void updateThreads();

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

    list<MyThread*>threads;


};

#endif // MYSERVER_H
