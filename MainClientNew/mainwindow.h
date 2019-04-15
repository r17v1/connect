#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signup.h"
#include "friendwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addFriend(QString);

private slots:
    void on_pushButton_SignIn_clicked();

    void on_pushButton_SignUp_clicked();

    void on_connet_but_clicked();
    void disconnect_and_destroy();


public slots:
    void onlogin(bool t);
    //void onsignup(bool t);

private:
    Ui::MainWindow *ui;
    SignUp *signUp;
    FriendWindow *frnd;

};

#endif // MAINWINDOW_H
