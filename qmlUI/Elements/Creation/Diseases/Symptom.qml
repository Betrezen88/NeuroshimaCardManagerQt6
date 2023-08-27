import QtQuick
import QtQuick.Layouts

Item {
    property alias name: _name.text
    property alias description: _description.text
    property alias penalties: _penalties.text

    id: _root

    ColumnLayout {
        width: _root.width
        spacing: 5

        onImplicitHeightChanged: _root.height = implicitHeight

        Text {
            id: _name
            text: modelData
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }

        Text {
            id: _description
            font.pointSize: 12
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignJustify
            Layout.fillWidth: true
        }

        Text {
            id: _penalties
            font.pointSize: 12
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }
    } // Column
} // Item
