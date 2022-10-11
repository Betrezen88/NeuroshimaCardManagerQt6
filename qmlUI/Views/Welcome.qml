import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../Delegates"

Item {
    id: _root


    Label {
        id: _label
        height: 40
        text: qsTr("Witaj !")
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
    }

    RowLayout {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: _label.bottom
        anchors.bottom: parent.bottom
        anchors.topMargin: 20
        anchors.leftMargin: 0
        spacing: 10

        Column {
            width: 200
            height: 400
            spacing: 5
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.rightMargin: 5
            Layout.fillHeight: true

            Button {
                width: 200
                height: 40
                text: qsTr("Stwórz nową postać")
            }
        }

        Column {
            width: 200
            height: 400
            spacing: 5
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.leftMargin: 5
            Layout.fillHeight: true

            Button {
                width: 200
                height: 40
                text: qsTr("Wczytaj kartę postaci")
            }

            Label {
                width: parent.width
                height: 30
                text: qsTr("Ostatnio otwierane")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Repeater {
                id: _recentFiles
                model: 1
                delegate: RecentFileDelegate {
                    width: parent.width
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1}D{i:6}D{i:2}
}
##^##*/
