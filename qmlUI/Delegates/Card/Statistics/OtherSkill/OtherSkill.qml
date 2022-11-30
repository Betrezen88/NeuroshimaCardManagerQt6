import QtQuick
import QtQuick.Controls

Item {
    property alias skillName: _skillName.text
    property alias skillAttribute: _attribute.text
    property alias skillValue: _value.text

    id: _root
    height: _skillName.implicitHeight < 40 ? 40 : _skillName.implicitHeight

    CheckBox {
        id: _used
        width: 40; height: 40
        anchors.left: parent.left
    }

    Text {
        id: _skillName
        text: model.name
        font.pointSize: 10
        anchors.left: _used.right
        height: parent.height; width: _root.width - _used.width - _attribute.width - _attribute.leftPadding
                                      - _attribute.rightPadding - _valueFrame.width
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
    }

    Row {
        anchors { right: parent.right; rightMargin: 5 }

        Text {
            id: _attribute
            text: model.attribute
            font.pointSize: 10
            height: 40
            leftPadding: 5; rightPadding: 5
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            id: _valueFrame
            width: 40; height: 40
            border.width: 2
            border.color: "#000"
            radius: 10

            Text {
                id: _value
                text: model.value
                font.pointSize: 10
                anchors.centerIn: parent
            }
        }
    } // Row
} // Item
