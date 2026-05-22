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
    void mainSettaskTitle(const QString &value);
    void mainSetTasks(const QStringList &tasks);
    void mainSettasks(const QStringList &tasks);

    signals:
            void mainDidChangeIsVisible(bool value);
    void mainDidChangeTaskTitle(const QString &value);
    void tasksChanged();

private:
    VM();

    bool _mainIsVisible = false;
    QString _mainTaskTitle = "";
    QStringList _tasks;
};

#endif // HW_VM_H