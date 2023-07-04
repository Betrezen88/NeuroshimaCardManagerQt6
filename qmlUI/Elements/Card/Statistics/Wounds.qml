import QtQuick

import core.view

import "../../../Delegates/Card/Statistics"

Rectangle {
    property Statistics statistics: null

    id: _root

    border.color: "#000"
    border.width: 2

    Column {
        anchors.fill: parent
        anchors.margins: 4
        spacing: 3

        Repeater {
            model: statistics != null ? statistics.locations : 0

            delegate: Wound {
                width: _root.width
                bodyPartName: modelData
                bodyPartWounds: statistics.woundsForLocation(modelData)
            }
        }
    } // Column
} // Rectangle
