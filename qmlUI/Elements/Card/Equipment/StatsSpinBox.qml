import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property alias name: _name.text
    property alias value: _value.value

    id: _root
    height: _value.height

    Text {
        id: _name
        font.bold: true
        font.pointSize: 10
    }

    SpinBox {
        id: _value
        font.pointSize: 10
        anchors { left: _name.right; leftMargin: 5 }
    }
}
