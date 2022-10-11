import QtQuick 2.15

Rectangle {
    property alias recentFilename: _recentFilename.text

    id: _root
    height: _column.implicitHeight
    color: "lightgray"

    Column {
        id: _column
        anchors.fill: parent
        spacing: 5

        Text {
            id: _recentFilename
            width: parent.width
            font.pointSize: 12
            wrapMode: Text.WordWrap
        }
    }

    MouseArea {
        anchors.fill: parent
    }
}
