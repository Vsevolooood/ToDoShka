package org.opengamestudio

//<!-- Component -->

typealias MC = MainContext

object MainComponent {
    init {
        val vm = VM
        val oneliners = arrayOf(
            F.isVisible, { c: MC -> vm.mainIsVisible.value = c.isVisible },
            F.taskTitle, { c: MC -> vm.mainTaskTitle.value = c.taskTitle },
            F.tasksString, { c: MC ->
                vm.tasks.clear()
                vm.tasks.addAll(c.tasks)
            },
        )
        registerOneliners(mainCtrl(), oneliners)
    }

    fun setup() {
        mainSet(F.didSetup, true)
    }

}
