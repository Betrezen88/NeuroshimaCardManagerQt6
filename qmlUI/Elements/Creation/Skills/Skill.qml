import QtQuick
import QtQuick.Controls

Item {
    property alias name: _name.text

    id: _root

    Row {
        spacing: 5
        leftPadding: 5

        onImplicitHeightChanged: _root.height = implicitHeight

        Text {
            id: _name
            text: "Skill name"
            font.pointSize: 12
            height: _value.height
        }

        Item {
            height: 1; width: _root.width - _name.width - _value.width - (parent.spacing*3) - parent.leftPadding
        }

        SpinBox {
            id: _value
            from: 0; to: 5
        }
    }
} // Item
