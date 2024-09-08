import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import data.types
import core.source 1.0

Item {
    property TrickSource source: null

    id: _root

    signal add(source: TrickSource)
    signal close()

    ColumnLayout {
        width: _root.width

        onImplicitHeightChanged: _root.implicitHeight = implicitHeight

        Label {
            id: _name
            text: source?.name ?? ""
            font.bold: true
            font.pointSize: 14
            color: "#000"
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        } // Label

        RowLayout {
            Layout.fillWidth: true

            Text {
                text: "Wymagania: "
                font.bold: true
                font.pointSize: 12
                Layout.alignment: Qt.AlignTop
            } // Text
            Flow {
                spacing: 2
                Layout.fillWidth: true
                Repeater {
                    model: source?.requirements ?? []
                    delegate: Text {
                        text: model.name + (model.type !== Types.Requirement.Profession ? " " + model.value : "")
                                + (index+1 === source?.requirements.length ? "" : ", ")
                        font.pointSize: 12
                    }
                }
            } // Flow
        } // RowLayout

        RowLayout {
            Text {
                text: "Opis: "
                font.bold: true
                font.pointSize: 12
                Layout.alignment: Qt.AlignTop
            }
            Text {
                text: source?.description ?? ""
                font.pointSize: 12
                wrapMode: Text.WordWrap
                Layout.fillWidth: true
            }
        } // RowLayout

        RowLayout {
            Text {
                text: "Akcja: "
                font.bold: true
                font.pointSize: 12
                Layout.alignment: Qt.AlignTop
            }
            Text {
                text: source?.action ?? ""
                font.pointSize: 12
                wrapMode: Text.WordWrap
                Layout.fillWidth: true
            }
        } // RowLayout

        Button {
            text: "Zamknij"
            Layout.preferredHeight: 40
            onClicked: _root.close()
            Layout.alignment:  Qt.AlignBottom | Qt.AlignRight
            Layout.bottomMargin: 10
        } // Button

    } // ColumnLayout
} // Item
