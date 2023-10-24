import QtQuick
import QtQuick.Controls

Item {
    required property var source

    id: _root

    Row {
        spacing: 5
        padding: 5

        onImplicitHeightChanged: _root.height = implicitHeight

        Image {
            id: _info

            width: _value.height
            height: _value.height

            source: "qrc:/Images/icons/info.svg"
        }

        Text {
            id: _name
            text: "Skillname"
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            width: _root.width - _info.width - _attribute.width - _value.width - (parent.spacing*3) - (parent.padding*2)
            height: implicitHeight > _value.height ? implicitHeight : _value.height
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
            width: 90
            from: 0; to: 5
        }
    } // Row

} // Item
