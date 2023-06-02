import QtQuick

Item {
    property string successes
    property string name
    property string damage

    id: _root
    height: _column.implicitHeight

    Column {
        id: _column
        anchors.fill: parent

        Row {
            padding: 8
            spacing: 5

            Text {
                id: _successes
                text: _root.successes + (_root.successes > 1 ? " sukcesy" : " sukces  ")
                font.pointSize: 12
            }

            Text {
                id: _name
                text: "- " + _root.name
                font.pointSize: 12
            }

            Text {
                id: _damage
                text: "(" +_root.damage+ ")"
                font.pointSize: 12
            }
        } // Row

        Rectangle {
            width: _root.width
            height: 2
            color: "#000"
        }
    } // Column

} // Item
