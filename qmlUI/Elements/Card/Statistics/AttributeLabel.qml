import QtQuick
import QtQuick.Controls

Rectangle {
    id: _root

    property alias name: _name.text
    property int value: 0

    height: _content.implicitHeight + 5
    color: "gray"
    border.width: 2
    border.color: "#000"

    Column {
        id: _content
        anchors.fill: parent

        Label {
            id: _name
            padding: 5
            text: "Attribute Name"
            font.pointSize: 16
            color: "#000"
        }

        Row {
            spacing: 2
            anchors.horizontalCenter: parent.horizontalCenter

            Repeater {
                id: _levels
                model: 7

                delegate: Rectangle {
                    width: 40; height: 40
                    color: "#fff"
                    radius: 10
                    border.width: 2
                    border.color: "#000"
                }
            }
        } // Row
    } // Column
} // Rectangle
