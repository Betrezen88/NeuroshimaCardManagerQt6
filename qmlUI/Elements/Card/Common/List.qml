import QtQuick

Rectangle {
    property alias model: _list.model
    property alias delegate: _list.delegate
    property alias spacing: _list.spacing

    id: _root

    border.width: 2
    border.color: "#000"

    ListView {
        id: _list
        anchors.fill: parent
        clip: true
    }
}
