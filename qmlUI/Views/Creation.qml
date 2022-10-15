import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: _root

    signal cancelCreation()

    header: Row {
        property int textFieldWidth: (parent.width - 150 - (parent.spacing*3)) / 3
        spacing: 5

        Button {
            text: "Anuluj"
            width: 150
            height: 40

            onClicked: _root.cancelCreation()
        }

        TextField {
            id: _name
            placeholderText: "Imie"
            width: parent.textFieldWidth > 200 ? 200 : parent.textFieldWidth
            height: 40
        }

        TextField {
            id: _nickname
            placeholderText: "Nickname"
            width: parent.textFieldWidth > 200 ? 200 : parent.textFieldWidth
            height: 40
        }

        TextField {
            id: _surname
            placeholderText: "Surname"
            width: parent.textFieldWidth > 200 ? 200 : parent.textFieldWidth
            height: 40
        }
    }

    Item {
        id: _stagesPanel
        width: 150
        anchors { top: parent.top; bottom: parent.bottom; left: parent.left }

        Label {
            id: _label
            text: "Etapy"
            color: "black"
            padding: 10
            font.pointSize: 14
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            height: 40; width: parent.width
        }

        ListView {
            id: _stages
            clip: true
            spacing: 5
            width: parent.width
            anchors { top: _label.bottom; bottom: parent.bottom; left: parent.left }

            model: ListModel {
                ListElement { name: "Pochodzenie" }
                ListElement { name: "Profesje" }
                ListElement { name: "Wspolczynniki" }
                ListElement { name: "Specjalizacje" }
                ListElement { name: "Umiejetnosci" }
                ListElement { name: "Sztuczki" }
                ListElement { name: "Choroby" }
                ListElement { name: "Reputacja" }
                ListElement { name: "Formularz" }
                ListElement { name: "Sprzet" }
                ListElement { name: "Znajomosci" }
            }

            delegate: Button {
                text: model.name
                height: 50; width: ListView.view.width
            }
        } // ListView
    }

    StackView {
        id: _stagePageView
        anchors {
            top: parent.top; bottom: parent.bottom
            left: _stagesPanel.right; right: parent.right
            leftMargin: 5; topMargin: 5
        }

        initialItem: Item {
            ScrollView {
                anchors.fill: parent

                Column {
                    anchors.fill: parent

                    Rectangle {
                        color: "green"
                        width: 700; height: 700
                        Text {
                            text: "Placeholder"
                            anchors.centerIn: parent
                        }
                    }
                }
            }
        }
    } // StackView
}
