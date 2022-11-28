import QtQuick
import QtQuick.Controls

Rectangle {
    id: _root

    property string aName: "Attribute Name"
    property int skillpacks: 1

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
            name: aName
            width: parent.width
        }

        Repeater {
            model: skillpacks

            delegate: Skillpack {
                width: _content.width - 10
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
