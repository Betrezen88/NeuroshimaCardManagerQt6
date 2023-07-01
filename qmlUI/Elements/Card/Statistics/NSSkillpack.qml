import QtQuick
import QtQuick.Controls

import core.view

Rectangle {
    property Skillpack skillpack: null

    id: _root

    height: _content.implicitHeight + 5
    border.width: 2
    border.color: "#000"
    radius: 10

    Column {
        id: _content
        anchors.fill: parent
        spacing: 3

        Row {
            spacing: 10

            Label {
                id: _name
                text: skillpack != null ? skillpack.name : "Skillpack"
                topPadding: 5; bottomPadding: 5
                leftPadding: 15; rightPadding: 5
                color: "#000"
                font.bold: true
                font.pointSize: 12
            }

            Label {
                id: _specializations
                text: skillpack != null ? skillpack.specializationsShort() : "()"
                padding: 5
                color: "#000"
                font.bold: true
                font.pointSize: 12
            }
        } // Row

        Repeater {
            model: skillpack != null ? skillpack.skills : 0

            delegate: NSSkill {
                skill: modelData
                width: parent.width
            }
        }
    } // Column
} // Rectangle
