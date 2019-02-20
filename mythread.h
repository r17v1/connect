//MANAGES THREADS See .cpp file for detailed info
#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QTcpSocket>
#include<QDebug>
#include<queue>
#include"global.h"
#include"database.h"

#include"user.h"
using namespace std;

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int id, QObject *parent = 0);
    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);
public slots:
    void readyRead(); //handles incoming data inside this. So requests from the client gets resolved here.
    void updateUser();//updates user pending stuff (messages/friends)

    void disconnected();

private:
    void write(QByteArray str);
    QTcpSocket *socket;  //socket pointing to the client connected to this thread
    int socketDescriptor;
    User *user; //after log in whis will point to the user who's socket is connected to this thread.


};

#endif // MYTHREAD_H
