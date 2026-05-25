// VM.h
#ifndef HW_VM_H
#define HW_VM_H

#include <QObject>
#include <QStringList>

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
            WRITE mainSetTasks
            NOTIFY tasksChanged
    )

    Q_PROPERTY(
            QString tasksString
            READ tasksString
            WRITE mainSetTasksString
            NOTIFY tasksStringChanged
    )

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
    QString tasksString() const { return _tasksString; }

public slots:
            void mainSetIsVisible(bool value);
    void mainSetTaskTitle(const QString &value);
    void mainSettaskTitle(const QString &value);
    void mainSetTasks(const QStringList &tasks);
    void mainSettasks(const QStringList &tasks);
    void mainSetTasksString(const QString &value);
    void mainSettasksString(const QString &value);

    signals:
            void mainDidChangeIsVisible(bool value);
    void mainDidChangeTaskTitle(const QString &value);
    void tasksChanged();
    void tasksStringChanged();

private:
    VM();

    bool _mainIsVisible = false;
    QString _mainTaskTitle = "";
    QStringList _tasks;
    QString _tasksString;
    bool _isSyncing = false;  // Флаг для предотвращения рекурсии
};

#endif // HW_VM_H