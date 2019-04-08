#include "chatbox.h"
#include "ui_chatbox.h"

ChatBox::ChatBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatBox)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("Chat!");

    if(j==0)ui->pushButton_3->setText("Welcome");

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

    ui->textBrowser->append("me : "+ui->lineEdit->text()+"\n");

    QString cmd = ui->lineEdit->text();


    cmd = "message-["+id+"]["+cmd+"]";
    QByteArray data;
    data.append(cmd);
    exsocket->socketWrite(data);
    ui->lineEdit->setText(nullptr);
}

void ChatBox::setReceiver(QString nm)
{
    id=nm;
}
