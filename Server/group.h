#ifndef GROUP_H
#define GROUP_H

#include <QObject>
#include<list>
#include<queue>
#include<QTcpSocket>

using namespace std;


class group : public QObject
{
    Q_OBJECT
public:
    explicit group(QObject *parent = nullptr);
    void addMember(string id,bool old=false);
    void update(QTcpSocket *socket);
    QString getFolderPath();
    void setFolderPath(QString usr);
    void setUploadStatus(bool stat);
    bool getUploadStatus();


signals:

public slots:

private:
    QString folder;
    bool uploadStatus;
    bool validity;
    list<string>mssg;
    list<string>members;
    queue<string>pendingMessage;
    queue<string>pendingMembers;
};

#endif // GROUP_H
