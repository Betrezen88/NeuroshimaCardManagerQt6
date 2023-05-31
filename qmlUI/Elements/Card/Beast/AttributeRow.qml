import QtQuick
import QtQuick.Controls

import "../Common"

Item {
    property alias name: _name.text

    id: _root
    height: _row.implicitHeight

    Row {
        id: _row
        spacing: 2

        Label {
            id: _name
            width: _root.width - (7*40) - (7*2)
            height: _root.height
            padding: 5
            font.pointSize: 12
            font.bold: true
            color: "#000"
            verticalAlignment: Text.AlignVCenter
        }

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

            delegate: ValueLabel {
                name: model.name
                value: model.value
            }
        }
    } // Row
} // Item
