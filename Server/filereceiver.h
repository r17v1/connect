#ifndef FILERECEIVER_H
#define FILERECEIVER_H

#include <QObject>
#include <QTcpSocket>
#include <string>
#include <QFile>

class FileReceiver : public QObject
{
    Q_OBJECT
public:
    FileReceiver();
    void fileWrite(QByteArray data);
    void setFilePath(std::string filename, std::string path, qint64 siz);
    bool checkHealthCloseFile();  //close file and checks health of the file.


private:
    std::string filepath;
    QFile *file;
    qint64 filesize;

};

#endif // FILERECEIVER_H
