#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}



void SignUp::on_pushButton_submit_clicked()
{
    QString firstname=ui->lineEdit_firstname->text();
    QString lastname=ui->lineEdit_lastname->text();
    QString username=ui->lineEdit_username->text();
    QString email=ui->lineEdit_email->text();
    QString password=ui->lineEdit_password->text();
}
