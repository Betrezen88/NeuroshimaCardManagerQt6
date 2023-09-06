import QtQuick
import QtQuick.Controls

import data.types 1.0
import core.source 1.0

Item {
    property AttributeBonusSource bonus: null

    id: _root
    height: 40

    Row {
        spacing: 5
        onWidthChanged: _root.width = implicitWidth

        Text {
            text: "+" + (bonus !== null ? bonus.value : 0)
            width: implicitWidth; height: _root.height
            font.pointSize: 16
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            text: (bonus !== null && bonus.type === Types.AttributeBonus.Single) ? bonus.name : "Brak"
            width: implicitWidth; height: _root.height
            font.pointSize: 16
            verticalAlignment: Text.AlignVCenter
            visible: bonus !== null ? bonus.type === Types.AttributeBonus.Single : false
        }

        ComboBox {
            model: (bonus !== null && bonus.type === Types.AttributeBonus.List) ? bonus.list : []
            width: implicitWidth; height: _root.height
            font.pointSize: 16
            visible: bonus !== null ? bonus.type === Types.AttributeBonus.List : false
        }
    }

} // Item
