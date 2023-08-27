import QtQuick
import QtQuick.Controls

Item {
    id: _root

    Row {
        spacing: 5
        padding: 5

        onImplicitHeightChanged: parent.height = implicitHeight

        Text {
            id: _name
            text: "Skillname"
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
            width: parent.parent.width - _attribute.width - _value.width - (parent.spacing*2) - (parent.padding*2)
            height: _value.height
        }

        Text {
            id: _attribute
            text: "At"
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
            height: _value.height
        }

        SpinBox {
            id: _value
            from: 0; to: 5
        }
    } // Row

} // Item
