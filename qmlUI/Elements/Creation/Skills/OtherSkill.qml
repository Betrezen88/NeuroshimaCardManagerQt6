import QtQuick
import QtQuick.Controls

import core.creation 1.0

import "../../../Common"
import "../../../Elements/Card/Common"

Item {
    property OtherSkillCreation source

    id: _root

    signal remove()

    Row {
        spacing: 5
        padding: 5

        onImplicitHeightChanged: _root.height = implicitHeight

        Button {
            id: _info

            width: _value.height
            height: _value.height

            background: Image {
                source: "qrc:/Images/icons/info.svg"
            }

            TooltipPopup {
                id: _tooltip

                contentItem: TooltipContent {
                    width: 300
                    title: source?.source?.name ?? ""
                    description: source?.source?.description ?? ""
                }
            }

            onClicked: {
                if (_tooltip.opened)
                    _tooltip.close()
                else {
                    _tooltip.y = -(_info.height/2) - _tooltip.contentItem.height
                    _tooltip.open()
                }
            }
        } // Button

        Text {
            id: _name
            text: source?.source?.name ?? ""
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            width: _root.width - _info.width - _attribute.width - _value.width - _removeBtn.width - (parent.spacing*4) - (parent.padding*2)
            height: implicitHeight > _value.height ? implicitHeight : _value.height
        }

        Text {
            id: _attribute
            text: source?.attributeShort ?? "--"
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
            height: _value.height
        }

        SpinBox {
            id: _value
            width: 90
            from: source?.min ?? 0
            to: source?.max ?? 0
            value: source?.value ?? 0

            up.onPressedChanged: {
                if ( up.pressed && source !== null ) {
                    source.increase()
                    up.pressed = false
                }
            }

            down.onPressedChanged: {
                if ( down.pressed && source !== null) {
                    source.decrease()
                    down.pressed = false
                }
            }
        } // SpinBox

        Button {
            id: _removeBtn
            width: _value.height
            height: _value.height

            background: Image {
                source: "qrc:/Images/icons/remove.svg"
            }

            onClicked: _root.remove()
        } // Button

    } // Row

} // Item
