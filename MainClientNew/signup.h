#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include "mysocket.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    void setSocket(MySocket *soc);

private slots:

    void onSignup(bool t);

    void on_pushButton_submit_clicked();

private:
    Ui::SignUp *ui;
    MySocket *socket;
};

#endif // SIGNUP_H
