import QtQuick
import QtQuick.Controls

import core.creation 1.0

Item {
    property ReputationCreation reputation: null
    property bool hasAvailablePoints: true
    property bool isGeneralPoint: true
    property alias labelWidth: _name.width
    property alias implicitLabelWith: _name.implicitWidth

    id: _root

    Row {
        spacing: 5

        onImplicitWidthChanged: parent.width = implicitWidth
        onImplicitHeightChanged: parent.height = implicitHeight

        Text {
            id: _name
            text: reputation?.place ?? ""
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            height: _value.height
        }

        SpinBox {
            id: _value
            value: reputation?.value ?? 0
            height: 40
            from: reputation?.min ?? 0
            to: reputation?.max ?? 0

            up.onPressedChanged: {
                if ( up.pressed && reputation !== null && _root.hasAvailablePoints ) {
                    reputation.increase()
                    up.pressed = false
                } else {
                    value = reputation.value
                }
            }

            down.onPressedChanged: {
                if ( down.pressed && reputation !== null && _root.isGeneralPoint ) {
                    reputation.decrease()
                    down.pressed = false
                } else {
                    value = reputation.value
                }
            }
        }
    } // Row

} // Item
