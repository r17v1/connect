#include "chatbox.h"
#include "ui_chatbox.h"

ChatBox::ChatBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatBox)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("Chat!");
    connect(exsocket,SIGNAL(newMsg(QString)),this,SLOT(onNewChat(QString)));


}


void ChatBox::onNewChat(QString data)
{

    QString sender;
    QString reciver;
    QString msg;


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
    i+=2;
    for(;data[i]!=']';i++)
    {
        msg.push_back(data[i]);
    }

    if(sender=="me")
    ui->textBrowser->append("ME: "+msg+"\n");
    else
        ui->textBrowser->append(sender+": "+msg+"\n");
}



ChatBox::~ChatBox()
{
    delete ui;
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

void ChatBox::on_pushButton_clicked()
{

    ui->textBrowser->append("ME: "+ui->lineEdit->text()+"\n");

    QString cmd = ui->lineEdit->text();


    cmd = "message-["+id+"]["+cmd+"]";
    QByteArray data;
    data.append(cmd);
    exsocket->socketWrite(data);
    exsocket->wrr(1000);
    ui->lineEdit->setText(nullptr);
}

void ChatBox::setReceiver(QString nm)
{
    id=nm;
}
void ChatBox::addChat(QString data)
{
    QString sender;
    QString reciver;
    QString msg;


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
    i+=2;
    for(;data[i]!=']';i++)
    {
        msg.push_back(data[i]);
    }

    if(sender=="me")
    ui->textBrowser->append("ME: "+msg+"\n");
    else
        ui->textBrowser->append(sender+": "+msg+"\n");
}
