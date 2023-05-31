import QtQuick
import QtQuick.Controls

Rectangle {
    property alias text: _contentText.text

    id: _root

    border.width: 2
    border.color: "#000"

    ScrollView {
        anchors.fill: parent
        clip: true

        TextArea {
            id: _contentText
            width: _root.width
            padding: 5
            font.pointSize: 12
            color: "#000"
            wrapMode: Text.WordWrap
        }
    } // ScrollView
} // Rectangle
