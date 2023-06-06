import QtQuick
import QtQuick.Controls

Item {
    property alias title: _title.text
    property string requirements
    property string description
    property string action
    property int maxHeight

    id: _root

    height: (_title.height + _scrollContent.height > maxHeight)
                ? maxHeight
                : _title.height + _scrollContent.height

    Column {
        id: _column

        Text {
            id: _title
            width: _root.width
            font.pointSize: 12
            font.bold: true
            padding: 5
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
        }

        ScrollView {
            width: _root.width; height: _root.height - _title.height

            Column {
                id: _scrollContent
                spacing: 5

                Text {
                    id: _requirements
                    width: _root.width
                    text: "<b>Wymagania:</b> " + _root.requirements
                    font.pointSize: 10
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: _description
                    width: _root.width
                    text: "<b>Opis:</b><i> " + _root.description + "</i>"
                    font.pointSize: 10
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: _action
                    width: _root.width
                    text: "<b>Akcja:</b> " + _root.action
                    font.pointSize: 10
                    wrapMode: Text.WordWrap
                }
            }
        } // Scrollview
    } // Column

} // Item
