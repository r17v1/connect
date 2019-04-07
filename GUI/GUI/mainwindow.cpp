#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_SignIn_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(username=="system" && password=="test123")
    {
        QMessageBox::information(this,"SignIn", "Sign In Successful!");

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
    signUp->show();
}
