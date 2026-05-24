package org.opengamestudio

import androidx.compose.animation.AnimatedVisibility
import androidx.compose.animation.fadeIn
import androidx.compose.animation.fadeOut
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Clear
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.input.ImeAction
import androidx.compose.ui.text.style.TextDecoration
import androidx.compose.ui.unit.dp

@Composable
fun MainView(
    modifier: Modifier = Modifier,
    vm: VM
) {
    AnimatedVisibility(
        enter = fadeIn(),
        exit = fadeOut(),
        modifier = modifier,
        visible = vm.mainIsVisible.value,
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
                    label = { Text("Задача") },
                    value = vm.mainTaskTitle.value,
                    onValueChange = { mainSet(F.taskTitle, it) },
                    singleLine = true,
                    modifier = Modifier.fillMaxWidth(),
                    keyboardOptions = androidx.compose.foundation.text.KeyboardOptions(
                        imeAction = ImeAction.Done
                    ),
                    keyboardActions = androidx.compose.foundation.text.KeyboardActions(
                        onDone = {
                            mainSet(F.didClickSaveText, true)
                        }
                    ),
                    trailingIcon = {
                        IconButton(
                            onClick = {
                                mainSet(F.didClickRemoveTasks, true)
                            }
                        ) {
                            Icon(Icons.Default.Clear, contentDescription = "Очистить")
                        }
                    }
                )

                Spacer(modifier = Modifier.height(16.dp))

                LazyColumn(
                    modifier = Modifier
                        .fillMaxWidth()
                        .weight(1f, fill = false)
                        .clip(RoundedCornerShape(10.dp))
                        .background(Color.LightGray),
                    verticalArrangement = Arrangement.spacedBy(8.dp)
                ) {
                    items(vm.tasks) { item ->
                        Text(
                            text = item.title,
                            modifier = Modifier
                                .padding(8.dp)
                                .clickable {
                                    mainSet(F.didSelectTask, item.id)
                                },
                            textDecoration = if (item.isDone)
                                TextDecoration.LineThrough
                            else
                                TextDecoration.None,
                            color = if (item.isDone) Color.Gray else Color.Black
                        )
                    }
                }
            }
        }
    }
}