
package org.opengamestudio

fun tasksToString(tasks: Array<MainItem>): String {
    return tasks.joinToString("|") { "${it.id}&${it.title}&${it.isDone}" }
}

fun stringToTasks(str: String): Array<MainItem> {
    if (str.isBlank()) return arrayOf()

    return str.split("|").map { item ->
        val parts = item.split("&")
        MainItem(
            id = parts[0],
            title = parts[1],
            isDone = parts[2].toBoolean()
        )
    }.toTypedArray()
}