package org.opengamestudio

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import org.opengamestudio.ui.theme.MyApplicationTheme

class MainActivity: ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

        VM.androidContext = this
        // Launch components after specifying Android Context.
        MainComponent.setup()

        setContent {
            MyApplicationTheme {
                MainView(vm = VM)
            }
        }
    }
}
