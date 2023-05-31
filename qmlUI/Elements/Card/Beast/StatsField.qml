import QtQuick
import QtQuick.Controls

Item {
    property alias name: _name.text
    property alias value: _value.text

    id: _root
    height: _name.implicitHeight

    Row {
        anchors.fill: parent

        Label {
            id: _name
            font.pointSize: 12
            font.bold: true
            color: "#000"
            verticalAlignment: Text.AlignVCenter
            padding: 5
        }

        Label {
            id: _value
            font.pointSize: 12
            color: "#000"
            height: _name.implicitHeight
            verticalAlignment: Text.AlignVCenter
        }
    }
}
