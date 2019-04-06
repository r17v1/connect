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
    void addFriend(string id, bool old=false);      //adds a friend to friends list. If old=0 i.e. new friend adds to pendingFriends and sends
    void addMessage(string sender,string receiver,string message,bool old=false); //adds a message to message list. If old=0 i.e. new message adds to pendingMessages and sends
    bool isValid();                                     //shows wheather a user is logged in or not
    bool isFriend(string fid);
    bool login(string password);                        //checks and logs in an user
    void setLoginDetails(string id, string password);   //sets username and password to check
    void update(QTcpSocket *socket);                    //updates pending stuff (messages, friends etc)
    void initData(QTcpSocket *socket);                  //sends old message/friend list etc to client
    string getID();                                     //returns user id
    QString getFolderPath();
    void setFolderPath(QString usr);
    void setUploadStatus(bool stat);
    bool getUploadStatus();
    void logOut();

signals:
    void needUpdate();

public slots:

private:
    string username;
    string password;
    QString folder;                      //Personal repository path for every user where uploaded files will be saved;
    bool uploadstat;                     //currently uploading;
    bool validity;                      //wheather a user is logged in or not.
    list<string> messages;              //All messages
    queue<string> pendingMessages;      //new not yet sent messages
    list<string> friends;               //All friends
    queue<string>pendingFriends;        //new, not yet sent to client friends


};

#endif // USER_H
