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

            Row {

                Text {
                    id: _name
                    text: "Południow Hegemonia"
                    font.bold: true
                    font.pointSize: 16
                    verticalAlignment: Text.AlignVCenter
                    height: 40
                    width: _root.width - _rightPanel.width - _value.width - _attribute.width - 50
                }

                Text {
                    id: _value
                    text: "+1"
                    rightPadding: 5
                    font.pointSize: 16
                    verticalAlignment: Text.AlignVCenter
                    width: _value.implicitWidth
                    height: 40
                }

                Text {
                    id: _attribute
                    text: "Budowa"
                    font.pointSize: 16
                    verticalAlignment: Text.AlignVCenter
                    width: _attribute.implicitWidth
                    height: 40
                }
            } // Row

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
            } // Row

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
            text: "Pochodzenie"
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
                ListElement { name: "Południowa Hegemonia" }
                ListElement { name: "Człowiek z... nie twój zasrany interes" }
                ListElement { name: "Detroit" }
                ListElement { name: "Federacja Appalachów" }
                ListElement { name: "Człowiek Pustyni" }
                ListElement { name: "Miami" }
                ListElement { name: "Missisipi" }
                ListElement { name: "Nowy Jork" }
                ListElement { name: "Posterunek" }
                ListElement { name: "Salt Lake Sity" }
                ListElement { name: "Texas" }
                ListElement { name: "Vegas" }
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
