#ifndef FRIENDWINDOW_H
#define FRIENDWINDOW_H

#include <QMainWindow>
#include <chatbox.h>
#include<vector>
#include<map>

namespace Ui {
class FriendWindow;
}

class FriendWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FriendWindow(QWidget *parent = nullptr);
    ~FriendWindow();
   void  addFriend(QString username);
   void setLabels();

private slots:

   void onNewFriend(QString id);
    void on_pushButton_clicked();

    void on_groupBox_objectNameChanged(const QString &objectName);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_AddFriendButton_clicked();

    void onNewChat(QString data);

private:
    Ui::FriendWindow *ui;
    int j=0;
    std::vector<QString>friends;
    std::map<QString,std::vector<QString> > chats;


};

#endif // MAINWINDOW_H
