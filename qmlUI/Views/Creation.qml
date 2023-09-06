import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.creation 1.0

import "../Pages/Creation"

Page {
    property CardCreation cardCreation: null

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
                ListElement { name: "Pochodzenie"; type: 0 }
                ListElement { name: "Profesje"; type: 1 }
                ListElement { name: "Wspolczynniki"; type: 2 }
                ListElement { name: "Specjalizacje"; type: 3 }
                ListElement { name: "Umiejetnosci"; type: 4 }
                ListElement { name: "Sztuczki"; type: 5 }
                ListElement { name: "Choroby"; type: 6; }
                ListElement { name: "Reputacja"; type: 7 }
                ListElement { name: "Formularz"; type: 8 }
                ListElement { name: "Sprzet"; type: 9 }
                ListElement { name: "Znajomosci"; type: 10 }
                ListElement { name: "Zakończ"; type: 11 }
            }

            delegate: Button {
                text: model.name
                height: 50; width: ListView.view.width
                onClicked: loadPage(model.type)
            }
        } // ListView
    }

    StackView {
        id: _creationPage
        anchors {
            top: parent.top; bottom: parent.bottom
            left: _stagesPanel.right; right: parent.right
            leftMargin: 5; topMargin: 5
        }
        clip: true

        Component.onCompleted: loadPage(0)
    } // StackView

    function loadPage(type) {
        if ( _creationPage.count > 0 ) {
            _creationPage.pop( _creationPage.currentItem )
        }

        var item = Qt.createComponent( pagePath(type) )
        if (item.status === Component.Ready) {
            _creationPage.push(item.createObject(_creationPage), { cardCreation: _root.cardCreation })
        }
        else if (item.status === Component.Error) {
            console.log("Error: ", item.errorString())
        }
    }

    function pagePath(type) {
        switch(type) {
        case 0:
            return "qrc:/QmlUI/Pages/Creation/Origin.qml"
        case 1:
            return "qrc:/QmlUI/Pages/Creation/Profession.qml"
        case 2:
            return "qrc:/QmlUI/Pages/Creation/Attributes.qml"
        case 3:
            return "qrc:/QmlUI/Pages/Creation/Specialization.qml"
        case 4:
            return "qrc:/QmlUI/Pages/Creation/Skills.qml"
        case 5:
            return "qrc:/QmlUI/Pages/Creation/Tricks.qml"
        case 6:
            return "qrc:/QmlUI/Pages/Creation/Diseases.qml"
        case 7:
            return "qrc:/QmlUI/Pages/Creation/Reputation.qml"
        case 8:
            return "qrc:/QmlUI/Pages/Creation/Form.qml"
        case 9:
            return "qrc:/QmlUI/Pages/Creation/Shop.qml"
        case 10:
            return "qrc:/QmlUI/Pages/Creation/Tricks.qml"
        default:
            return "qrc:/QmlUI/Pages/Creation/Diseases.qml"
        }
    }

} // Page
