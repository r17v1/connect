#include "chatbox.h"
#include "ui_chatbox.h"

ChatBox::ChatBox(QWidget *parent, QString name) :
    QMainWindow(parent),
    ui(new Ui::ChatBox)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("Chat with "+name);
    connect(exsocket,SIGNAL(newMsg(QString)),this,SLOT(onNewChat(QString)));
    connect(exsocket,SIGNAL(newFile(QString)),this,SLOT(addIncommingFile(QString)));
    filecount=0;

}


void ChatBox::onNewChat(QString data)
{

    QString sender;
    QString reciver;
    QString msg;


    int i=9;
    int k= data.indexOf("]",i);
    sender=data.mid(i,k-i);

    i=k+2;
    k=data.indexOf("]",i);
    reciver=data.mid(i,k-i);

    i=k+2;
    k=data.lastIndexOf(']');
    msg=data.mid(i,k-i);


    if(sender=="me" && reciver==id)
    ui->textBrowser->append("ME: "+msg+"\n");
    else if(sender==id)
        ui->textBrowser->append(sender+": "+msg+"\n");
}

void ChatBox::addFile(QString data)
{
    QString sender;
    QString reciver;
    QString filename;


    int i=9;
    int k= data.indexOf("]",i);
    sender=data.mid(i,k-i);

    i=k+2;
    k=data.indexOf("]",i);
    reciver=data.mid(i,k-i);

    i=k+2;
    k=data.lastIndexOf(']');
    filename=data.mid(i,k-i);

    ui->comboBox->addItem(filename);
    ui->lcdNumber->display(filecount);
}

void ChatBox::addIncommingFile(QString data)
{
    filecount++;
    QString sender;
    QString reciver;
    QString filename;


    int i=9;
    int k= data.indexOf("]",i);
    sender=data.mid(i,k-i);

    i=k+2;
    k=data.indexOf("]",i);
    reciver=data.mid(i,k-i);

    i=k+2;
    k=data.lastIndexOf(']');
    filename=data.mid(i,k-i);

    ui->comboBox->addItem(filename);
    ui->lcdNumber->display(filecount);
}


ChatBox::~ChatBox()
{
    delete ui;
}



void ChatBox::on_file_attach_clicked()
{
    explore = new FileExplorar(this,true);
    explore->setReceiver(id);
    explore->exec();
}

void ChatBox::on_pushButton_clicked()
{

    QString cmd = ui->lineEdit->text();
    ui->textBrowser->append("ME: "+cmd+"\n");


    QString cmd2="message-[me]["+id+"]["+cmd+"]";
    cmd = "message-["+id+"]["+cmd+"]";

    (*chats)[id].push_back(cmd2);
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
    int k= data.indexOf("]",i);
    sender=data.mid(i,k-i);

    i=k+2;
    k=data.indexOf("]",i);
    reciver=data.mid(i,k-i);

    i=k+2;
    k=data.lastIndexOf(']');
    msg=data.mid(i,k-i);

   // qDebug()<<sender<<' '<<reciver<<' '<<msg<<data<<' '<< k <<' '<< i;

    if(sender=="me")
    ui->textBrowser->append("ME: "+msg+"\n");
    else
        ui->textBrowser->append(sender+": "+msg+"\n");
}

void ChatBox::on_download_clicked()
{
    explore = new FileExplorar(this, false);
    explore->setSender(id);
    explore->setFileName(ui->comboBox->currentText());
    explore->show();
}
