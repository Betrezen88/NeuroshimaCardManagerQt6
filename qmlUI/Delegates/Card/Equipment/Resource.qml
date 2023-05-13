import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    property alias name: _name.text
    property alias value: _value.value

    id: _root

    border.width: 2
    border.color: "#000"

    Row {
        anchors.fill: parent
        spacing: 1

        Text {
            id: _name
            width: 77; height: parent.height
            font.pointSize: 12
            leftPadding: 7
            verticalAlignment: Text.AlignVCenter
        }

        SpinBox {
            id: _value
            height: parent.height; width: _root.width - _name.width - parent.spacing
            font.pointSize: 12
            from: 0
            to: 14
        }
    }
}
