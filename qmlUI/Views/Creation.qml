import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: _root

    signal cancelCreation()

    ScrollView {
        clip: true
        anchors.fill: parent

        Column {
            spacing: 5
            anchors.fill: parent

            Row {
                spacing: 5

                Button {
                    text: "Anuluj"
                    width: 200
                    height: 40

                    onClicked: _root.cancelCreation()
                }

                TextField {
                    id: _name
                    placeholderText: "Imie"
                    width: 200
                    height: 40
                }

                TextField {
                    id: _nickname
                    placeholderText: "Nickname"
                    width: 200
                    height: 40
                }

                TextField {
                    id: _surname
                    placeholderText: "Surname"
                    width: 200
                    height: 40
                }
            }

            Row {
                spacing: 5

                Column {
                    id: _sidePanel
                    spacing: 5

                    Label {
                        text: "Etapy"
                        color: "black"
                        padding: 10
                        font.pointSize: 14
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        width: 200
                        height: 40
                    }

                    Repeater {
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
                            width: 200
                            height: 50
                        }
                    }
                }

                StackView {
                    id: _stackView

                    width: 700
                    height: 700

                    initialItem: Rectangle {
                        color: "green"

                        Text {
                            text: "Placeholder"
                            anchors.centerIn: parent
                        }
                    }
                }
            }
        }
    }
}
