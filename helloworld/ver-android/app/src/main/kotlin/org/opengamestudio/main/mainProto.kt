package org.opengamestudio

object MainProto {
    val ctrl: KDController

    init {
        ctrl = KDController(MainContext())
        setupComponentDebugging(ctrl, "Main")
        arrayOf(
            ::mainShouldLaunch,
            ::mainShouldResetVisibility,
            ::shouldResetTasks,
            ::mainShouldClearTaskTitle,
        ).forEach { f ->
            ctrl.registerFunction { c -> f(c as MainContext) }
        }
    }
}
