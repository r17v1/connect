#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    exsocket = new MySocket;

    connect(exsocket,SIGNAL(login(bool)),this,SLOT(onlogin(bool)));

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
    exsocket->socketWrite(data);
    exsocket->wrr(1000);

/*    cmd=QString(exsocket->socketRead());

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
    }*/
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
    hide();
    signUp = new SignUp(this);
    signUp->setSocket(exsocket);
    signUp->exec();
    show();
}

void MainWindow::on_connet_but_clicked()
{
    if(exsocket->doConnect()==false)
    {
        QMessageBox::warning(this,"Caution","Couldn't connect to the server");
    }
    else {
        QMessageBox::information(this, "Congratulation", "You are now connected");
        ui->conncetion_status->setChecked(true);
    }
}
