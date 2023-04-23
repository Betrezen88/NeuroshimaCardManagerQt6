import QtQuick 2.15

Item {
    property var stats: {
        "requiredBody": 12,
        "penetration": 1,
        "dexterityBonus": "Atak +1, Obrona +1, Inicjatywa +1, Grupa +1",
        "damage": "1s Lekka / 2s Lekka / 3s Ciezka",
        "specials": [ "Poreczny" ]
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

        StatsText {
            id: _dexterityBonus
            width: parent.width
            name: "Bonus do zrecznosci:"
            value: stats.dexterityBonus
        }

        StatsText {
            id: _damage
            width: parent.width
            name: "Obrazenia:"
            value: stats.damage
        }

        StatsSpecials {
            id: _specials
            width: parent.width
            name: "Specjalne:"
            value: stats.specials
        }
    }
}
