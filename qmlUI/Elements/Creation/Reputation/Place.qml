import QtQuick
import QtQuick.Controls

Item {
    property alias name: _name.text
    property alias labelWidth: _name.width
    property alias implicitLabelWith: _name.implicitWidth

    id: _root

    Row {
        spacing: 5

        onImplicitWidthChanged: parent.width = implicitWidth
        onImplicitHeightChanged: parent.height = implicitHeight

        Text {
            id: _name
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            height: _value.height
        }

        SpinBox {
            id: _value
            height: 40
        }
    } // Row

} // Item
