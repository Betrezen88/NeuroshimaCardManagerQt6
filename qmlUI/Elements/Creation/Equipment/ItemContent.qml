import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.source
import data.types

Item {
    property ItemSource itemSource: null

    id: _root

    signal close()
    signal itemBougth(itemSource: ItemSource)

    Column {
        id: _column
        spacing: 5

        onImplicitHeightChanged: _root.implicitHeight = implicitHeight

        Label {
            id: _title
            text: itemSource?.name ?? ""
            color: "#000"
            font.bold: true
            font.pointSize: 14
            horizontalAlignment: Qt.AlignHCenter
            width: _root.width
        }

        RowLayout {
            width: _root.width
            spacing: 5

            Text {
                text: "Cena:"
                font.bold: true
                font.pointSize: 12
            }

            Text {
                text: itemSource?.price + (itemSource?.price === 1 ? " gambel" : itemSource?.price < 5 ? " gamble" : " gambli") ?? ""
                font.pointSize: 12
            }

            Item {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                text: "Szansa:"
                font.bold: true
                font.pointSize: 12
            }

            Text {
                text: itemSource?.availability + "%" ?? 0 + "%"
                font.pointSize: 12
            }
        } // RowLayout

        HandWeaponContent {
            handWeapon: itemSource?.type === Types.Item.HandWeapon ? itemSource : null
            visible: itemSource?.type === Types.Item.HandWeapon
            width: _root.width
        }

        ShieldContent {
            shieldSource: itemSource?.type === Types.Item.Shield ? itemSource : null
            visible: itemSource?.type === Types.Item.Shield
            width: _root.width
        }

        RangeWeaponContent {
            rangeWeapon: itemSource?.type === Types.Item.RangeWeapon ? itemSource : null
            visible: itemSource?.type === Types.Item.RangeWeapon
            width: _root.width
        }

        ArmorContent {
            armor: itemSource?.type === Types.Item.Armor ? itemSource : null
            visible: itemSource?.type === Types.Item.Armor
            width: _root.width
        }

        Text {
            id: _description
            width: _root.width
            text: itemSource?.description ?? ""
            wrapMode: Text.WordWrap
            horizontalAlignment: Qt.AlignJustify
            font.pointSize: 12
            font.italic: true
            topPadding: 10
        } // Text

        RowLayout {
            width: _root.width
            height: 40

            Button {
                text: "Zamknij"
                Layout.fillHeight: true
                onClicked: _root.close()
            }

            Item {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Button {
                text: "Kup"
                Layout.fillHeight: true
                onClicked: _root.itemBougth(itemSource)
            }
        } // RowLayout

        Item {
            height: 5
            width: _root.width
        } // Item spacer
    } // ColumnLayout

} // Item
