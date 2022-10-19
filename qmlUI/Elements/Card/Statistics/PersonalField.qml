import QtQuick

Rectangle {
    property string name
    property string value
    property string description

    id: _root

    color: "#fff"
    height: _text.implicitHeight < 40 ? 40 : _text.implicitHeight
    radius: 10
    border.color: "#000"
    border.width: 2

    Text {
        id: _text
        text: "<b>" + _root.name + ":</b> " + _root.value
        font.pointSize: 12
        wrapMode: Text.WordWrap
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        padding: 5
    }
}
