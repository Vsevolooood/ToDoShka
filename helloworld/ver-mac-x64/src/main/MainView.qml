import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: mainView
    anchors.fill: parent
    visible: vm.mainIsVisible

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16

        TextField {
            id: taskInput

            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop

            placeholderText: "Задача"
            text: vm.mainTaskTitle
            onTextChanged: {
                api.mainSet(F.taskTitle, text)
            }

            onAccepted: {
                onAccepted: {
                    api.mainSet(F.didClickSaveText, true)

                    console.log(vm.tasks)
                }
            }
        }
    }
}