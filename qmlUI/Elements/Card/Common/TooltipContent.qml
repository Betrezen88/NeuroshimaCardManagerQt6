import QtQuick
import QtQuick.Controls

Item {
    property alias title: _title.text
    property alias description: _description.text

    id: _root
    height: _column.implicitHeight

    Column {
        id: _column

        Text {
            id: _title
            width: _root.width
            font.pointSize: 12
            font.bold: true
            padding: 5
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: _description
            padding: 5
            width: _root.width
            font.pointSize: 10
            wrapMode: Text.WordWrap
        }

    } // Column
} // Item
