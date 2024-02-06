#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include <Backend/dataThreading.h>
#include <Backend/Director.h>
#include "Backend/AppContext.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);    

    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/Cluster/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    //////////////// Data Threading ///////////////
    DataThreading dataThreading;
    QThread myThread;
    dataThreading.moveToThread(&myThread);

    QObject::connect(&app, &QCoreApplication::aboutToQuit, [&myThread] {
        qDebug() << "Application is about to quit";
        myThread.terminate();
        myThread.wait();
    });
    myThread.start();
    ////////////////////////////////////////////////
    Director* myDirector;
    myDirector = Director::Instance();

    if(nullptr != myDirector)
    {
        myDirector->onConfigure();
    }
    QObject::connect(&dataThreading, &DataThreading::textDataChanged, myDirector, &Director::receiveEvents);
    /////////////////////////////////////////////////
    GaugesViewControl* GaugesControl = AppContext::instance().getMyGaugeViewControlInstance();
    engine.rootContext()->setContextProperty("GaugesControl", GaugesControl);

    return app.exec();
}
