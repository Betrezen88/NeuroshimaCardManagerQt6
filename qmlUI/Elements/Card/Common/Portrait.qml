import QtQuick 2.15

Rectangle {
    property url imagePath: _image.source

    id: _root

    color: "#fff"
    border.color: "#000"
    border.width: 2

    Image {
        id: _image
        anchors.fill: parent
    }
}
