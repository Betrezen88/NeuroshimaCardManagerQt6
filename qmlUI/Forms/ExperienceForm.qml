import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: _root

    signal accepted(value: int)
    signal rejected()

    GridLayout {
        columns: 2
        columnSpacing: 5

        Text {
            text: "Przynane doświadczenie"
            Layout.preferredHeight: 40
            Layout.columnSpan: 2
            Layout.fillWidth: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font{ bold: true; pointSize: 12 }
        }

        SpinBox {
            id: _value
            editable: true
            from: 1; to: 10000
            font.pointSize: 12
            Layout.columnSpan: 2
            Layout.preferredHeight: 40
            Layout.fillWidth: true
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
            onClicked: _root.accepted(_value.value)
        }
    }
} // Item
