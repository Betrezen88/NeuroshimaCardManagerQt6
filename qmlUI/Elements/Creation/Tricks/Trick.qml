import QtQuick

Item {
    property alias name: _name.text

    id: _root

    Text {
        id: _name
        font.pointSize: 12
        anchors.verticalCenter: parent.verticalCenter
        wrapMode: Text.WordWrap
        padding: 5
        width: _root.width

        onImplicitHeightChanged: _root.height = implicitHeight > 40 ? implicitHeight : 40
    }

    MouseArea {
        anchors.fill: parent
        onClicked: console.log("Show tricks info")
    }

} // Item
