#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QTcpSocket>
#include<QDebug>
#include<queue>
#include"global.h"

#include"user.h"
using namespace std;

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int id, QObject *parent = 0);
    void run();
    void addToWrite(QByteArray str);
signals:
    void error(QTcpSocket::SocketError socketerror);
public slots:
    void readyRead();
    void disconnected();

private:
    void write(QByteArray str);
    QTcpSocket *socket;
    int socketDescriptor;
    queue<QByteArray> pendingData;
    User *user;


};

#endif // MYTHREAD_H
