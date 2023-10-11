import QtQuick
import QtQuick.Controls

import "../../../Delegates/Card/Statistics"

Item {
    property alias title: _title.text
    property string description
    property string cure
    property alias symptoms: _symptoms.model
    property int defaultWidth: 0
    property int defaultHeight: 0

    id: _root

    onVisibleChanged: {
        width = defaultWidth
        height = defaultHeight
    }

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
                spacing: 5

                Text {
                    id: _description
                    width: _root.width
                    text: "<b>Opis:</b> " + _root.description
                    font.pointSize: 10
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: _cure
                    width: _root.width
                    text: "<b>Lekarstwo:</b> " + _root.cure
                    font.pointSize: 10
                    wrapMode: Text.WordWrap
                }

                Text {
                    width: _root.width
                    text: "Kary"
                    font.pointSize: 12
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }

                Repeater {
                    id: _symptoms
                    delegate: Symptom {
                        width: _root.width
                        symptom: modelData
                    }
                } // Repeater

            } // Column
        } // Scrollview
    } // Column

} // Item
