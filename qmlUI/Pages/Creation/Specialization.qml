import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

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
            spacing: 10

            Text {
                text: "Wojownik"
                font.bold: true
                font.pointSize: 16
                verticalAlignment: Text.AlignVCenter
                height: 40
                width: _root.width - _rightPanel.width - 50
            }

            Text {
                text: "Opis specjalizacji"
                font.pointSize: 14
                wrapMode: Text.WordWrap
                width: _root.width - _rightPanel.width - 50
            }

            Text {
                text: "Dodatkowy opis mechaniki związanej ze specjalizacją"
                font.pointSize: 14
                wrapMode: Text.WordWrap
                width: _root.width - _rightPanel.width - 50
            }
        }

    } // ScrollView

    ColumnLayout {
        id: _rightPanel

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
        }

        Label {
            text: "Specjalizacje"
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
            id: _specializations
            spacing: 5
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: ListModel {
                ListElement { name: "Wojownik" }
                ListElement { name: "Ranger" }
                ListElement { name: "Cwniak" }
                ListElement { name: "Technik" }
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
    } // ColumnLayout

    background: Rectangle {
        color: "#fff"
    }
} // Page
