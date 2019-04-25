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
    MySocket(QObject *parent=nullptr);
    bool doConnect();
    ~MySocket();
    QByteArray socketRead();
    void socketWrite(QByteArray data);
    void wrr(int i);
    bool isconnected();


signals:
    void login(bool);
    void signup(bool);
    void newFriend(QString);
    void newMsg(QString);
    void fileUpload();
    void fileUpStatus(bool);
    void connectionLost();
    void fileSize(qint64);
    void filedata(QByteArray);
    void newFile(QString);

public slots:
    void readyRead();
    void disconnected();



private:
    QTcpSocket *socket;
    bool state;
};


#endif // MYSOCKET_H
