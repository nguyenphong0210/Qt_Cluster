// Worker.h
#ifndef DATATHREADING_H
#define DATATHREADING_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QFile>

class DataThreading : public QObject
{
    Q_OBJECT
public:
    explicit DataThreading(QObject *parent = nullptr);

public slots:
    void doWork();

signals:
    void resultReady(const QString &result);
    void textDataChanged(const QString &newTextData); // New signal for text data changes

private:
    void readtxtfile();
    QTimer *timer;
    QString m_filePath = "../Cluster/Test.txt";
    QTextStream in;
    QString m_TextData;
};

#endif // WORKER_H
