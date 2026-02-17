import QtQuick
import QtQuick.Layouts

import core.source 1.0

Item {
    property ArmorSource armor: null

    id: _root

    Column {
        spacing: 5
        onImplicitHeightChanged: _root.implicitHeight = implicitHeight

        RowLayout {
            width: _root.width
            spacing: 5

            Text {
                text: "Kara:"
                font.bold: true
                font.pointSize: 12
            }

            Text {
                text: armor?.penalty ?? ""
                font.pointSize: 12
            }

            Item {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                text: "Wytrzymałość:"
                font.bold: true
                font.pointSize: 12
            }

            Text {
                text: armor?.durability ?? ""
                font.pointSize: 12
            }
        } // RowLayout

        RowLayout {
            width: _root.width
            spacing: 5

            Text {
                text: "Lokacje:"
                font.bold: true
                font.pointSize: 12
                Layout.alignment: Qt.AlignTop
            }

            Flow {
                Layout.fillWidth: true
                spacing: 5

                Repeater {
                    model: armor?.defence ?? []
                    delegate: Text {
                        text: model.location + " " + model.value
                              + (model.cutting === 0 ? " (nie dotyczy tnących)" :
                                    (model.value !== model.cutting) ? " (" + model.cutting + " tnące)" : "")
                              + (index < armor?.defence.length-1 ? ", " : "")
                        font.pointSize: 12
                    }
                }
            }
        } // RowLayout
    } // Column
} // Item
