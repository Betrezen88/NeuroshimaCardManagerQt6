import QtQuick 2.15

Item {
    property alias name: _name.text
    property alias value: _value.text

    id: _root
    height: _name.height

    Text {
        id: _name
        font.bold: true
        font.pointSize: 10
    }

    Text {
        id: _value
        font.pointSize: 10
        anchors { left: _name.right; leftMargin: 5 }
    }
}
