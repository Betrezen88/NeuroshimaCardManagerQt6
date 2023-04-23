import QtQuick 2.15

Item {
    property var stats: {
        "requiredBody": 12,
        "penetration": 1,
        "damage": "Lekka",
        "rateOfFire": 1,
        "bullet": "9 mm",
        "magazine": 15,
        "ammunition": 15,
        "jam": "16 - 20",
        "specials": [ "Celny", "Poreczny", "Powolne przeledownie" ]
    }

    id: _root
    height: _column.implicitHeight + _column.anchors.margins * 2

    Column {
        id: _column
        anchors.fill: parent
        anchors.margins: 5
        spacing: 5

        Row {
            width: parent.width

            StatsText {
                id: _requiredBody
                width: parent.width / 2
                name: "Wymagana Budowa:"
                value: stats.requiredBody
            }

            StatsText {
                id: _penetration
                width: parent.width / 2
                name: "Przebicie:"
                value: stats.penetration
            }
        }

        Row {
            width: parent.width

            StatsText {
                id: _damage
                width: parent.width / 2
                name: "Obrazenia:"
                value: stats.damage
            }

            StatsText {
                id: _rateOfFire
                width: parent.width / 2
                name: "Szybkostrzelnosc:"
                value: stats.rateOfFire
            }
        }

        Row {
            width: parent.width

            StatsText {
                id: _bullet
                width: parent.width / 2
                name: "Naboj:"
                value: stats.bullet
            }

            StatsText {
                id: _magazine
                width: parent.width / 2
                name: "Magazynek:"
                value: stats.magazine
            }
        }

        StatsSpinBox {
            id: _ammunition
            width: parent.width
            name: "Amunicja:"
            value: stats.ammunition
        }

        StatsSpecials {
            id: _specials
            width: parent.width
            name: "Specjalne:"
            value: stats.specials
        }
    }
}
