#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QMessageBox>
#include<QAbstractSocket>
#include<QDebug>

class MySocket: public QObject
{
    Q_OBJECT

public:
    MySocket(QObject *parent=0);
    bool doConnect();
    ~MySocket();
    QByteArray socketRead();
    void socketWrite(QByteArray data);
    void wrr(int i);


signals:
    void login(bool);
    void signup(bool);
    void newFriend(QString);
    void newMsg(QString);
    void fileUpload();
    void fileUpStatus(bool);

public slots:
    void readyRead();



private:
    QTcpSocket *socket;
};


#endif // MYSOCKET_H
