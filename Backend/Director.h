// MyObject.h
#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>
#include <QDebug>
#include <QString>
#include "DataModel/DataModel.h"
#include "AppContext.h"

class Director : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data READ getData WRITE setData NOTIFY dataChanged)

public:
    explicit Director(QObject *parent = nullptr);

    QString getData() const;
    void setData(const QString &data);

    virtual void onConfigure();
    virtual void onUpdate();

    static Director* Instance();
    static void CreateInstance();
    static void Destroy();

signals:
    void dataChanged();

public slots:
    void sendDataToQml();
    void receiveEvents(const QString &newTextData);

private:
    QString m_data;
    static Director* m_pInstance;
    DataModel* m_pDataModel;

    GaugesViewControl* testGaugesControl = AppContext::instance().getMyGaugeViewControlInstance();
};

#endif // DIRECTOR_H
