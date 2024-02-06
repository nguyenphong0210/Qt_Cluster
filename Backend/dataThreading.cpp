// Worker.cpp
#include "dataThreading.h"

DataThreading::DataThreading(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DataThreading::doWork);
    timer->start(100);
}

void DataThreading::doWork()
{
    readtxtfile();
}


void DataThreading::readtxtfile()
{
    QFile file(m_filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString textdata = file.readAll();
        if(m_TextData != textdata)
        {
            m_TextData = textdata;
            emit textDataChanged(m_TextData);
            // qDebug() << m_TextData;
        }
    }
    else{
        qDebug() << "Could not open file for reading";
    }
    file.close();
    // qDebug() << "Some other method executed in thread " << QThread::currentThreadId();
}
