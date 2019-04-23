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
    explicit ChatBox(QWidget *parent = nullptr, QString name="Chat!");
    ~ChatBox();
    void setReceiver(QString nm);

    void addChat(QString str);

    void setChat(std::map<QString,std::vector<QString> > *c)
    {
        chats=c;
    }
    void addFile(QString data);


private slots:

    void onNewChat(QString data);

    void on_file_attach_clicked();

    void on_pushButton_clicked();

    void on_download_clicked();

    void addIncommingFile(QString data);

private:
    Ui::ChatBox *ui;
    FileExplorar *explore;
    QString id;
    std::map<QString,std::vector<QString> > *chats;
    int filecount;
};

#endif // MAINWINDOW_H
