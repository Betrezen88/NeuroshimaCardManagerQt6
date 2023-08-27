import QtQuick

Item {
    property alias name: _name.text
    property alias description: _description.text

    id: _root
    height: _column.implicitHeight

    Column {
        id: _column

        Text {
            id: _name
            font.bold: true
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            height: 30; width: _root.width
        }

        Rectangle {
            height: 2; width: _root.width
            color: "#000"
        }

        Text {
            id: _description
            text: "Jeśli przeznaczysz ma nią mało punktów, wyciągniesz kopyta przy pierwszym starciu. Jeden cios w papę i będzie po tobie. Albo inaczej - zatrzasną się za tobą drzwi i co? I dechniesz z głodu, bo nie będziesz i potrafił wyważyć. Spadnie na ciebie kupa żelastwa i zostaniesz wprasowany w ziemię. Bez wysokiej Budowy nie przetrasz tu ani godziny."
            font.pointSize: 14
            padding: 5
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignJustify
            width: _root.width
            height: implicitHeight
        }
    } // Column
} // Item
