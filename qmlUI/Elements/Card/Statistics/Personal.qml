import QtQuick
import QtQuick.Controls

Column {
    id: _root

    spacing: 3

    Portrait {
        id: _portrait
        width: _root.width; height: 250
    }

    Label {
        text: "Postac"
        width: _root.width; height: 40
        font.bold: true
        font.pointSize: 14
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        background: Rectangle {
            color: "#000"
        }
    }

    PersonalField {
        id: _fullname
        width: _root.width
        name: "Imie"
        value: "Nick 'Happy' Sax"
    }

    PersonalField {
        id: _origin
        width: _root.width
        name: "Pochodzenie"
        value: "Las Vegas"
    }

    PersonalField {
        id: _profesion
        width: _root.width
        name: "Profesja"
        value: "Wojownik Autostrady"
    }

    PersonalField {
        id: _specialization
        width: _root.width
        name: "Specjalizacja"
        value: "Technik"
    }

    PersonalField {
        id: _disease
        width: _root.width
        name: "Choroba"
        value: "Goraczka Sobotniej Nocy"
    }

    PersonalField {
        id: _originFeature
        width: _root.width
        name: "Cecha z pochodzenia"
        value: "Zalety klasycznego wyksztalcenia"
    }

    PersonalField {
        id: _profesionFeature
        width: _root.width
        name: "Cecha z profesji"
        value: "Szybka bryka"
    }

    PersonalField {
        id: _fame
        width: _root.width
        name: "Slawa"
        value: "0"
    }

    Rectangle {
        id: _reputation
        color: "#fff"
        width: _root.width; height: 40
        radius: 10
        border.width: 2
        border.color: "#000"

        Text {
            text: "Reputacja"
            font.pointSize: 12
            font.bold: true
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: console.log("Show reputation popup")
        }
    }
} // Column
