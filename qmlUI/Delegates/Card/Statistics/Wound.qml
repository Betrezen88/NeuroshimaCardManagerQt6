import QtQuick 2.15

Row {
    property alias bodyPartName: _label.text
    property alias bodyPartWounds: _wounds.text

    id: _root

    Text {
        id: _label
        font.pointSize: 12
        verticalAlignment: Text.AlignVCenter
        height: 30; width: 90
    }

    Rectangle {
        height: 30; width: _root.width - _label.width - 10
        border.color: "#000"
        border.width: 2
        radius: 5

        Text {
            id: _wounds
            font.pointSize: 11
            padding: 5
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
        }
    } // Rectangle
} // Row
