#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signUp = nullptr;
    frnd =nullptr;
    exsocket = new MySocket;

    connect(exsocket,SIGNAL(login(bool)),this,SLOT(onlogin(bool)));
    connect(exsocket,SIGNAL(connectionLost()),this,SLOT(disconnect_and_destroy()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_SignIn_clicked()
{
    if(exsocket->isconnected()==false && exsocket->doConnect()==false)
    {
        QMessageBox::warning(this,"Caution","Couldn't connect to the server");
    }
    else {

        QString username = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();
        QString cmd = "login---["+username+"]["+password+"]";
        QByteArray data;
        data.append(cmd);
        exsocket->socketWrite(data);
        exsocket->wrr(1000);
    }

}

void MainWindow::onlogin(bool t)
{
    if(t)
    {
        QMessageBox::information(this,"SignIn", "Sign In Successful!");

        this->hide();
        frnd=new FriendWindow(this);
        frnd->setUsername(ui->lineEdit_username->text());
        frnd->setLabels();
        frnd->show();
        //exsocket->socketWrite("initdata");
    }
    else
    {
        QMessageBox::warning(this,"SignIn", "Username and Password do not match");
    }

}


void MainWindow::on_pushButton_SignUp_clicked()
{

    if(exsocket->isconnected()==false)
    {
        if(exsocket->doConnect()==false)
        {
            QMessageBox::warning(this,"Caution","Couldn't connect to the server");
            return;
        }
    }
    hide();
    signUp = new SignUp(this);
    signUp->setSocket(exsocket);
    signUp->exec();
    show();
}


void MainWindow::disconnect_and_destroy()
{
    if(signUp != nullptr)
    {
        signUp->close();
        this->show();
    }
    else if(frnd != nullptr)
    {
        frnd->close();
        frnd->~FriendWindow();
        this->show();
    }
}
