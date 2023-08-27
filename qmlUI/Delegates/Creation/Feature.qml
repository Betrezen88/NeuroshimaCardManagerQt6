import QtQuick
import QtQuick.Controls

Item {
    property var buttonGroup

    id: _root

    height: _column.implicitHeight

    Column {
        id: _column

        RadioButton {
            id: _name
            height: 40
            text: "Urodzony morderca"
            contentItem: Text {
                text: _name.text
                font.bold: true
                font.pointSize: 12
                color: "#000"
                leftPadding: _name.indicator.width + _name.spacing
                verticalAlignment: Text.AlignVCenter
            }
            ButtonGroup.group: _root.buttonGroup
        }

        Text {
            id: _description
            text: "Wyrzuciliby Cię z Areny za szczególne bestialstwo. Wybierz sobie dowolny pakiet Umiejętności Wojownika. Wszystkie umiejętności z paczki posiadasz na poziomie +2."
            font.pointSize: 12
            wrapMode: Text.WordWrap
            width: _root.width
        }
    } // Column

} // Item
