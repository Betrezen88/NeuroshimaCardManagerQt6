import QtQuick

Item {
    property alias name: _name.text

    id: _root
    height: _column.implicitHeight

    Column {
        id: _column

        Text {
            id: _name
            width: _root.width
            font.pointSize: 12
            padding: 8
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
        }

        Rectangle {
            width: _root.width
            height: 2
            color: "#000"
        }
    } // Column

} // Item
