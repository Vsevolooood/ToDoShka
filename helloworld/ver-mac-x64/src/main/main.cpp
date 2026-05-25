#include <any>
#include <cstdio>
#include <vector>
#include <QStringList>

#include "main.h"
#include "ignore.kd.h"

#define CB(code) std::make_any<std::function<void(MainContext)>>([&](MainContext c) { code })
#define VM VM::singleton()

// Вспомогательная функция для конвертации строки в список задач
static QStringList stringToTasks(const QString& tasksString) {
    if (tasksString.isEmpty()) {
        return QStringList();
    }
    return tasksString.split('|');
}

MainComponent::MainComponent() {
    std::vector<std::any> oneliners = {
            F.taskTitle, CB( VM.mainSettaskTitle(c.taskTitle()); ),
            F.isVisible, CB( VM.mainSetIsVisible(c.isVisible()); ),
            F.tasksString, CB( VM.mainSettasksString(c.tasksString()); ),
    };
    MainEffectRegistry::registerOneliners(KT.mainCtrl(), oneliners);
}

void MainComponent::setup() {
    mainSet(F.didSetup, true);
}