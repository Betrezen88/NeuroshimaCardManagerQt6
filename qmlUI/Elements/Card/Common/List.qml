import QtQuick 2.15

Rectangle {
    property alias model: _list.model
    property alias delegate: _list.delegate

    id: _root

    border.width: 2
    border.color: "#000"

    ListView {
        id: _list
        anchors.fill: parent
        clip: true
        spacing: 2
    }
}
