// VM.cpp
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

void VM::mainSetTasks(const QStringList &tasks) {
    if (_tasks != tasks) {
        _tasks = tasks;
        emit tasksChanged();
        qDebug() << "Tasks updated:" << _tasks;
    }
}

void VM::mainSettasks(const QStringList &tasks) {
    mainSetTasks(tasks);
}