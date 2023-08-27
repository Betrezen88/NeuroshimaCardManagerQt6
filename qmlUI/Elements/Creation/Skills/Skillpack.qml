import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    property alias name: _name.text

    id: _root

    color: "#fff"
    border.width: 2
    border.color: "#000"

    Column {
        spacing: 5

        onImplicitHeightChanged: _root.height = implicitHeight

        Row {
            spacing: 5
            padding: 5

            Text {
                id: _name
                font.pointSize: 12
                font.bold: true
                leftPadding: 10
                verticalAlignment: Text.AlignVCenter
                height: _bought.height
            }

            Text {
                id: _specializations
                text: "(R)"
                font.pointSize: 12
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                height: _bought.height
            }

            Item {
                height: 1; width: _root.width - (parent.spacing*3) - (parent.padding*2) - _name.width - _specializations.width - _bought.width
            }

            CheckBox {
                id: _bought
                text: "Kup"
                contentItem: Text {
                    text: parent.text
                    color: "#000"
                    font.pointSize: 12
                    leftPadding: _bought.indicator.width + _bought.spacing
                    verticalAlignment: Text.AlignVCenter
                }
            }
        } // Row

        Repeater {
            model: 3
            delegate: Skill {
                width: _root.width
            }
        }

        Item {
            height: 1; width: 1
        }
    } // Column

} // Rectangle
