#include "VM.h"
#include <QDebug>

VM::VM() : QObject(nullptr) {
    // Constructor
}

void VM::mainSetIsVisible(bool value) {
    if (_mainIsVisible != value) {
        _mainIsVisible = value;
        emit mainDidChangeIsVisible(value);
    }
}

void VM::mainSetTaskTitle(const QString &value) {
    if (_mainTaskTitle != value) {
        _mainTaskTitle = value;
        emit mainDidChangeTaskTitle(value);
    }
}

void VM::mainSettaskTitle(const QString &value) {
    mainSetTaskTitle(value);
}

void VM::addTask(const QString &task) {
    if (!task.isEmpty()) {
        _tasks.append(task);
        emit tasksChanged();
    }
}

void VM::addAllTasks(const QStringList &tasks) {
    if (!tasks.isEmpty()) {
        _tasks.append(tasks);
        emit tasksChanged();
    }
}

// Перегрузка для std::vector<std::string> из Kotlin
void VM::addAllTasks(const std::vector<std::string> &tasks) {
    if (!tasks.empty()) {
        for (const auto &task : tasks) {
            _tasks.append(QString::fromStdString(task));
        }
        emit tasksChanged();
    }
}

void VM::removeTask(int index) {
    if (index >= 0 && index < _tasks.size()) {
        _tasks.removeAt(index);
        emit tasksChanged();
    }
}

void VM::clearTasks() {
    if (!_tasks.isEmpty()) {
        _tasks.clear();
        emit tasksChanged();
    }
}