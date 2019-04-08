#include "fileexplorar.h"
#include "ui_fileexplorar.h"
MySocket *exsocket;

FileExplorar::FileExplorar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileExplorar)
{
    ui->setupUi(this);
    QString spath="C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(spath);
    dirmodel->setReadOnly(true);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->treeView->setModel(dirmodel);

    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setRootPath(spath);
    ui->listView->setModel(filemodel);

    filename = nullptr;


}

FileExplorar::~FileExplorar()
{
    delete ui;
}


void FileExplorar::on_treeView_clicked(const QModelIndex &index)
{
    QString spath = dirmodel->fileInfo(index).absoluteFilePath();

    ui->listView->setRootIndex(filemodel->setRootPath(spath));
    ui->listView->setModel(filemodel);
    qDebug() << spath;
}

void FileExplorar::on_listView_clicked(const QModelIndex &index)
{
    filepath = filemodel->fileInfo(index).absoluteFilePath();
    filename = filemodel->fileInfo(index).fileName();
    qDebug() << filepath<<' '<<filename;
}

void FileExplorar::on_send_button_clicked()
{
    if(filename == nullptr)
        QMessageBox::warning(this,"Caution","No File Selected");
    else
    {
        file = new QFile(filepath);
        file->open(QIODevice::ReadOnly);
        QString cmd="download["+filename+"]["+QString::number(file->size())+"]["+revceiver+"]";
        QByteArray data;
        data.append(cmd);
        exsocket->socketWrite(data);
        exsocket->socketRead();
        long long sz=file->size() ,cur=0;
        while (!file->atEnd()) {

            QByteArray data =  "file----";
            data.append(file->read(1000));
            exsocket->socketWrite(data);
            exsocket->socketRead();
            cur+=data.size()-8;
            ui->progressBar->setValue(cur*100/sz);
        }
        exsocket->socketWrite("endofile");
        cmd = QString(exsocket->socketRead());
        cmd=cmd.mid(0,8);
        if(cmd=="uploaded")
            QMessageBox::information(this,"Done?","Upload Successfull");
        else {
            QMessageBox::warning(this,"Done?","Upload failed");
        }

    }

}

void FileExplorar::on_cancel_button_clicked()
{
    filepath = nullptr;
}
