import QtQuick

Rectangle {
    id: _root

    height: _column.implicitHeight

    border.width: 2
    border.color: "#000"

    Column {
        id: _column
        spacing: 5
        padding: 5

        Repeater {
            model: ListModel {
                ListElement { name: "Draśnięcia:" }
                ListElement { name: "Lekkie:" }
                ListElement { name: "Ciężkie:" }
                ListElement { name: "Krytyczne:" }
            }

            delegate: Row {
                spacing: 5

                Text {
                    id: _name
                    text: model.name
                    font.pointSize: 12
                    width: 80
                    height: _value.height
                    verticalAlignment: Text.AlignVCenter
                }

                Rectangle {
                    width: _root.width - 80 - parent.spacing * 4
                    height: _value.implicitHeight
                    border.width: 2
                    border.color: "#000"

                    Text {
                        id: _value
                        padding: 5
                        text: "-"
                        font.pointSize: 12
                    }
                }
            }
        }
    } // Column
} // Rectangle
