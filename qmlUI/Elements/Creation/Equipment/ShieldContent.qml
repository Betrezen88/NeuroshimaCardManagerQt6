import QtQuick
import QtQuick.Layouts

import core.source 1.0

Item {
    property ShieldSource shieldSource: null

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
                visible: shieldSource?.requirement?.value > 0
            }
            Text {
                text: {
                    var result = shieldSource?.requirement?.attribute ?? ""
                    result += shieldSource?.requirement?.value ?? ""
                    return result
                }
                font.pointSize: 12
                visible: shieldSource?.requirement?.value > 0
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            Text {
                text: "Wytrzymałość:"
                font.bold: true
                font.pointSize: 12
            }

            Text {
                text: shieldSource?.durability ?? ""
                font.pointSize: 12
            }
        } // RowLayout

        Row {
            visible: shieldSource?.bonuses.length > 0
            spacing: 5

            Text {
                text: "Bonusy:"
                font.pointSize: 12
                font.bold: true
            }

            Repeater {
                model: shieldSource?.bonuses ?? []
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
                visible: shieldSource?.damage !== null
            }

            Text {
                text: {
                    var result = ""
                    if ( shieldSource?.damage?.value > 1 )
                        result += shieldSource?.damage.attribute + ": " + shieldSource?.damage.value + " "
                    result += "("
                    for ( var w in shieldSource?.damage.wounds ) {
                        result += shieldSource?.damage.wounds[w][0]
                        if ( w < shieldSource?.damage.wounds.length-1 )
                            result += " / "
                    }
                    result += ")"
                    return result
                }
                font.pointSize: 12
            }
        } // Row

    } // Column

} // Item
