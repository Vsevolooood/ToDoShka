package org.opengamestudio

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import org.opengamestudio.ui.theme.MyApplicationTheme
import java.io.File

class MainActivity: ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

        VM.androidContext = this
        MainComponent.setup()

        val file = File(filesDir, "tasks.json")
        if (file.exists()) {
            mainSet(F.saveString, file.readText())
            mainSet(F.loadTasks, true)
        }

        setContent {
            MyApplicationTheme {
                MainView(vm = VM)
            }
        }
    }
}