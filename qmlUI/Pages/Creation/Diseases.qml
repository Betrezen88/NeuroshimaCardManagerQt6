import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.creation 1.0
import core.source 1.0

import "../../Elements/Card/Common"
import "../../Elements/Creation/Diseases"

Page {
    property CardCreation cardCreation: null

    id: _root

    ScrollView {
        id: _scrollView

        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
            right: _rightPanel.left
            margins: 5
        }

        Column {
            spacing: 5

            Text {
                id: _description
                text: "Opis kroku losowania choroby."
                font.pointSize: 14
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
            }

            Item { width: 5; height: 5 }

            Text {
                id: _name
                text: _rightPanel.disease?.name ?? ""
                font.bold: true
                font.pointSize: 14
                horizontalAlignment: Text.AlignHCenter
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
            }

            Text {
                id: _diseaseDescription
                text: _rightPanel.disease?.description ?? ""
                wrapMode: Text.WordWrap
                font.pointSize: 14
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
            }

            Text {
                id: _cure
                text: _rightPanel.disease?.cure ?? ""
                wrapMode: Text.WordWrap
                font.pointSize: 14
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
            }

            Text {
                text: "Symptomy"
                font.bold: true
                font.pointSize: 14
                horizontalAlignment: Text.AlignHCenter
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
            }

            Flow {
                spacing: 20
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)

                Repeater {
                    model: _rightPanel.disease?.symptoms ?? []

                    delegate: Symptom {
                        width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2) < 700 ? 250 : 350
                        symptom: modelData
                    } // Item
                }
            } // Flow

        } // Column

    } // ScrollView

    ColumnLayout {
        property DiseaseSource disease: null

        id: _rightPanel

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
        }

        Label {
            text: "Choroby"
            color: "#000"
            font.bold: true
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.preferredHeight: 40
            Layout.preferredWidth: 150
            Layout.alignment: Qt.AlignTop
        }

        ListView {
            id: _origins
            spacing: 5
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: cardCreation?.statisticsSource?.diseases ?? []

            delegate: Rectangle {
                width: ListView.view.width; height: 40
                color: "lightgray"

                Text {
                    text: model.name
                    width: parent.width; height: parent.height
                    wrapMode: Text.WordWrap
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _rightPanel.disease = model.modelData
                    }
                }
            }
        } // ListView

        Button {
            text: "Losuj"
            Layout.preferredHeight: 50
            Layout.fillWidth: true
        }
    } // ColumnLayout

    background: Rectangle {
        color: "#fff"
    }
} // Page
