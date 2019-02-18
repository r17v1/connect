//USER CLASS THAT CONTAINS INFO OF USERS
#ifndef USER_H
#define USER_H

#include <QObject>
#include<list>
#include<queue>
#include<QTcpSocket>
using namespace std;

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    void addFriend(string id);
    void addMessage(string sender,string message);      //adda a message to pending which will later get sent
    bool isValid();                                     //shows wheather a user is logged in or not
    bool isFriend(string fid);
    bool login(string password);                        //checks and logs in an user
    void setLoginDetails(string id, string password);   //sets username and password to check
    void update(QTcpSocket *socket);                    //updates pending stuff (messages, friends etc)
    string getID();                                     //returns user id
    void logOut();

signals:
    void needUpdate();

public slots:

private:
    string username;
    string password;
    bool validity;                      //wheather a user is logged in or not.
    list<string> messages;              //All messages
    queue<string> pendingMessages;      //new not yet sent messages
    list<string> friends;               //All friends
    queue<string>pendingFriends;        //new, not yet sent to client friends


};

#endif // USER_H
