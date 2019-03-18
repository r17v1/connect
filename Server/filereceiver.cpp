#include "filereceiver.h"
#include "iostream"
FileReceiver::FileReceiver()
{

}
void FileReceiver::setFilePath(std::string filename, std::string path, qint64 siz)
{
    filepath=path+"/"+filename;
    file= new QFile(filepath.c_str());
    file->open(QIODevice::WriteOnly);
    filesize = siz;
    return;
}
void FileReceiver::fileWrite(QByteArray data)
{
    file->write(data);
    file->waitForBytesWritten(10000);
    return;
}

bool FileReceiver::checkHealthCloseFile()
{
    file->close();
    return filesize==file->size();
}
