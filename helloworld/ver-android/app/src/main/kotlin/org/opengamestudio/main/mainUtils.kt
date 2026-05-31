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

fun tasksToJson(tasks: Array<MainItem>): String {
    val items = tasks.joinToString(",") { task ->
        """{"id":"${task.id}","title":"${task.title}","isDone":${task.isDone}}"""
    }
    return """{"tasks":[$items]}"""
}

fun jsonToTasks(json: String): Array<MainItem> {
    if (json.isBlank()) return arrayOf()
    val itemsRaw = json.substringAfter("[").substringBeforeLast("]")
    if (itemsRaw.isBlank()) return arrayOf()
    return itemsRaw.split("},{").map { raw ->
        val clean = raw.replace("{", "").replace("}", "")
        fun field(name: String): String =
            clean.substringAfter("\"$name\":").trimStart('"').substringBefore('"')
        fun boolField(name: String): Boolean =
            clean.substringAfter("\"$name\":").trimStart().startsWith("true")
        MainItem(
            id     = field("id"),
            title  = field("title"),
            isDone = boolField("isDone"),
        )
    }.toTypedArray()
}