#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new MySocket;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_SignIn_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString cmd = "login---["+username+"]["+password+"]";
    QByteArray data;
    data.append(cmd);
    socket->socketWrite(data);
    cmd=QString(socket->socketRead());

    if(cmd=="loginT--")
    {
        QMessageBox::information(this,"SignIn", "Sign In Successful!");

        this->hide();
        frnd=new FriendWindow(this);
        frnd->show();
    }
    else
    {
        QMessageBox::warning(this,"SignIn", "Username and Password do not match");
    }
}

void MainWindow::on_pushButton_SignUp_clicked()
{
    hide();
    signUp = new SignUp(this);
    signUp->setSocket(socket);
    signUp->exec();
    show();
}

void MainWindow::on_connet_but_clicked()
{
    if(socket->doConnect()==false)
    {
        QMessageBox::warning(this,"Caution","Couldn't connect to the server");
    }
    else {
        QMessageBox::information(this, "Congratulation", "You are now connected");
        ui->conncetion_status->setChecked(true);
    }


}
