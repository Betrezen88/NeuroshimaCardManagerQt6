import QtQuick
import QtQuick.Controls

Column {
    id: _root

    spacing: 3

    Label {
        text: "Sztuczki"
        width: _root.width; height: 40
        font.bold: true
        font.pointSize: 14
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        background: Rectangle {
            color: "#000"
        }
    }

    ListView {
        spacing: 3
        clip: true
        width: _root.width; height: 500

        model: 3

        delegate: Rectangle {
            color: "#fff"
            width: ListView.view.width; height: 40
            radius: 10
            border.width: 2
            border.color: "#000"

            Text {
                text: "Sztuczka"
                font.pointSize: 12
                anchors.centerIn: parent
            }
        }
    } // ListView
} // Column
