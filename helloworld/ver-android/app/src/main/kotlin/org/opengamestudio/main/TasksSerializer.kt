package org.opengamestudio

object TasksSerializer {
    fun serialize(tasks: Array<MainItem>): String {
        return tasks.joinToString("|") { "${it.id},${it.title},${it.isDone}" }
    }
}