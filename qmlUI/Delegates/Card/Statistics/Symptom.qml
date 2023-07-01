import QtQuick

import data.types
import core.view

Item {
    property Symptom symptom: null

    id: _root

    height: _column.implicitHeight

    Column {
        id: _column
        spacing: 5

        Text {
            text: "<b>" + symptom.name + "</b> - " + symptom.description
            width: _root.width
            font.pointSize: 10
            wrapMode: Text.WordWrap
        }

        Flow {
            spacing: 5

            Repeater {
                model: symptom.penalties

                delegate: Text {
                    text: ((modelData.value > 0) ? "+" : "") + modelData.value
                        + ((modelData.type === Types.Modifier.Test) ? "%" : "")
                        + " " + modelData.name
                        + (index+1 < symptom.penalties.length ? "," : "")
                    font.pointSize: 10
                }
            }
        }
    } // Column

} // Item
