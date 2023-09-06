import QtQuick

Rectangle {
    property alias name: _name.text
    property bool selected: false

    signal clicked()

    id: _root

    color: selected ? "lightgray" : "gray"
    border.color: "gray"
    border.width: selected ? 2 : 0

    Text {
        id: _name
        width: parent.width; height: parent.height
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    MouseArea {
        anchors.fill: parent
        onClicked: _root.clicked()
    }
} // Rectangle
