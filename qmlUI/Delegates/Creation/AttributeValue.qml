import QtQuick
import QtQuick.Controls

import core.creation 1.0

Item {
    property AttributeCreation attribute: null

    id: _root
    width: _row.implicitWidth
    height: _row.implicitHeight

    Row {
        id: _row

        Text {
            id: _name
            text: attribute !== null ? attribute.source.name : ""
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            width: 150; height: 40
        }

        SpinBox {
            id: _value
            value: attribute !== null ? attribute.baseValue : 6
            font.pointSize: 14
            from: 6; to: 20
            height: 40

            onValueChanged: attribute.baseValue = value
        }
    } // Row

} // Item
