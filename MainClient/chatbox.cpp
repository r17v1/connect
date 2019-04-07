#include "chatbox.h"
#include "ui_chatbox.h"

ChatBox::ChatBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatBox)
{
    ui->setupUi(this);
    QString user="Chatting With   ",name="Hirok",username;
    username=user+name;
    ui->groupBox->setTitle(username);
    for(int i=j;i<j+6;i++){
     QString text;
     //just assuming i%2 it will be replaced by a flag
     if(i%2==0)text=name+" :: "+message[i];
     else text="You :: "+message[i];
       if(i==j)
    ui->label->setText(text);
       else if(i==j+1)
    ui->label_2->setText(text);
       else if(i==j+2)
    ui->label_3->setText(text);
       else if(i==j+3)
    ui->label_4->setText(text);
       else if(i==j+4)
    ui->label_5->setText(text);
       else if(i==j+5)
    ui->label_6->setText(text);}
    if(j==0)ui->pushButton_3->setText("Welcome");
        else ui->pushButton_3->setText("Previous");
}

ChatBox::~ChatBox()
{
    delete ui;
}


void ChatBox::on_label_linkActivated(const QString &link)
{
    ui->label->setText(message[j+0]);
    ui->label_2->setText(message[j+1]);
}


void ChatBox::on_pushButton_3_clicked()
{
    if(j)j-=6;

}


void ChatBox::on_pushButton_2_clicked()
{
    j+=6;
}

void ChatBox::on_file_attach_clicked()
{
    explore = new FileExplorar(this);
    explore->exec();
}
