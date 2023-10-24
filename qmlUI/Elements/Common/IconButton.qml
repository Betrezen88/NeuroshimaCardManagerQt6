import QtQuick

Rectangle {
    property url source

    id: _root

    signal clicked()

    radius: 100

    Image {
        source: _root.source
        anchors.fill: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: _root.clicked()
    }
} // Rectangle
