#ifndef HW_VM_H
#define HW_VM_H

#include <QObject>
#include <QStringList>
#include <vector>
#include <string>

class VM: public QObject {
    Q_OBJECT

    Q_PROPERTY(
            bool mainIsVisible
            READ mainIsVisible
            WRITE mainSetIsVisible
            NOTIFY mainDidChangeIsVisible
    )

    Q_PROPERTY(
            QString mainTaskTitle
            READ mainTaskTitle
            WRITE mainSetTaskTitle
            NOTIFY mainDidChangeTaskTitle
    )

    Q_PROPERTY(
            QStringList tasks
            READ tasks
            NOTIFY tasksChanged
    )

private:
    VM();

public:
    VM(VM const &) = delete;
    void operator=(VM const &) = delete;
    virtual ~VM() { }
    static VM &singleton() {
        static VM instance;
        return instance;
    }

    // Getters
    bool mainIsVisible() const { return _mainIsVisible; }
    QString mainTaskTitle() const { return _mainTaskTitle; }
    QStringList tasks() const { return _tasks; }

public slots:
            void mainSetIsVisible(bool value);
    void mainSetTaskTitle(const QString &value);
    void mainSettaskTitle(const QString &value);  // Алиас для Kotlin
    void addTask(const QString &task);
    void addAllTasks(const QStringList &tasks);   // Для QStringList
    void addAllTasks(const std::vector<std::string> &tasks);  // Для std::vector из Kotlin
    void removeTask(int index);
    void clearTasks();

    signals:
            void mainDidChangeIsVisible(bool value);
    void mainDidChangeTaskTitle(const QString &value);
    void tasksChanged();

private:
    bool _mainIsVisible = false;
    QString _mainTaskTitle = "";
    QStringList _tasks;
};

#endif // HW_VM_H