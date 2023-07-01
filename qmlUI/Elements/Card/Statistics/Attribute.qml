import QtQuick

import core.view

Rectangle {
    property Attribute attribute: null

    id: _root

    height: _content.implicitHeight + 5
    color: "lightgray"
    border.color: "#000"
    border.width: 2

    Column {
        id: _content
        anchors.fill: parent
        spacing: 3

        AttributeLabel {
            id: _label
            name: attribute != null ? attribute.name : "Attribute name"
            value: attribute != null ? attribute.value : 0
            width: parent.width
        }

        Repeater {
            model: attribute != null ? attribute.skillpacks : 0

            delegate: NSSkillpack {
                skillpack: modelData
                width: _content.width - 10
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    } // Column

} // Rectangle
