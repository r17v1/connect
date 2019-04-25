#include "filereceiver.h"
#include "iostream"
FileReceiver::FileReceiver()
{
    filename = nullptr;
    filereceiver = nullptr;
    filesender = nullptr;

}
void FileReceiver::setFilePath(QString filename, QString path, qint64 siz, bool dnld)
{
    filepath = path+"/"+filename;
    qDebug() << filepath;
    file= new QFile(filepath);
    if(dnld)
    {
        file->open(QIODevice::WriteOnly);
        filesize = siz;
    }

    else {
        file->open(QIODevice::ReadOnly);
        filesize=file->size();
    }

    return;
}
void FileReceiver::fileWrite(QByteArray data)
{
    file->write(data);
    file->waitForBytesWritten(-1);
    return;
}

bool FileReceiver::checkHealthCloseFile()
{
    file->close();
    qDebug() << file->size();
    return filesize==file->size();
}
QByteArray FileReceiver::fileSend()
{
    if(!file->atEnd())
    {
       return file->read(10000);
    }
    else {
        file->close();
        file->~QFile();
        return nullptr;
    }

}

qint64 FileReceiver::getFileSize()
{
    return filesize;
}
void FileReceiver::setFileAtEnd()
{
    if(file!=nullptr&&file->isOpen())
    {
        file->seek(file->size());
        file->close();
        file->~QFile();
        file=nullptr;
    }
}

void FileReceiver::setFilename(QString nm)
{
   filename = nm;
}
void FileReceiver::setFilereceiver(QString nm)
{
   filereceiver = nm;
}
void FileReceiver::setFilesender(QString nm)
{
    filesender = nm;
}

QString FileReceiver::getFilename()
{
    return filename;
}
QString FileReceiver::getFilereceiver()
{
    return filereceiver;
}
QString FileReceiver::getFilesender()
{
    return filesender;
}
