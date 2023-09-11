import QtQuick

Item {
    property int value: 0

    id: _root

    Row {
        spacing: 5
        padding: 5

        onImplicitWidthChanged: _root.width = implicitWidth

        Repeater {
            model: ListModel {
                ListElement { name: "Łat."; mod: 2}
                ListElement { name: "Prze."; mod: 0 }
                ListElement { name: "Prob."; mod: -2 }
                ListElement { name: "Trud."; mod: -5 }
                ListElement { name: "B.Tr"; mod: -8 }
                ListElement { name: "Ch.Tr."; mod: -11 }
                ListElement { name: "Fuks"; mod: -14 }
            }
            delegate: DifficultyLevel {
                name: model.name
                value: _root.value + model.mod
                width: _root.height; height: _root.height
            }
        }
    } // Row
} // Item
