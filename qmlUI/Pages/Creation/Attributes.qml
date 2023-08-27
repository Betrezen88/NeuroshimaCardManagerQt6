import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../../Delegates/Creation"

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
                text: "Atrybuty"
                font.bold: true
                font.pointSize: 16
                verticalAlignment: Text.AlignVCenter
                width: _root.width - _rightPanel.width - 10
            }

            Text {
                id: _description
                text: "Przypisanie - metoda pozwala na własnoręczne pisanie wartości atrybutów. Weź 3k20 i rzuć. Zsumuj wynik i wyciągnij średnią zaokrąglając w górę. Wykonaj to 6 razy i odrzuć najmniejszy wynik. Jeśli wyrzucisz wynik mniejszy niż 6 to nie pękaj, tylko wpisz 6."
                bottomPadding: 20
                font.pointSize: 14
                wrapMode: Text.WordWrap
                verticalAlignment: Text.AlignJustify
                width: _root.width - _rightPanel.width - 10
            }

            Repeater {
                model: ["Budowa", "Zręczność", "Charakter", "Spryt", "Percepcja"]

                delegate: AttributeValue {
                    name: modelData
                }
            } // Repeater

            Item { width: 1; height: 20 }

            Grid {
                columns: 2
                spacing: 5

                Repeater {
                    model: ["Budowa", "Zręczność", "Charakter", "Percepcja", "Spryt"]

                    delegate: AttributeDescription {
                        name: modelData
                        width: (_root.width - _rightPanel.width - 15)/2
                    }
                }
            } // Grid

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
            text: "Metoda"
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
            id: _styles
            spacing: 5
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: ListModel {
                ListElement { name: "Przypisanie" }
                ListElement { name: "Losowanie" }
                ListElement { name: "Punkty" }
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
