import QtQuick
import QtQuick.Layouts

import data.types 1.0
import core.source 1.0

Item {
    property SymptomSource symptom: null

    id: _root

    ColumnLayout {
        width: _root.width
        spacing: 5

        onImplicitHeightChanged: _root.height = implicitHeight

        Text {
            id: _name
            text: symptom?.name ?? ""
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }

        Text {
            id: _description
            text: symptom?.description ?? ""
            font.pointSize: 12
            font.italic: true
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignJustify
            Layout.fillWidth: true
        }

        Flow {
            spacing: 5
            Layout.fillWidth: true

            Repeater {
                id: _penalties
                model: symptom?.penalties ?? []
                delegate: Text {
                    text: (model.value > 0 ? "+" : "") + model.value + (model.type === Types.Modifier.Test ? "%" : "") + " " + model.name + (index < _penalties.count-1 ? ", " : "")
                    font.pointSize: 10
                    font.bold: true
                    font.italic: true
                }
            }
        }
    } // Column
} // Item
