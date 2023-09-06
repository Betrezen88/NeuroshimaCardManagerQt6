import QtQuick
import core.creation 1.0

Item {
    property AttributeCreation attribute: null

    id: _root
    height: _column.implicitHeight

    Column {
        id: _column

        Text {
            id: _name
            text: attribute !== null ? attribute.source.name : ""
            font.bold: true
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            height: 30; width: _root.width
        }

        Rectangle {
            height: 2; width: _root.width
            color: "#000"
        }

        Text {
            id: _description
            text: attribute !== null ? attribute.source.description : ""
            font.pointSize: 14
            padding: 5
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignJustify
            width: _root.width
            height: implicitHeight
        }
    } // Column
} // Item
