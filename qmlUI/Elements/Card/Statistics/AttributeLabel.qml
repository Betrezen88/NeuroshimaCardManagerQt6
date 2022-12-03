import QtQuick
import QtQuick.Controls

import "../../../Delegates/Card/Statistics/AttributeLabel"

Rectangle {
    id: _root

    property alias name: _name.text
    property int value: 0

    height: _content.implicitHeight + 5
    color: "gray"
    border.width: 2
    border.color: "#000"

    Column {
        id: _content
        anchors.fill: parent

        Label {
            id: _name
            padding: 5
            text: "Attribute Name"
            font.pointSize: 16
            color: "#000"
        }

        Row {
            spacing: 2
            anchors.horizontalCenter: parent.horizontalCenter

            Repeater {
                id: _levels
                model: ListModel {
                    ListElement { name: "Lat."; value: "2" }
                    ListElement { name: "Prze."; value: "0" }
                    ListElement { name: "Prob."; value: "-2" }
                    ListElement { name: "Trud."; value: "-5" }
                    ListElement { name: "B.Tr."; value: "-8" }
                    ListElement { name: "Ch.Tr."; value: "-11" }
                    ListElement { name: "Fuks"; value: "-14" }
                }

                delegate: AttributeValueLabel {
                    name: model.name
                    value: model.value
                }
            }
        } // Row
    } // Column
} // Rectangle
