#ifndef USER_H
#define USER_H

#include <QObject>
#include<list>
#include<queue>
//#include"database.h"
#include<QTcpSocket>
using namespace std;

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    void addFriend(string id);
    void addMessage(string sender,string message);
    bool isValid();
    bool isFriend(string fid);
    bool login(string password);
    void setLoginDetails(string id, string password);
    void update(QTcpSocket *socket);
    string getID();

signals:

public slots:

private:
    string username;
    string password;
    bool validity;
    list<string> messages;
    queue<string> pendingMessages;
    list<string> friends;
    queue<string>pendingFriends;
   // Database db;

};

#endif // USER_H
