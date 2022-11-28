import QtQuick 2.15

Rectangle {
    property alias name: _name.text
    property alias value: _value.text
    property alias elements: _elements.model

    id: _root
    height: _mouseArea.showElements ? _column.implicitHeight : 30

    Column {
        id: _column
        anchors.fill: parent

        Item {
            width: _root.width; height: 30

            Text {
                id: _name
                height: parent.height
                anchors { left: parent.left; leftMargin: 2 }
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 12
            }

            Text {
                id: _value
                height: parent.height
                anchors { right: parent.right; rightMargin: 2 }
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 12
            }
        } // Item

        Repeater {
            id: _elements
            delegate: Item {
                width: _root.width; height: 25
                visible: _mouseArea.showElements

                Text {
                    text: model.name
                    leftPadding: 10
                    height: parent.height; width: implicitWidth
                    anchors.left: parent.left
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    text: model.value
                    height: parent.height; width: implicitWidth
                    anchors { right: parent.right; rightMargin: 2 }
                    verticalAlignment: Text.AlignVCenter
                }
            }
        } // Repeater
    } // Column

    MouseArea {
        property bool showElements: false
        id: _mouseArea
        anchors.fill: parent
        onClicked: showElements = !showElements
    }
} // Rectangle
