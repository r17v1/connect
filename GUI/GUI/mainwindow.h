#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signup.h"
#include "mysocket.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_SignIn_clicked();

    void on_pushButton_SignUp_clicked();

    void on_pushButton_clicked();

    void on_connet_but_clicked();

private:
    Ui::MainWindow *ui;
    SignUp *signUp;
    MySocket *socket;

};

#endif // MAINWINDOW_H
