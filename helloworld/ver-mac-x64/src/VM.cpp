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
        qDebug() << "IsVisible updated:" << value;
    }
}

void VM::mainSetTaskTitle(const QString &value) {
    if (_mainTaskTitle != value) {
        _mainTaskTitle = value;
        emit mainDidChangeTaskTitle(value);
        qDebug() << "TaskTitle updated:" << value;
    }
}

void VM::mainSettaskTitle(const QString &value) {
    mainSetTaskTitle(value);
}

void VM::mainSetTasks(const QStringList &tasks) {
    if (_tasks != tasks) {
        _tasks = tasks;

        if (!_isSyncing) {
            _isSyncing = true;
            _tasksString = tasks.join('|');
            emit tasksChanged();
            emit tasksStringChanged();
            _isSyncing = false;
            qDebug() << "Tasks updated (from tasks):" << _tasks;
            qDebug() << "TasksString updated (from tasks):" << _tasksString;
        } else {
            emit tasksChanged();
            qDebug() << "Tasks updated (sync skip):" << _tasks;
        }
    }
}

void VM::mainSettasks(const QStringList &tasks) {
    mainSetTasks(tasks);
}

void VM::mainSetTasksString(const QString &value) {
    if (_tasksString != value) {
        _tasksString = value;

        if (!_isSyncing) {
            _isSyncing = true;
            if (value.isEmpty()) {
                _tasks.clear();
            } else {
                _tasks = value.split('|');
            }
            emit tasksStringChanged();
            emit tasksChanged();
            _isSyncing = false;
            qDebug() << "TasksString updated (from string):" << _tasksString;
            qDebug() << "Tasks updated (from string):" << _tasks;
        } else {
            emit tasksStringChanged();
            qDebug() << "TasksString updated (sync skip):" << _tasksString;
        }
    }
}

void VM::mainSettasksString(const QString &value) {
    mainSetTasksString(value);
}