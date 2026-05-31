#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>
#include <QStandardPaths>
#include <QDir>

#include "ignore.kd.h"
#include "main.h"
#include "VM.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QObject::connect(
            &engine,
            &QQmlApplicationEngine::objectCreationFailed,
            &app,
            []() { QCoreApplication::exit(-1); },
            Qt::QueuedConnection
    );

    API api;
    FObj fobj;
    MainComponent m;
    m.setup();

    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/tasks.json";
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString json = QString::fromUtf8(file.readAll());
        file.close();
        std::string jsonStd = json.toStdString();
        ::mainSet<const char*>(F.saveString, jsonStd.c_str());
        ::mainSet<bool>(F.loadTasks, true);
    }

    engine.rootContext()->setContextProperty("api", &api);
    engine.rootContext()->setContextProperty("F", &fobj);
    engine.rootContext()->setContextProperty("vm", &VM::singleton());
    engine.loadFromModule("helloworld", "MainView");
    engine.loadFromModule("helloworld", "AppView");

    return app.exec();
}