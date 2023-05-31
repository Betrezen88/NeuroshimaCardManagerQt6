import QtQuick 2.15

Rectangle {
    property alias name: _name.text
    property alias value: _value.text

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
            text: "Text"
            width: 40
            topPadding: 3
            font.pointSize: 8
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: _value
            text: "0"
            width: 40; height: _root.height - _name.height - parent.spacing
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    } // Column
} // Rectangle
