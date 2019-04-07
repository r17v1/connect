#include "filereceiver.h"
#include "iostream"
FileReceiver::FileReceiver()
{

}
void FileReceiver::setFilePath(QString filename, QString path, qint64 siz)
{
    filepath=path+"/"+filename;
    qDebug() << filepath;
    file= new QFile(filepath);
    file->open(QIODevice::WriteOnly);
    filesize = siz;
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
