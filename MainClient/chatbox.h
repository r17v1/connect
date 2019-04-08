#ifndef CHATBOX_H
#define CHATBOX_H

#include <QMainWindow>
#include "fileexplorar.h"

namespace Ui {
class ChatBox;
}

class ChatBox : public QMainWindow
{
    Q_OBJECT

public:
    int j=0;
    QString message[10]={"Hi","Hello","TATA","BYe BYe","MEH","Yah","Hello2","TATA2","BYe BYe2","MEH2"};
    explicit ChatBox(QWidget *parent = nullptr);
    ~ChatBox();
    void setReceiver(QString nm);

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_file_attach_clicked();

    void on_pushButton_clicked();

private:
    Ui::ChatBox *ui;
    FileExplorar *explore;
    QString id;
};

#endif // MAINWINDOW_H
