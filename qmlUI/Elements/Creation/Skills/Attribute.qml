import QtQuick

Rectangle {
    property alias name: _name.text
    property int value: 0
    property var skillpacks

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
            text: "Attribute Name"
            padding: 5
            font.bold: true
            font.pointSize: 14
        }

        AttributeDiffcultyLevels {
            value: _root.value
            height: 40
        }

        Item {
            width: 1; height: 1
        }

        Repeater {
            model: skillpacks
            delegate: Skillpack {
                name: modelData
                width: _root.width - 10
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    } // Column

} // Rectangle
