import QtQuick

import "../../../Delegates/Card/Statistics/Wounds"

Rectangle {
    id: _root

    border.color: "#000"
    border.width: 2

    Column {
        anchors.fill: parent
        anchors.margins: 4
        spacing: 3

        Repeater {
            model: ListModel {
                ListElement { name: "Glowa"; value: "D, D, L, L, C, C, K, K" }
                ListElement { name: "Prawa Reka"; value: "D, D, L, L, C, C, K, K" }
                ListElement { name: "Lewa Reka"; value: "D, D, L, L, C, C, K, K" }
                ListElement { name: "Tulow"; value: "D, D, L, L, C, C, K, K" }
                ListElement { name: "Prawa Noga"; value: "D, D, L, L, C, C, K, K" }
                ListElement { name: "Lewa Noga"; value: "D, D, L, L, C, C, K, K" }
            }
            delegate: Wound {
                width: _root.width
                bodyPartName: model.name
                bodyPartWounds: model.value
            }
        }
    } // Column
} // Rectangle
