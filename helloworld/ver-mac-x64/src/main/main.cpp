#include <any>
#include <cstdio>
#include <vector>
#include <QFile>
#include <QStandardPaths>
#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include "main.h"
#include "ignore.kd.h"

#define CB(code) std::make_any<std::function<void(MainContext)>>([&](MainContext c) { code })
#define VM VM::singleton()

static QString tasksStringToJson(const QString &tasksString) {
    QJsonArray arr;
    if (!tasksString.isEmpty()) {
        const QStringList items = tasksString.split('|');
        for (const QString &item : items) {
            const QStringList parts = item.split('&');
            if (parts.size() < 3) continue;
            QJsonObject obj;
            obj["id"]     = parts[0];
            obj["title"]  = parts[1];
            obj["isDone"] = (parts[2] == "true");
            arr.append(obj);
        }
    }
    QJsonObject root;
    root["tasks"] = arr;
    return QString::fromUtf8(QJsonDocument(root).toJson(QJsonDocument::Compact));
}

MainComponent::MainComponent() {
    std::vector<std::any> oneliners = {
            F.taskTitle,       CB( VM.mainSettaskTitle(c.taskTitle()); ),
            F.isVisible,       CB( VM.mainSetIsVisible(c.isVisible()); ),
            F.tasksString,     CB( VM.mainSettasksString(c.tasksString()); ),
            F.shouldSavaTasks, CB(
                                       QString dir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
                                       QDir().mkpath(dir);
                                       QFile file(dir + "/tasks.json");
                                       if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                                           QString json = tasksStringToJson(VM.tasksString());
                                           printf("DBG saving JSON: %s\n", json.toStdString().c_str());
                                           file.write(json.toUtf8());
                                           file.close();
                                       }
                               ),
    };
    MainEffectRegistry::registerOneliners(KT.mainCtrl(), oneliners);
}

void MainComponent::setup() {
    mainSet(F.didSetup, true);
}