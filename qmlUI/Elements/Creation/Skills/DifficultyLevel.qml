import QtQuick

Rectangle {
    property alias name: _name.text
    property alias value: _value.text

    id: _root

    color: "#fff"

    border.width: 2
    border.color: "#000"

    Column {
        spacing: 2

        Text {
            id: _name
            topPadding: 5
            font.pointSize: 8
            horizontalAlignment: Text.AlignHCenter
            width: _root.width
        }

        Text {
            id: _value
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            width: _root.width
        }
    } // Column

} // Rectangle
