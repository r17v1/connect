#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QString friends[10]={"FRIEND LIST","Farhad","Masum","Rizvi","Kawser","Herok","Raian","Rabib","Nur","Nahin"};
    ui->setupUi(this);
    QString user="Logged in As   ",name="Herok",username;
    username=user+name;
    ui->groupBox->setTitle(username);
    for(int i=j;i<j+7;i++){
        if(i==0)ui->pushButton->setText(friends[i]);
        else if(i==1)ui->pushButton_2->setText(friends[i]);
        else if(i==2)ui->pushButton_3->setText(friends[i]);
        else if(i==3)ui->pushButton_4->setText(friends[i]);
        else if(i==4)ui->pushButton_5->setText(friends[i]);
        else if(i==5)ui->pushButton_8->setText(friends[i]);
        else if(i==6)ui->pushButton_9->setText(friends[i]);

    }
    ui->pushButton_10->setText("Find Friend");
    ui->pushButton_6->setText("Add Friend");
    if(j==0)ui->pushButton_7->setText("Next");
    else ui->pushButton_7->setText("Previous");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_6_clicked()
{

}

void MainWindow::on_pushButton_10_clicked()
{

}


void MainWindow::on_pushButton_7_clicked()
{

}

