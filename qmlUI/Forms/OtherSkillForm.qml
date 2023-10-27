import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import "../Elements/Card/Common"

Item {
    property alias attributes: _attributes.model

    id: _root

    signal accepted(name: string, attribut: string, description: string)
    signal rejected()

    GridLayout {
        columns: 5
        columnSpacing: 5
        rowSpacing: 5

        TextField {
            id: _name
            placeholderText: "Nazwa umiejętności"
            font.pointSize: 12
            Layout.preferredWidth: 200
            Layout.preferredHeight: 40
            Layout.columnSpan: 3
        }

        ComboBox {
            id: _attributes
            font.pointSize: 12
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40
            Layout.columnSpan: 2
        }

        ScrollTextArea {
            id: _description
            Layout.preferredHeight: 100
            Layout.preferredWidth: _name.width + parent.columnSpacing + _attributes.width
            Layout.columnSpan: 5
        }

        Button {
            text: "Anuluj"
            Layout.preferredHeight: 40
            Layout.preferredWidth: 100
            Layout.columnSpan: 2
            onClicked: _root.rejected()
        }

        Item {
            width: 1; height: 1
            Layout.columnSpan: 1
        }

        Button {
            text: "Dodaj"
            Layout.preferredHeight: 40
            Layout.preferredWidth: 100
            Layout.columnSpan: 2
            onClicked: _root.accepted(_name.text, _attributes.currentText, _description.text)
        }
    } // GridLayout

    function clear() {
        _name.clear()
        _description.text = ""
        _attributes.currentIndex = 0
    }
} // Item
