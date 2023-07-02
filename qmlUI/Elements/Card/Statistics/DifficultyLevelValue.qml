import QtQuick

Rectangle {
    property alias name: _name.text
    property int value: 0

    id: _root

    width: 40; height: 40
    color: "#fff"
    radius: 10
    border.width: 2
    border.color: "#000"

    Column {
        anchors.fill: parent
        spacing: 2

        Text {
            id: _name
            width: 40
            topPadding: 3
            font.pointSize: 8
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: _value
            text: _root.value
            width: 40; height: _root.height - _name.height - parent.spacing
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    } // Column
} // Rectangle
