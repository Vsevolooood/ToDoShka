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
        spacing: 16

        RowLayout {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop
            spacing: 8

            TextField {
                id: taskInput
                Layout.fillWidth: true
                placeholderText: "Задача"
                text: vm.mainTaskTitle

                onTextChanged: {
                    api.mainSet(F.taskTitle, text)
                }

                onAccepted: {
                    api.mainSet(F.didClickSaveText, true)
                }
            }

            Button {
                id: clearButton
                text: "Del"
                font.pixelSize: 18

                background: Rectangle {
                    color: "#E0E0E0"
                    radius: 4
                    border.color: "#B0B0B0"
                }

                onClicked: {
                    api.mainSet(F.didClickRemoveTasks, true)
                }
            }
        }

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            clip: true
            spacing: 8

            property var taskList: vm.tasksString !== "" ? vm.tasksString.split('|') : []

            model: taskList

            delegate: Rectangle {
                width: ListView.view.width
                height: 48
                radius: 8

                color: taskIsDone ? "#D3D3D3" : "#F5F5F5"
                border.width: 1
                border.color: "#C0C0C0"

                property var parts: modelData.split(',')
                property string taskId: parts.length > 0 ? parts[0] : ""
                property string taskTitle: parts.length > 1 ? parts[1] : ""
                property bool taskIsDone: parts.length > 2 ? parts[2] === 'true' : false

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 12

                    text: taskTitle

                    color: taskIsDone ? "#808080" : "#000000"
                    font.strikeout: taskIsDone
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        api.mainSet(F.didSelectTask, taskId)
                    }
                }
            }
        }
    }
}