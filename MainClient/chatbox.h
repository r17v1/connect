#ifndef CHATBOX_H
#define CHATBOX_H

#include <QMainWindow>

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

private slots:
    void on_toolButton_triggered(QAction *arg1);

    void on_label_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChatBox *ui;
};

#endif // MAINWINDOW_H
