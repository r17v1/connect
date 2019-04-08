#include "friendwindow.h"
#include "ui_friendwindow.h"
//int current_pos=0;
FriendWindow::FriendWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FriendWindow)
{
    addFriend("r17v1");
    addFriend("herok");
    addFriend("rizvi");
    addFriend("d");
    addFriend("e");
    addFriend("f");
    ui->setupUi(this);
    QString user="Logged in As   ",name="Hirok",username;
    username=user+name;
    ui->groupBox->setTitle(username);
    for(int i=j;i<j+5;i++){
        if(i-j==0)ui->pushButton->setText(friends[i]);
        else if(i-j==1)ui->pushButton_2->setText(friends[i]);
        else if(i-j==2)ui->pushButton_3->setText(friends[i]);
        else if(i-j==3)ui->pushButton_4->setText(friends[i]);
        else if(i-j==4)ui->pushButton_5->setText(friends[i]);
    }
    ui->pushButton_6->setText("Next");
    if(j==0)ui->pushButton_7->setText("Welcome");
    else ui->pushButton_7->setText("Previous");
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
    }
    if(j==0)ui->pushButton_7->setText("Welcome");
    else ui->pushButton_7->setText("Previous");
}

void FriendWindow::on_pushButton_clicked()
{
    ChatBox *c=new ChatBox(this);
    this->hide();
    c->setReceiver(ui->pushButton->text());
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
    c->show();
    this->show();
}

void FriendWindow::on_pushButton_3_clicked()
{
    ChatBox *c=new ChatBox(this);
    c->setReceiver(ui->pushButton_3->text());
    this->hide();
    c->show();
    this->show();
}

void FriendWindow::on_pushButton_4_clicked()
{
    ChatBox *c=new ChatBox(this);
    c->setReceiver(ui->pushButton_4->text());
    this->hide();
    c->show();
    this->show();
}

void FriendWindow::on_pushButton_5_clicked()
{
    ChatBox *c=new ChatBox(this);
    c->setReceiver(ui->pushButton_5->text());
    this->hide();
    c->show();
    this->show();
}
