import QtQuick
import QtQuick.Controls

import core.creation 1.0
import creation.types 1.0

Item {
    property SkillCreation skill: null

    id: _root

    Row {
        spacing: 5
        leftPadding: 5

        onImplicitHeightChanged: _root.height = implicitHeight

        Item {
            id: _name
            height: _value.height
            width: implicitContentWidth

            Text {
                text: skill !== null ? skill.source.name : ""
                font.pointSize: 12
                visible: skill.type === CreationTypes.Single
            } // Text

            ComboBox {
                model: skill !== null ? skill.list : []
                displayText: skill !== null ? skill.selected : ""
                font.pointSize: 12
                visible: skill.type === CreationTypes.List
                onCurrentTextChanged: {
                    if ( skill !== null ) {
                        skill.selected = currentText
                    }
                }
            } // ComboBox
        } // Item

        Item {
            height: 1; width: _root.width - _name.width - _value.width - (parent.spacing*3) - parent.leftPadding
        }

        SpinBox {
            id: _value
            from: skill !== null ? skill.min : 0
            to: skill !== null ? skill.max : 5
            value: skill !== null ? skill.value : 0

            up.onPressedChanged: {
                if ( up.pressed && skill !== null ) {
                    skill.increase()
                    up.pressed = false
                }
            }

            down.onPressedChanged: {
                if ( down.pressed && skill !== null) {
                    skill.decrease()
                    down.pressed = false
                }
            }
        } // SpinBox
    } // Row
} // Item
