#include "friendwindow.h"
#include "ui_friendwindow.h"
#include<QDebug>
//int current_pos=0;
FriendWindow::FriendWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FriendWindow)
{
   connect(exsocket,SIGNAL(newFriend(QString)),this,SLOT(onNewFriend(QString)));
   connect(exsocket,SIGNAL(newMsg(QString)),this,SLOT(onNewChat(QString)));

    ui->setupUi(this);
    ui->groupBox->setTitle("Logged in as "+username);
    setLabels();
    ui->pushButton_6->setText("Next");
    if(j==0)ui->pushButton_7->setText("Welcome");
    else ui->pushButton_7->setText("Previous");

    exsocket->socketWrite("initdata");
}

void FriendWindow::setUsername(QString id)
{
    username=id;
}

void FriendWindow::onNewChat(QString data)
{

    QString sender;
    QString reciver;
    QString msg;
    qDebug()<<"Signal called";


    int i=9;

    for(;data[i]!=']';i++)
    {
        sender.push_back(data[i]);
    }
    i+=2;
    for(;data[i]!=']';i++)
    {
        reciver.push_back(data[i]);
    }
    qDebug()<<sender<<' '<<reciver;
    if(sender=="me")
        chats[reciver].push_back(data);
    else chats[sender].push_back(data);
}

void FriendWindow::onNewFriend(QString id)
{
    qDebug()<<"yes";
    friends.push_back(id);
    setLabels();
}

FriendWindow::~FriendWindow()
{
    delete ui;
}
void FriendWindow::setLabels()
{
    for(int i=j;i<j+5;i++){
        if(i<friends.size())
        {
            if(i-j==0)ui->pushButton->setText(friends[i]);
            if(i-j==1)ui->pushButton_2->setText(friends[i]);
            if(i-j==2)ui->pushButton_3->setText(friends[i]);
            if(i-j==3)ui->pushButton_4->setText(friends[i]);
            if(i-j==4)ui->pushButton_5->setText(friends[i]);
        }
        else {

            if(i-j==0)ui->pushButton->setText("Empty");
            else if(i-j==1)ui->pushButton_2->setText("Empty");
            else if(i-j==2)ui->pushButton_3->setText("Empty");
            else if(i-j==3)ui->pushButton_4->setText("Empty");
            else if(i-j==4)ui->pushButton_5->setText("Empty");
        }
    }
    if(j==0)ui->pushButton_7->setText("Welcome");
    else ui->pushButton_7->setText("Previous");
}

void FriendWindow::on_pushButton_clicked()
{
    ChatBox *c=new ChatBox(this);
    this->hide();
    c->setReceiver(ui->pushButton->text());
    for(int i=0;i<chats[ui->pushButton->text()].size();i++)
    {
        qDebug()<<chats[ui->pushButton->text()][i];
        c->addChat(chats[ui->pushButton->text()][i]);
    }



    c->show();
    this->show();
}

void FriendWindow::on_groupBox_objectNameChanged(const QString &objectName)
{

}
void FriendWindow::addFriend(QString username)
{
    friends.push_back(username);
}
void FriendWindow::on_pushButton_6_clicked()
{
    if(j<friends.size())
    j+=5;
    setLabels();
}

void FriendWindow::on_pushButton_7_clicked()
{
    if(j>0){j-=5;
    setLabels();}
}

void FriendWindow::on_pushButton_2_clicked()
{
    ChatBox *c=new ChatBox(this);
    c->setReceiver(ui->pushButton_2->text());
    this->hide();
    for(int i=0;i<chats[ui->pushButton_2->text()].size();i++)
    {
        c->addChat(chats[ui->pushButton_2->text()][i]);
        // qDebug()<<chats[ui->pushButton->text()][i];
    }


    c->show();
    this->show();
}

void FriendWindow::on_pushButton_3_clicked()
{
    ChatBox *c=new ChatBox(this);
    c->setReceiver(ui->pushButton_3->text());
    this->hide();
    for(int i=0;i<chats[ui->pushButton_3->text()].size();i++)
    {
        c->addChat(chats[ui->pushButton_3->text()][i]);
        // qDebug()<<chats[ui->pushButton_3->text()][i];
    }


    c->show();
    this->show();
}

void FriendWindow::on_pushButton_4_clicked()
{
    ChatBox *c=new ChatBox(this);
    c->setReceiver(ui->pushButton_4->text());
    this->hide();
    for(int i=0;i<chats[ui->pushButton_4->text()].size();i++)
    {
        c->addChat(chats[ui->pushButton_4->text()][i]);
         //qDebug()<<chats[ui->pushButton_4->text()][i];
    }


    c->show();
    this->show();
}

void FriendWindow::on_pushButton_5_clicked()
{
    ChatBox *c=new ChatBox(this);
    c->setReceiver(ui->pushButton_5->text());
    this->hide();
    for(int i=0;i<chats[ui->pushButton_5->text()].size();i++)
    {
        c->addChat(chats[ui->pushButton_5->text()][i]);
         //qDebug()<<chats[ui->pushButton_5->text()][i];
    }


    c->show();
    this->show();
}

void FriendWindow::on_AddFriendButton_clicked()
{
    QByteArray id=ui->lineEdit->text().toUtf8();
    exsocket->socketWrite("addfrnd-["+id+"]");
    exsocket->wrr(1000);
}
