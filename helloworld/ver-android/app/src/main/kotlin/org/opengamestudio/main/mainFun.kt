package org.opengamestudio

//<!-- Shoulds -->

// Launch only once
//
// Purpose: Work around Android's activity restart
//
// Conditions:
// 1. UI has been created the first time
fun mainShouldLaunch(c: MainContext): MainContext {
    if (
        c.recentField == F.didSetup &&
        !c.didLaunch
    ) {
        c.didLaunch = true
        c.recentField = F.didLaunch
        return c
    }

    c.recentField = F.none
    return c
}
fun shouldResetTasks(c: MainContext): MainContext {
    if (c.recentField == F.didClickSaveText && c.taskTitle.isNotBlank()) {
        c.tasks = c.tasks + c.taskTitle
        c.recentField = F.tasks
        return c
    }

    c.recentField = F.none
    return c
}

fun mainShouldClearTaskTitle(c: MainContext): MainContext {
    if (c.recentField == F.didClickSaveText && c.taskTitle.isNotBlank()) {
        c.taskTitle = ""
        c.recentField = F.taskTitle  // Сообщаем, что изменилось поле taskTitle
        return c
    }
    c.recentField = F.none
    return c
}
fun mainShouldResetVisibility(c: MainContext): MainContext {
    if (c.recentField == F.didLaunch) {
        c.isVisible = true
        c.recentField = F.isVisible
        return c
    }
    c.recentField = F.none
    return c
}


// Specify greeting text
//
// Conditions:
// 1. Did launch
// 2. Did click `Change text` button


// Set `main` window visible
//
// Conditions:
// 1. Did launch



//<!-- Other functions -->


fun mainCtrl(): KDController {
    return MainProto.ctrl
}

fun mainCtrlCtx(): MainContext {
    return MainProto.ctrl.context as MainContext
}

fun mainCtrlCtxField(): String {
    return MainProto.ctrl.context.recentField
}

fun mainSet(k: String, v: Any) {
    MainProto.ctrl.set(k, v)
}