import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    property alias quantity: _quantity.text
    property alias name: _name.text

    id: _root

    color: "#fff"
    border.width: 2
    border.color: "#000"

    Row {
        id: _row
        anchors.fill: parent
        spacing: 5

        Text {
            id: _quantity
            color: "#000"
            font.pointSize: 12
            padding: 5
            width: 50
            height: _root.height
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: _name
            width: _root.width - _quantity.width - _button.width - (parent.spacing*2)
            height: _root.height
            color: "#000"
            font.pointSize: 12
            padding: 5
            verticalAlignment: Text.AlignVCenter
        }

        Button {
            id: _button
            text: "..."
            height: parent.height
            width: height

            onClicked: _backpackItemMenu.open()

            Menu {
                id: _backpackItemMenu

                MenuItem {
                    id: _equipItem
                    text: "Wyekwipuj"
                }

                MenuItem {
                    id: _useItem
                    text: "Uzyj"
                }

                MenuItem {
                    id: _quantityItem
                    text: "Zmien ilosc"
                }

                MenuItem {
                    id: _removeItem
                    text: "Usun"
                }
            }
        }
    }
}
