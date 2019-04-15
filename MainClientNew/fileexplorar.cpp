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
    connect(exsocket,SIGNAL(fileUpload()),this,SLOT(upLoadFile()));
    connect(exsocket,SIGNAL(fileUpStatus(bool)),this,SLOT(fileStatus(bool)));
    file=nullptr;
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
    //qDebug() << spath;
}

void FileExplorar::on_listView_clicked(const QModelIndex &index)
{
    filepath = filemodel->fileInfo(index).absoluteFilePath();
    filename = filemodel->fileInfo(index).fileName();
    //qDebug() << filepath<<' '<<filename;
}

void FileExplorar::on_send_button_clicked()
{
    if(filename == nullptr)
        QMessageBox::warning(this,"Caution","No File Selected");
    else if(file!=nullptr)
        QMessageBox::information(this,"Wait", "wait for file finished");
    else
    {
        file = new QFile(filepath);
        file->open(QIODevice::ReadOnly);
        filesize = file->size();
        curfileposition =0;
        QString cmd="download["+filename+"]["+QString::number(file->size())+"]["+revceiver+"]";
        QByteArray data;
        data.append(cmd);
        exsocket->socketWrite(data);
    }

}

void FileExplorar::upLoadFile()
{
    QByteArray data;
    QString siz;
    if(!file->atEnd())
    {
        data.append("["+QString::number(file->bytesAvailable()>50000? 50000:file->bytesAvailable())+"]");
        data.append(file->read(50000));
        curfileposition+=data.size();
        exsocket->socketWrite(data);
        ui->progressBar->setValue(curfileposition*100/filesize);
    }
    else
    {
        file->close();
        file=nullptr;
        exsocket->socketWrite("endofile");
    }
}

void FileExplorar::fileStatus(bool status)
{
    if(status)
    {
        QMessageBox::information(this,"Done?","Upload Successfull");
    }
    else
    {
        QMessageBox::warning(this,"Done?","Upload failed");
    }
}

void FileExplorar::on_cancel_button_clicked()
{
    if(file != nullptr)
        file->seek(file->size());
    else {
        this->close();
    }
}
