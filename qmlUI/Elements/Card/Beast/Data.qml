import QtQuick 2.15

import "../Common"

Item {
    id: _root

    height: _column.implicitHeight

    Column {
        id: _column
        spacing: 2

        Portrait {
            id: _picture
            width: _root.width; height: _root.width
        }

        HeaderLabel {
            text: "Dane"
            width: _root.width
        }

        DataField {
            id: _name
            width: _root.width
            name: "Imię"
            value: "Fafik"
        }

        DataField {
            id: _spicie
            width: _root.width
            name: "Rodzaj/Gatunek"
            value: "Gryzoń"
        }

        DataField {
            id: _connection
            width: _root.width
            name: "Wieź"
            value: "3"
        }

        DataField {
            id: _value
            width: 250
            name: "Wartość"
            value: "15"
        }

        HeaderLabel {
            text: "Podatność na:"
            width: _root.width
        }

        DataField {
            id: _oswojenie
            width: 250
            name: "Oswojenie"
            value: "Przecietny"
        }

        DataField {
            id: _tresura
            width: 250
            name: "Tresurę"
            value: "Trudny"
        }
    } // Column
} // Item
