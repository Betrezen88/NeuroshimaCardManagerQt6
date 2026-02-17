import QtQuick
import QtQuick.Layouts

import core.source

import "../../../Common"

Item {
    property RangeWeaponSource rangeWeapon: null
    id: _root

    Column {
        spacing: 5
        onImplicitHeightChanged: _root.implicitHeight = implicitHeight

        Row {
            width: _root.width
            spacing: 5

            Text {
                text: "Wymagania:"
                font.pointSize: 12
                font.bold: true
                visible: rangeWeapon?.requirement?.value > 0
            }
            Text {
                text: {
                    var result = rangeWeapon?.requirement?.attribute ?? ""
                    result += " " + rangeWeapon?.requirement?.value ?? ""
                    return result
                }
                font.pointSize: 12
                visible: rangeWeapon?.requirement?.value > 0
            }
        } // Row

        RowLayout {
            width: _root.width
            spacing: 5

            Text {
                text: "Obrażenia:"
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: rangeWeapon?.damage ?? ""
                font.pointSize: 12
            }

            Item {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                text: "Przebicie pancerza:"
                font.pointSize: 12
                font.bold: true
                visible: rangeWeapon?.penetration > 0
            }
            Text {
                text: rangeWeapon?.penetration ?? ""
                font.pointSize: 12
                visible: rangeWeapon?.penetration > 0
            }
        } // RowLayout

        RowLayout {
            width: _root.width
            spacing: 5

            Text {
                text: "Amunicja:"
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: {
                    var result = ""
                    for ( var a in rangeWeapon?.ammunition ) {
                        result += rangeWeapon.ammunition[a]
                        if ( a < rangeWeapon.ammunition.length-1 )
                            result += ", "
                    }
                    return result
                }
                font.pointSize: 12
            }

            Item {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                text: "Szybkostrzelność:"
                font.pointSize: 12
                font.bold: true
                visible: rangeWeapon?.firerate > 0
            }
            Text {
                text: rangeWeapon?.firerate ?? ""
                font.pointSize: 12
                visible: rangeWeapon?.firerate > 0
            }
        } // RowLayout

        Row {
            spacing: 5

            Text {
                text: "Magazynek:"
                font.pointSize: 12
                font.bold: true
                visible: rangeWeapon?.magazine.length > 0
            }

            Text {
                text: {
                    var result = ""
                    for ( var m in rangeWeapon?.magazine ) {
                        result += rangeWeapon?.magazine[m]
                        if ( m < rangeWeapon?.magazine.length-1 )
                            result += ", "
                    }
                    return result
                }
                font.pointSize: 12
                visible: rangeWeapon?.magazine.length > 0
            }
        } // Row

        RowLayout {
            width: _root.width
            spacing: 5
            visible: rangeWeapon?.specials.length > 0

            Text {
                text: "Reguły specjalne:"
                font.pointSize: 12
                font.bold: true
                Layout.alignment: Qt.AlignTop
            }

            Flow {
                Layout.fillWidth: true
                spacing: 5

                Repeater {
                    model: rangeWeapon?.specials ?? []
                    delegate: Text {
                        text: model.name + (index < rangeWeapon?.specials.length-1 ? "," : "")
                        font.pointSize: 12

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
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
    } // TooltipPopup

} // Item
