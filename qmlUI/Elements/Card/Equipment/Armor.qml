import QtQuick 2.15

import "../../../Delegates/Card/Equipment"

Grid {
    id: _root

    columns: 2
    spacing: 4

    Repeater {
        model: ListModel {
            ListElement { name: "Glowa"; value: "1"; item: "Helm kewlarowy"; durability: "3/3" }
            ListElement { name: "Tulow"; value: "1"; item: "Kamizelka kewlarowa"; durability: "3/3" }
            ListElement { name: "Prawa Reka"; value: "1"; item: "Kamizelka kewlarowa"; durability: "3/3" }
            ListElement { name: "Lewa Reka"; value: "1"; item: "Kamizelka kewlarowa"; durability: "3/3" }
            ListElement { name: "Prawa Noga"; value: "1"; item: "Spodnie kewlarowe"; durability: "3/3" }
            ListElement { name: "Lewa Noga"; value: "1"; item: "Spodnie kewlarowe"; durability: "3/3" }
        }

        delegate: ArmorPart {
            width: parent.width / 2 - 2
            label: model.name
            value: model.value
            item: model.item
            durability: model.durability
        }
    }
}
