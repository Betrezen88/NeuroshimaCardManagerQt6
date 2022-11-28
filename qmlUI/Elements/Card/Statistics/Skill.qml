import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: _root

    height: 40

    CheckBox {
        id: _used
        height: parent.height
        width: parent.height
        anchors { top: parent.top; left: parent.left }
    } // Checkbox

    Label {
        id: _name
        text: "Skillname"
        color: "#000"
        verticalAlignment: Text.AlignVCenter
        height: parent.height
        anchors { top: parent.top; left: _used.right; leftMargin: 5 }
        font.pointSize: 10
    } // Label

    Label {
        id: _value
        text: "1"
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
