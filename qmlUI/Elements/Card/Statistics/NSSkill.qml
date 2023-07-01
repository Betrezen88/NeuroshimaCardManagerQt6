import QtQuick
import QtQuick.Controls

import core.view

Item {
    property Skill skill: null

    id: _root

    height: 40

    CheckBox {
        id: _used
        checked: skill != null ? skill.used : false
        height: parent.height
        width: parent.height
        anchors { top: parent.top; left: parent.left }
    } // Checkbox

    Label {
        id: _name
        text: skill != null ? skill.name : "Skillname"
        color: "#000"
        verticalAlignment: Text.AlignVCenter
        height: parent.height
        anchors { top: parent.top; left: _used.right; leftMargin: 5 }
        font.pointSize: 10
    } // Label

    Label {
        id: _value
        text: skill != null ? skill.value : 0
        color: "#000"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        height: parent.height; width: parent.height
        anchors { top: parent.top; right: parent.right; rightMargin: 5 }
        font.pointSize: 10

        background: Rectangle {
            border.width: 2
            border.color: "#000"
            radius: 10
        }
    } // Label
} // Item
