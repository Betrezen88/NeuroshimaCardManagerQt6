import QtQuick

Rectangle {
    id: _root

    height: _column.implicitHeight

    border.width: 2
    border.color: "#000"

    Column {
        id: _column
        spacing: 2
        padding: 5

        Repeater {
            model: ListModel {
                ListElement { name: "Spryt" }
                ListElement { name: "Zręczność" }
                ListElement { name: "Percepcja" }
            }

            delegate: AttributeRow {
                name: model.name
                width: _root.width - parent.padding * 2
            }
        }

        Rectangle {
            width: _root.width - parent.padding * 2; height: 2
            color: "#000"
        }

        Row {
            spacing: 5

            StatsField {
                id: _aggresion
                name: "Agresja:"
                value: "8"
                width: (_root.width / 2) - (parent.spacing/2)
            }

            StatsField {
                id: _movement
                name: "Ruch:"
                value: "1m / segment"
                width: (_root.width / 2) - (parent.spacing/2)
            }
        }

        StatsField {
            id: _travelSpeed
            name: "Prędkość:"
            value: "Przeciętna 6-7 km/h; Maksymalna 60 km/h"
            width: _root.width
        }

        StatsField {
            id: _damageLimit
            name: "Limit obrażeń:"
            value: "1 Krytyczna i 1 Ciężka"
            width: _root.width
        }
    } // Column
} // Rectangle
