import QtQuick
import QtQuick.Controls

import data.types 1.0
import core.source 1.0

Item {
    property var buttonGroup
    property FeatureSource source: null
    property alias selected: _name.checked

    id: _root

    height: _column.implicitHeight

    Column {
        id: _column

        RadioButton {
            id: _name
            height: 40
            text: source !== null ? source.name : ""
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
            text: source !== null ? source.description : ""
            font.pointSize: 12
            wrapMode: Text.WordWrap
            width: _root.width
        }

        ComboBox {
            id: _skillpackSelection
            model: source.bonus !== null && (source.bonus.type === Types.Bonus.Skillpack || source.bonus.type === Types.Bonus.Skillpack)
                   ? source.bonus.list : []
            font.pointSize: 12
            width: 180; height: 35
            visible: source.bonus !== null && (source.bonus.type === Types.Bonus.Skillpack || source.bonus.type === Types.Bonus.Skillpack)
            onCurrentTextChanged: {
                if ( selected && visible ) {
                    source.bonus.selected = currentText
                }
            }
        }
    } // Column

    onSelectedChanged: {
        if ( selected && _skillpackSelection.visible ) {
            source.bonus.selected = _skillpackSelection.currentText
        }
    }

} // Item
