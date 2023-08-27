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

            Text {
                id: _name
                text: "Chemik"
                font.bold: true
                font.pointSize: 16
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                height: 40
                width: _root.width - _rightPanel.width - 50
            }

            Text {
                id: _quote
                text: "\"Quote of current profession\""
                font.italic: true
                font.pointSize: 14
                horizontalAlignment: Text.AlignHCenter
                height: 40
                width: _root.width - _rightPanel.width - 50
            }

            Row {
                spacing: 5

                Text {
                    id: _description
                    text: "W świecie rządzonym prze mordercę, reguły są jasne i proste. Trzeba umieć walczyć, by przeżyć. Jeśli ktoś coś Ci ukradł, to znaczy, że źle tego strzegłeś. Jeśli ktoś obił Ci mordę, to znaczy, że Ci sie należało.
            Nie ma sądów. Nie ma dziesięciu przykazań. Nie ma gadki o nie pożądaniu żony bliźniego swego. Co się tak gapisz?! Tak, pochodzę z Hegemoni i jakoś nie narzekam. To twarda szkoła życia, ale wierz mi, nie chciałbym urodzić się gdzie indziej. Nasz świat jest prosty, albo ktoś mówi Ci prawdę, albo strzelasz mu w łeb. Albo potrafisz udowodnić, że jesteś mężczyzną, albo kopiesz w kalendarz nim dożyjesz dwudziestki.
            Dlatego Hegemonia się rozrasta, a Ty szczasz na mój widok i kulisz za każdym razem, kiedy podnoszę głos. Pochodzę z Hegemonii i we mnie jest siła.
            Jeśli spotkasz kogoś, kto wychował się u nas, nie zadzieraj z nim. Nie próbuj go oszukać, ani okłamać. Nie próbuj być cwany. Nie warto."
                    font.pointSize: 14
                    wrapMode: Text.WordWrap
                    horizontalAlignment: Text.AlignJustify
                    width: _root.width - parent.spacing - _rightPanel.width - _picture.width - 10
                }

                Rectangle {
                    id: _picture
                    color: "green"
                    width: {
                        if ( 300 > _root.width - _rightPanel.width )
                            return 150
                        if ( 700 > _root.width - _rightPanel.width )
                            return 250
                        return 350
                    }
                    height: 500
                }
            } // RowLayout

            Text {
                text: "Cechy (Wybierz jedną):"
                font.bold: true
                font.pointSize: 14

                width: _root.width - _rightPanel.width - 10
            }

            ButtonGroup { id: _featureButtons }

            Repeater {
                model: 3

                delegate: Feature {
                    width: _root.width - _rightPanel.width - 10
                    buttonGroup: _featureButtons
                }
            } // Repeater
        } // ColumnLayout

    } // ScrollView

    ColumnLayout {
        id: _rightPanel

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
        }

        Label {
            text: "Profesje"
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
            id: _professions
            spacing: 5
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: ListModel {
                ListElement { name: "Chemik" }
                ListElement { name: "Ganger" }
                ListElement { name: "Gladiator" }
                ListElement { name: "Handlarz" }
                ListElement { name: "Człowiek pustyni" }
                ListElement { name: "Kaznodzieja nowej ery" }
                ListElement { name: "Kowboj" }
                ListElement { name: "Kurier" }
                ListElement { name: "Łowca" }
                ListElement { name: "Łowca mutantów" }
                ListElement { name: "Mafiozo" }
                ListElement { name: "Medyk" }
                ListElement { name: "Monter" }
                ListElement { name: "Najemnik" }
                ListElement { name: "Ochroniarz" }
                ListElement { name: "Sędzia" }
                ListElement { name: "Spec" }
                ListElement { name: "Szaman" }
                ListElement { name: "Szczur" }
                ListElement { name: "Treser bestii" }
                ListElement { name: "Tropiciel" }
                ListElement { name: "Wojownik autostrady" }
                ListElement { name: "Wojownik klanu" }
                ListElement { name: "Zabójca" }
                ListElement { name: "Zabójca maszyn" }
                ListElement { name: "Złodziej" }
                ListElement { name: "Zołnierz" }
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
