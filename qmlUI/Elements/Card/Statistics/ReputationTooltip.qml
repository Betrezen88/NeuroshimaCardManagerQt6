import QtQuick
import QtQuick.Controls

Item {
    property alias title: _title.text
    property alias places: _places.model

    id: _root

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
            clip: true

            Column {
                spacing: 5

                Repeater {
                    id: _places

                    delegate: Row {
                        Text {
                            text: model.name
                            padding: 5
                            font.pointSize: 12
                            width: 200
                        }

                        Text {
                            text: model.value
                            padding: 5
                            font.pointSize: 12
                            width: 40
                        }
                    }
                }
            }
        } // ScrollView
    } // Column
} // Item
