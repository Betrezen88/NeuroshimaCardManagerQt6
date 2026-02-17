import QtQuick
import QtQuick.Layouts

import core.source 1.0

import "../../../Common"

Item {
    property HandWeaponSource handWeapon: null

    id: _root

    Column {
        onImplicitHeightChanged: _root.implicitHeight = implicitHeight

        RowLayout {
            width: _root.width
            spacing: 5

            Text {
                text: "Wymagania:"
                font.pointSize: 12
                font.bold: true
                visible: handWeapon?.requirement?.value > 0
            }
            Text {
                text: {
                    var result = handWeapon?.requirement?.attribute ?? ""
                    result += " " + handWeapon?.requirement?.value ?? ""
                    return result
                }
                font.pointSize: 12
                visible: handWeapon?.requirement?.value > 0
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            Text {
                text: "Przebicie pancerza:"
                font.pointSize: 12
                font.bold: true
                visible: handWeapon?.penetration > 0
            }
            Text {
                text: handWeapon?.penetration ?? ""
                font.pointSize: 12
                visible: handWeapon?.penetration > 0
            }
        } // Row

        Row {
            visible: handWeapon?.bonuses.length > 0
            spacing: 5

            Text {
                text: "Bonusy:"
                font.pointSize: 12
                font.bold: true
            }

            Repeater {
                model: handWeapon?.bonuses ?? []
                delegate: Text {
                    text: model.name + " +"  + model.value
                    font.pointSize: 12
                }
            }
        } // Row

        Row {
            spacing: 5

            Text {
                text: "Obrażenia:"
                font.pointSize: 12
                font.bold: true
                visible: handWeapon?.damages.length > 0
            }

            Column {
                spacing: 3

                Repeater {
                    model: handWeapon?.damages ?? []
                    delegate: Text {
                        text: {
                            var result = ""
                            if ( model.value > 1 )
                                result += model.attribute + ": " + model.value + " "
                            result += "("
                            for ( var w in model.wounds ) {
                                result += model.wounds[w][0]
                                if ( w < model.wounds.length-1 )
                                    result += " / "
                            }
                            result += ")"
                            return result
                        }
                        font.pointSize: 12
                    }
                }
            } // Column
        } // Row

        Row {
            spacing: 5
            visible: handWeapon?.specials.length > 0

            Text {
                text: "Reguły specjalne:"
                font.pointSize: 12
                font.bold: true
            }

            Flow {
                Repeater {
                    model: handWeapon?.specials ?? []
                    delegate: Text {
                        text: model.name + (index < handWeapon?.specials.length-1 ? "," : "")
                        font.pointSize: 12

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                _specialPopup.contentText = model.description
                                _specialPopup.x = mouseX
                                _specialPopup.y = mouseY + 10
                                _specialPopup.parent = parent
                                _specialPopup.open()
                            }
                        }
                    }
                }
            } // Flow
        } // Row

    } // Column

    TooltipPopup {
        property string contentText: ""

        id: _specialPopup

        contentItem: Text {
            text: _specialPopup.contentText
            font.pointSize: 11
            wrapMode: Text.WordWrap
        }

        onOpened: _specialPopup.width = contentItem.width > 400 ? 400 : contentItem.width
        onClosed: _specialPopup.contentText = ""
    }

} // Item
