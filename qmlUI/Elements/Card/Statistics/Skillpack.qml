import QtQuick
import QtQuick.Controls

Rectangle {
    id: _root

    height: _content.implicitHeight + 5
    border.width: 2
    border.color: "#000"
    radius: 10

    Column {
        id: _content
        anchors.fill: parent
        spacing: 3

        Row {
            spacing: 10

            Label {
                id: _name
                text: "Skillpack"
                topPadding: 5; bottomPadding: 5
                leftPadding: 15; rightPadding: 5
                color: "#000"
                font.bold: true
                font.pointSize: 12
            }

            Label {
                id: _specializations
                text: "(R)"
                padding: 5
                color: "#000"
                font.bold: true
                font.pointSize: 12
            }
        } // Row

        Repeater {
            model: 3

            delegate: Skill {
                width: parent.width
            }
        }
    } // Column
} // Rectangle
