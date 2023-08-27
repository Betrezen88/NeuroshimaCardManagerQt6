import QtQuick
import QtQuick.Controls

Item {
    property alias name: _name.text

    id: _root
    width: _row.implicitWidth
    height: _row.implicitHeight

    Row {
        id: _row

        Text {
            id: _name
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            width: 150; height: 40
        }

        SpinBox {
            id: _value
            font.pointSize: 14
            from: 6; to: 20
            height: 40
        }
    } // Row
} // Item
