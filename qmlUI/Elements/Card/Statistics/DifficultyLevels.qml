import QtQuick

import "../../../Delegates/Card/Statistics/AttributeLabel"

Rectangle {
    id: _root
    color: "lightgray"

    border.width: 2
    border.color: "#000"

    Row {
        spacing: 2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Repeater {
            id: _levels
            model: ListModel {
                ListElement { name: "Lat."; value: "+2" }
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
} // Rectangle
