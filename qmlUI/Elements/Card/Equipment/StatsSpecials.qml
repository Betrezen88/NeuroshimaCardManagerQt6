import QtQuick 2.15

Item {
    property alias name: _name.text
    property alias value: _value.model

    id: _root
    height: _flow.implicitHeight

    Flow {
        id: _flow
        anchors.fill: parent
        spacing: 5

        Text {
            id: _name
            font.bold: true
            font.pointSize: 10
        }

        Repeater {
            id: _value

            delegate: Text {
                text: modelData + ","
                font.pointSize: 10
            }
        }
    }
}
