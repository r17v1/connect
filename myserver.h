//STARTS THE SERVER AND ACCEPS INCOMING CONNECTIONS See the .cpp file for more info
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

   // void updateThreads();

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // MYSERVER_H
