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
        Label {
            text: source?.name ?? ""
            font.bold: true
            font.pointSize: 14
            color: "#000"
            Layout.alignment: Qt.AlignHCenter
        } // Label

        RowLayout {
            Layout.preferredWidth: _root.width
            Text {
                text: "Wymagania: "
                font.bold: true
                font.pointSize: 12
                Layout.alignment: Qt.AlignTop
            } // Text
            Flow {
                spacing: 2
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignLeft
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
            Layout.preferredWidth: _root.width
            Text {
                text: "Opis: "
                font.bold: true
                font.pointSize: 12
                Layout.fillWidth: true
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
            Layout.preferredWidth: _root.width
            Text {
                text: "Akcja: "
                font.bold: true
                font.pointSize: 12
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignTop
            }
            Text {
                text: source?.action ?? ""
                font.pointSize: 12
                wrapMode: Text.WordWrap
                Layout.fillWidth: true
            }
        } // RowLayout

        RowLayout {
            Layout.preferredWidth: _root.width

            Button {
                text: "Zamknij"
                Layout.preferredHeight: 40
                Layout.alignment: Qt.AlignLeft
                onClicked: _root.close()
            }
            Button {
                text: "Dodaj"
                Layout.preferredHeight: 40
                Layout.alignment: Qt.AlignRight
                onClicked: _root.add(_root.source)
            }
        } // RowLayout
    } // ColumnLayout

} // Item
