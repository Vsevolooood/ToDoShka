#include <any>
#include <cstdio>
#include <vector>

#include "main.h"
#include "ignore.kd.h"

#define CB(code) std::make_any<std::function<void(MainContext)>>([&](MainContext c) { code })
#define VM VM::singleton()


MainComponent::MainComponent() {
    std::vector<std::any> oneliners = {
            F.taskTitle, CB( VM.mainSettaskTitle(c.taskTitle()); ),
            F.isVisible, CB( VM.mainSetIsVisible(c.isVisible()); ),
            F.tasksString, CB(
                                   VM.mainSettasksString(c.tasksString());

                                   auto tasks = stringToTasks(c.tasksString());
                                   VM.mainSettasks(tasks);
                           ),

    };
    MainEffectRegistry::registerOneliners(KT.mainCtrl(), oneliners);
}

void MainComponent::setup() {
    mainSet(F.didSetup, true);
}
