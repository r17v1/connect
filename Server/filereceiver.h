#ifndef FILERECEIVER_H
#define FILERECEIVER_H

#include <QObject>
#include <QTcpSocket>
#include <QFile>

class FileReceiver : public QObject
{
    Q_OBJECT
public:
    FileReceiver();
    void fileWrite(QByteArray data);
    void setFilePath(QString filename, QString path, qint64 siz, bool dnld);
    bool checkHealthCloseFile();  //close file and checks health of the file.
    QByteArray fileSend();
    qint64 getFileSize();
    void setFileAtEnd();
    void setFilename(QString nm);
    void setFilereceiver(QString nm);
    void setFilesender(QString nm);
    QString getFilename();
    QString getFilereceiver();
    QString getFilesender();


private:
    QString filepath;
    QFile *file;
    qint64 filesize;
    QString filename, filereceiver, filesender;

};

#endif // FILERECEIVER_H
