#include "mainwindow.h"
#include "ui_mainwindow.h"
//int current_pos=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //here j is the index of the username in the database aka rownum
    QString chatbox[10]={"A:: Hi","B:: Hello","C:: TATA","D:: BYe BYe","E:: MEH","Hi2","Hello2","TATA2","BYe BYe2","MEH2"};
    ui->setupUi(this);
    QString user="Logged in As   ",name="Hirok",username;
    username=user+name;
    ui->groupBox->setTitle(username);
    for(int i=j;i<j+5;i++){
        if(i==0)ui->pushButton->setText(chatbox[i]);
        else if(i==1)ui->pushButton_2->setText(chatbox[i]);
        else if(i==2)ui->pushButton_3->setText(chatbox[i]);
        else if(i==3)ui->pushButton_4->setText(chatbox[i]);
        else if(i==4)ui->pushButton_5->setText(chatbox[i]);
    }
    ui->pushButton_6->setText("Next");
    if(j==0)ui->pushButton_7->setText("Welcome");
    else ui->pushButton_7->setText("Previous");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


}

void MainWindow::on_groupBox_objectNameChanged(const QString &objectName)
{

}

void MainWindow::on_pushButton_6_clicked()
{
    j+=5;

}

void MainWindow::on_pushButton_7_clicked()
{
    if(j>0)j-=5;
}
