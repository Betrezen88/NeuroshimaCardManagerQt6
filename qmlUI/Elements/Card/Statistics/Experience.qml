import QtQuick
import QtQuick.Controls

import core.view

Rectangle {
    property Experience experience: null

    id: _root

    color: "#FFF"
    border.width: 2
    border.color: "#000"

    Grid {
        columns: 2
        spacing: 5
        padding: 5

        Text {
            text: qsTr("Dostepne:")
            height: _available.height
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
        }
        Label {
            id: _available
            text: experience != null ? experience.left() : 0
            width: 210
            padding: 5
            color: "#000"
            font.pointSize: 12
            horizontalAlignment: Text.AlignRight
            background: Rectangle {
                border.width: 2
                border.color: "#000"
                radius: 5
            }
        }

        Text {
            text: qsTr("Wydane:")
            height: _spended.height
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
        }
        Label {
            id: _spended
            text: experience != null ? experience.spended : 0
            width: 210
            padding: 5
            color: "#000"
            font.pointSize: 12
            horizontalAlignment: Text.AlignRight
            background: Rectangle {
                border.width: 2
                border.color: "#000"
                radius: 5
            }
        }

        Text {
            text: qsTr("Zdobyte:")
            height: _gathered.height
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
        }
        Label {
            id: _gathered
            text: experience != null ? experience.gathered : 0
            width: 210
            padding: 5
            color: "#000"
            font.pointSize: 12
            horizontalAlignment: Text.AlignRight
            background: Rectangle {
                border.width: 2
                border.color: "#000"
                radius: 5
            }
        }

        onImplicitHeightChanged: _root.height = implicitHeight

        Connections {
            target: _root.experience
            function onGatheredChanged() {
                _available.text = _root.experience.left()
            }
        }

    } // Grid
} // Rectangle
