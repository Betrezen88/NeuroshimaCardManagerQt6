import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    property alias wounds: _wound.model
    property alias locations: _location.model

    id: _root

    signal accepted(wound: string, location: string, penalty: int)
    signal rejected()

    GridLayout {
        columns: 2
        columnSpacing: 5
        rowSpacing: 5

        Text {
            text: "Rana"
            Layout.preferredHeight: 40
            verticalAlignment: Text.AlignVCenter
            font{ bold: true; pointSize: 12 }
        }

        ComboBox {
            id: _wound
            font.pointSize: 12
            Layout.preferredHeight: 40
            Layout.preferredWidth: 150
        }

        Text {
            text: "Lokacja"
            Layout.preferredHeight: 40
            verticalAlignment: Text.AlignVCenter
            font{ bold: true; pointSize: 12 }
        }

        ComboBox {
            id: _location
            font.pointSize: 12
            Layout.preferredHeight: 40
            Layout.preferredWidth: 150
        }

        Text {
            text: "Kara"
            Layout.preferredHeight: 40
            verticalAlignment: Text.AlignVCenter
            font{ bold: true; pointSize: 12 }
        }

        SpinBox {
            id: _penalty
            from: 1; to: 200
            Layout.preferredHeight: 40
            Layout.preferredWidth: 150
        }

        Button {
            text: "Anuluj"
            Layout.preferredHeight: 40
            Layout.preferredWidth: 150
            onClicked: _root.rejected()
        }

        Button {
            text: "Dodaj"
            Layout.preferredHeight: 40
            Layout.preferredWidth: 150
            Layout.alignment: Qt.AlignRight
            onClicked: _root.accepted(_wound.currentText, _location.currentText, _penalty.value)
        }
    } // GridLayout
} // Item
