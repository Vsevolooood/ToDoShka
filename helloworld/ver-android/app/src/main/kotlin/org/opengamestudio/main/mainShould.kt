package org.opengamestudio

fun mainShouldLaunch(c: MainContext): MainContext {
    if (c.recentField == F.didSetup && !c.didLaunch) {
        c.didLaunch = true
        c.recentField = F.didLaunch
        return c
    }
    c.recentField = F.none
    return c
}

fun shouldResetTasks(c: MainContext): MainContext {
    if (c.recentField == F.didClickSaveText && c.taskTitle.isNotBlank()) {
        val nextId = (c.tasks.maxOfOrNull { it.id.toInt() } ?: 0) + 1
        c.tasks = c.tasks + MainItem(id = nextId.toString(), title = c.taskTitle, isDone = false)
        c.recentField = F.tasks
        return c
    }
    if (c.recentField == F.didClickRemoveTasks) {
        c.tasks = c.tasks.filter { !it.isDone }.toTypedArray()
        c.recentField = F.tasks
        return c
    }
    if (c.recentField == F.didSelectTask && c.didSelectTask.isNotBlank()) {
        c.tasks = c.tasks.map { task ->
            if (task.id == c.didSelectTask) {
                MainItem(id = task.id, title = task.title, isDone = !task.isDone)
            } else {
                task
            }
        }.toTypedArray()
        c.recentField = F.tasks
        return c
    }
    c.recentField = F.none
    return c
}

fun mainShouldConvertTasksToString(c: MainContext): MainContext {
    if (c.recentField == F.tasks) {
        c.tasksString = tasksToString(c.tasks)
        c.recentField = F.tasksString
        return c
    }
    c.recentField = F.none
    return c
}

fun mainShouldConvertTasksFromString(c: MainContext): MainContext {
    if (c.recentField == F.tasksString && c.tasksString.isNotBlank()) {
        c.tasks = stringToTasks(c.tasksString)
        c.recentField = F.tasks
        return c
    }
    c.recentField = F.none
    return c
}

fun mainShouldClearTaskTitle(c: MainContext): MainContext {
    if (c.recentField == F.didClickSaveText && c.taskTitle.isNotBlank()) {
        c.taskTitle = ""
        c.recentField = F.taskTitle
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