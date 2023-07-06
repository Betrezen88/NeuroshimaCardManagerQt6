import QtQuick

import core.view

import "../../../Delegates/Card/Statistics"

Rectangle {
    property WoundsHandler wounds: null

    id: _root

    border.color: "#000"
    border.width: 2

    Column {
        anchors.fill: parent
        anchors.margins: 4
        spacing: 3

        Repeater {
            id: _wounds
            model: wounds != null ? wounds.locations : 0

            delegate: Wound {
                width: _root.width
                bodyPartName: modelData
                bodyPartWounds: wounds.woundsForLocation(modelData)
            }
        }
    } // Column

    Connections {
        target: wounds
        function onWoundsChanged() {
            console.log("Wounds.onWoundsChanged()")
            _wounds.model = 0
            _wounds.model = wounds.locations
        }
    }
} // Rectangle
