package org.opengamestudio

import androidx.compose.animation.AnimatedVisibility
import androidx.compose.animation.fadeIn
import androidx.compose.animation.fadeOut
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.input.ImeAction
import androidx.compose.ui.unit.dp

@Composable
fun MainView(
    modifier: Modifier = Modifier,
    vm: VM
) {
    AnimatedVisibility(
        visible = vm.mainIsVisible.value,
        enter = fadeIn(),
        exit = fadeOut(),
        modifier = modifier
    ) {
        Scaffold(
            modifier = Modifier.fillMaxSize()
        ) { paddingValues ->
            Column(
                modifier = Modifier
                    .fillMaxSize()
                    .padding(paddingValues)
                    .padding(16.dp)
            ) {
                OutlinedTextField(
                    value = vm.mainTaskTitle.value,
                    onValueChange = {
                        mainSet(F.taskTitle, it)
                    },
                    label = {
                        Text("Задача")
                    },
                    singleLine = true,
                    modifier = Modifier.fillMaxWidth(),
                    keyboardOptions = androidx.compose.foundation.text.KeyboardOptions(
                        imeAction = ImeAction.Done
                    ),
                    keyboardActions = androidx.compose.foundation.text.KeyboardActions(
                        onDone = {
                            mainSet(F.didClickSaveText, true)
                        }
                    )
                )

            }
        }
    }
}