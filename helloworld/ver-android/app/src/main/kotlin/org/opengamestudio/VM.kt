package org.opengamestudio

import android.content.Context
import androidx.compose.runtime.mutableStateListOf
import androidx.compose.runtime.mutableStateOf

object VM {
    var androidContext: Context? = null

    var mainIsVisible = mutableStateOf(false)

    var mainTaskTitle = mutableStateOf("")
    var tasks = mutableStateListOf<MainItem>()
    var tasksString = mutableStateOf("")

}