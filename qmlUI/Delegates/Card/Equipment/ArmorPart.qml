import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    property alias label: _label.text
    property alias value: _value.text
    property alias item: _item.text
    property alias durability: _durability.text

    id: _root
    height: _column.implicitHeight

    color: "#000"

    Column {
        id: _column
        anchors.fill: parent

        Row {
            Label {
                id: _label
                width: _root.width - _value.width
                horizontalAlignment: Text.AlignHCenter
                padding: 5
                font.bold: true
                font.pointSize: 14
                color: "#fff"
            }

            Label {
                id: _value
                width: 50
                padding: 10
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 12
                color: "#000"
                background: Rectangle {
                    color: "#fff"
                    border.width: 5
                    border.color: "#000"
                }
            }
        } // Row Label

        Label {
            id: _item
            width: _column.width
            wrapMode: Text.WordWrap
            color: "#000"
            padding: 10
            font.pointSize: 12
            background: Rectangle {
                color: "#fff"
                border.color: "#000"
                border.width: 5
            }
        }

        Row {
            Label {
                text: "Wytrzymalosc"
                width: _root.width - _durability.width
                font.pointSize: 12
                color: "#000"
                padding: 10
                background: Rectangle {
                    color: "#fff"
                    border.color: "#000"
                    border.width: 5
                }
            }
            Label {
                id: _durability
                font.pointSize: 12
                color: "#000"
                padding: 10
                background: Rectangle {
                    color: "#fff"
                    border.color: "#000"
                    border.width: 5
                }
            }
        }
    } // Column

} // Rectangle
