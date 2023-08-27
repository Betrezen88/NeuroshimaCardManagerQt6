import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../../Elements/Card/Common"
import "../../Elements/Creation/Diseases"

Page {
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

            Text {
                id: _name
                text: "Nazwa choroby"
                font.bold: true
                font.pointSize: 14
            }

            Text {
                id: _diseaseDescription
                text: "Opis choroby."
                font.pointSize: 14
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
            }

            Text {
                id: _cure
                text: "Opis kroku losowania choroby."
                font.pointSize: 14
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
            }

            Text {
                text: "Symptomy"
                font.bold: true
                font.pointSize: 14
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
            }

            Flow {
                spacing: 20
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)

                Repeater {
                    model: [ "Pierwsze symptomy", "Stan ostry", "Stan krytyczny", "Stan terminlny" ]

                    delegate: Symptom {
                        width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2) < 700 ? 250 : 350
                        name: modelData
                        description: "Opis"
                        penalties: "-1 Zręczność, +30% Kondycja"
                    } // Item
                }
            } // Flow

        } // Column

    } // ScrollView

    ColumnLayout {
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

            model: ListModel {
                ListElement { name: "Zwapnienie płut" }
                ListElement { name: "Gorączka sobotniej nocy" }
                ListElement { name: "Przewlekła gorączka krwotoczna" }
                ListElement { name: "Mount Rushmore" }
                ListElement { name: "Syndrom Obcego" }
                ListElement { name: "Chore Nery" }
                ListElement { name: "Alergie" }
                ListElement { name: "Szaleństwo bostońskie" }
                ListElement { name: "Syndrom Thrumana (matołek)" }
                ListElement { name: "Drgawki" }
                ListElement { name: "Hemofilia" }
                ListElement { name: "Drętwota Hollywood" }
                ListElement { name: "Osteoporoza" }
                ListElement { name: "Zawroty głowy" }
                ListElement { name: "Niewydolność krążenia" }
                ListElement { name: "Anemia" }
                ListElement { name: "Morbius Dexteri (amnezje)" }
                ListElement { name: "Syndrom Draculi (światłowstręt)" }
                ListElement { name: "Zespół wirusowej horoby języka (VTDS)" }
                ListElement { name: "Paranoja" }
            }

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
