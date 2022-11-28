import QtQuick
import QtQuick.Layouts

import "../../../Delegates/Card/Statistics/Modifiers"

Rectangle {
    id: _root
    border.color: "#000"
    border.width: 2

    ListView {
        anchors.fill: parent
        spacing: 5
        clip: true

        model: ListModel {
            ListElement {
                name: "Rany"
                value: "+30%"
                elements: [
                    ListElement { name: "Lekka (L.R)"; value: "+15%" },
                    ListElement { name: "Lekka (P.N)"; value: "+15%" }
                ]
            }
            ListElement {
                name: "Percepcja"
                value: "+5%"
                elements: [
                    ListElement { name: "Helm"; value: "+5%" }
                ]
            }
        }

        delegate: ModifierCategory {
            name: model.name
            value: model.value
            elements: model.elements
            width: ListView.view.width - _root.border.width*2
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
