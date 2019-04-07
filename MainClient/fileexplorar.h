#ifndef FILEEXPLORAR_H
#define FILEEXPLORAR_H

#include <QDialog>
#include <QFileSystemModel>
#include <QTcpSocket>
#include <QFile>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "mysocket.h"

extern MySocket *exsocket;

namespace Ui {
class FileExplorar;
}

class FileExplorar : public QDialog
{
    Q_OBJECT

public:
    explicit FileExplorar(QWidget *parent = nullptr);
    ~FileExplorar();

    void setReceiver();

private slots:

    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

    void on_send_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::FileExplorar *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    QFile *file;
    QString filepath, filename, revceiver;
};

#endif // FILEEXPLORAR_H
