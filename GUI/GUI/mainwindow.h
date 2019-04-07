#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signup.h"

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

private:
    Ui::MainWindow *ui;
    SignUp *signUp;
};

#endif // MAINWINDOW_H
