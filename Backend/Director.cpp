#include "Director.h"

Director* Director::m_pInstance = nullptr;

Director::Director(QObject *parent) : QObject(parent)
{
}

QString Director::getData() const
{
    return m_data;
}

void Director::onUpdate()
{
    QStringList lines = m_data.split("\n", Qt::SkipEmptyParts);

    foreach (const QString &line, lines) {
        int index = line.lastIndexOf(":");
        if(index > 0)
        {
            QString txtid = line.left(index);
            int id = txtid.toInt();
            QString txtvalue = line.mid(index + 1);
            int value = txtvalue.toInt();
            qDebug() << id << ":" << value;
            m_pDataModel->SetDataValue((DataType)id, value);
        }
    }

    testGaugesControl->Update(*m_pDataModel);

    m_pDataModel->Reset();
}

void Director::setData(const QString &data)
{
    if (data != m_data) {
        m_data = data;
        emit dataChanged();
    }
}

void Director::onConfigure()
{
    m_pDataModel = DataModel::Instance();
}

void Director::sendDataToQml()
{
    setData("Hello from C++ using Q_PROPERTY!");
}

void Director::receiveEvents(const QString &newTextData)
{
    setData(newTextData);

    onUpdate();
}

Director* Director::Instance()
{
    if (nullptr == m_pInstance) {
        CreateInstance();
    }
    return m_pInstance;
}

void Director::CreateInstance()
{
    m_pInstance = new Director();
}

void Director::Destroy()
{
    if (nullptr != m_pInstance) {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}
