#include "fileexplorar.h"
#include "ui_fileexplorar.h"
MySocket *exsocket;

FileExplorar::FileExplorar(QWidget *parent, bool state) :
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
    if(state)
    {
       filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
       ui->send_button->setText("Send");
       action = "upload";
    }
    else
    {
        filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
        ui->send_button->setText("Download");
        action = "download";
        filepath = nullptr;
        downloadCanceled=false;
    }

    filemodel->setRootPath(spath);
    ui->listView->setModel(filemodel);
    connect(exsocket,SIGNAL(fileUpload()),this,SLOT(upLoadFile()));
    connect(exsocket,SIGNAL(fileUpStatus(bool)),this,SLOT(fileStatus(bool)));
    connect(exsocket,SIGNAL(fileSize(qint64)),this,SLOT(setFilesize(qint64)));
    connect(exsocket,SIGNAL(filedata(QByteArray)),this,SLOT(downloadFile(QByteArray)));
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
    filepath = spath;
    ui->file_path_show->setText(filepath+"/"+filename);
    //qDebug() << spath;
}

void FileExplorar::on_listView_clicked(const QModelIndex &index)
{
    filepath = filemodel->fileInfo(index).absoluteFilePath();
    if(action=="upload")
    filename = filemodel->fileInfo(index).fileName();
    ui->file_path_show->setText(filepath+"/"+filename);
    //qDebug() << filepath<<' '<<filename;
}

void FileExplorar::on_send_button_clicked()
{
    if(action=="upload")
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
    else if(action=="download")
    {
        if(filepath==nullptr)
        {
            QMessageBox::warning(this,"Caution","Invalid Path");
        }
        else if(file!=nullptr)
        {
            QMessageBox::information(this,"Wait", "wait for Download finished");
        }
        else {
            downloadCanceled = false;
            file = new QFile(filepath+"/"+filename);
            file->open(QIODevice::WriteOnly);
            curfileposition =0;
            filesync = 0;
            QString cmd="upload--["+filename+"]["+sender+"]";
            QByteArray data;
            data.append(cmd);
            exsocket->socketWrite(data);
        }
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

void FileExplorar::downloadFile(QByteArray data)
{
    QString cmd(data);
    bool ok;
    int i=cmd.indexOf('[')+1;
    int k=cmd.indexOf(']');
    long long sz=cmd.mid(i,k-i).toLongLong(&ok,10);
    data.remove(0,k-i+2);
    qDebug()<<data.size()<<" "<<sz;

    file->write(data);
    curfileposition+=data.size();
    if(filesize!=0)
    ui->progressBar->setValue(curfileposition*100/filesize);

    if(data.size()<sz)
        filesync+=data.size();
    if(filesync==sz||data.size()==sz)
    {
        filesync=0;
        if(downloadCanceled)
            exsocket->socketWrite("upflcnld");
        else
             exsocket->socketWrite("upfldata");
    }

}

void FileExplorar::fileStatus(bool status)
{
    if(action=="upload")
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
    else if(action=="download")
    {
        if(filesize == file->size()&&filesize!=0)
            QMessageBox::information(this,"Done?","Download Successfull");
        else
        {
            QMessageBox::warning(this,"Done?","Dowload failed");
        }
        file->close();
        file->~QFile();
        file=nullptr;
    }
}

void FileExplorar::setFilesize(qint64 sz)
{
    filesize = sz;
    qDebug()<<sz;
    exsocket->socketWrite("upfldata");
}

void FileExplorar::on_cancel_button_clicked()
{
    if(file != nullptr&&action=="upload")
        file->seek(file->size());
    else if(file!=nullptr&&action=="download"){
        downloadCanceled=true;
    }
}


void FileExplorar::setReceiver(QString name)
{
    revceiver=name;
}
void FileExplorar::setSender(QString name)
{
    sender=name;
}

 void FileExplorar::setFileName(QString fnm)
 {
     filename =fnm;
 }

 void FileExplorar::reject()
 {
    this->close();
    this->~FileExplorar();
 }
