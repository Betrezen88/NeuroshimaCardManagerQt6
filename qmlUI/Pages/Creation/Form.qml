import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.creation 1.0

import "../../Elements/Creation/Form"

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
            spacing: 15

            Text {
                text: "Teraz zadam Ci kilka pytań, odpowiedz na nie, a możesz być pewny, że będzie Ci się lepiej grało. Razem spróbujemy zastanowić się, co za typa tworzysz. Jeśli chwilę pokombinujesz i postarasz się w miarę sensownie odpowiadać na pytania, które Ci zadam, możesz być pewien, że wyjdzie to wszystko na dobre. Posłuchaj..."
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
                font.pointSize: 14
                wrapMode: Text.WordWrap
                verticalAlignment: Text.AlignJustify
            }

            Repeater {
                model: cardCreation?.statisticsCreation?.answers ?? []

                delegate: Question {
                    number: (index+1)
                    answer: modelData
                    width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
                }
            } // Repeater
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
            text: "Formularz"
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
            id: _forms
            spacing: 5
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: cardCreation?.statisticsSource?.questionSources ?? []

            delegate: Rectangle {
                width: ListView.view.width; height: 40
                color: "lightgray"

                Text {
                    text: modelData
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
