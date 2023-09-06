import QtQuick

import core.creation 1.0

Rectangle {
    property AttributeCreation attribute: null

    id: _root

    border.width: 2
    border.color: "#000"

    color: "lightgray"

    Column {
        spacing: 5

        onImplicitHeightChanged: _root.height = implicitHeight + 10
        onImplicitWidthChanged: _root.width = implicitWidth

        Text {
            id: _name
            text: attribute !== null ? attribute.source.name : ""
            padding: 5
            font.bold: true
            font.pointSize: 14
        }

        AttributeDiffcultyLevels {
            value: attribute !== null ? attribute.value : 0
            height: 40
        }

        Item {
            width: 1; height: 1
        }

        Repeater {
            model: attribute !== null ? attribute.skillpacks : []
            delegate: Skillpack {
                skillpack: modelData
                width: _root.width - 10
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    } // Column

} // Rectangle
