import QtQuick
import QtQuick.Controls

import "../../Elements/Card/Equipment"
import "../../Delegates/Card/Equipment"

Page {
    id: _root

    ScrollView {
        anchors.fill: parent

        Row {
            spacing: 5

            Column {
                spacing: 5
                width: 600

                Label {
                    text: "Pancerz"
                    height: 40; width: parent.width
                    font.bold: true
                    font.pointSize: 14
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    background: Rectangle {
                        color: "#000"
                    }
                }

                Armor {
                    id: _armor
                    width: parent.width
                }

                Label {
                    text: "Bron"
                    height: 40; width: parent.width
                    font.bold: true
                    font.pointSize: 14
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    background: Rectangle {
                        color: "#000"
                    }
                }

                ListView {
                    width: parent.width; height: 800
                    spacing: 3
                    clip: true

                    model: ListModel {
                        ListElement {
                            name: "Beretta";
                            type: "ranged";
                        }
                        ListElement {
                            name: "Kij";
                            type: "melee";
                        }
                    }

                    delegate: Weapon {
                        width: ListView.view.width
                        name: model.name
                        type: model.type
//                        stats: model.stats
                    }
                }
            } // Column

            Column {
                width: 600
                Label {
                    text: "Plecak"
                    height: 40; width: parent.width
                    font.bold: true
                    font.pointSize: 14
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    background: Rectangle {
                        color: "#000"
                    }
                }

                ListView {
                    width: parent.width; height: 1060
                    spacing: 3
                    clip: true

                    model: ListModel {
                        ListElement { quantity: 9999; name: "Papieros" }
                        ListElement { quantity: 1; name: "Helm Kewlarowy" }
                        ListElement { quantity: 1; name: "Kaseta VHS" }
                        ListElement { quantity: 15; name: "Czesci mechaniczne" }
                        ListElement { quantity: 1; name: "Glock 17" }
                        ListElement { quantity: 1; name: "Cieply Sweter" }
                        ListElement { quantity: 1; name: "Kurtka zimowa" }
                        ListElement { quantity: 1; name: "Czapka" }
                        ListElement { quantity: 1; name: "Plecak" }
                        ListElement { quantity: 1; name: "Dresy" }
                    }

                    delegate: BackpackItem {
                        width: ListView.view.width
                        height: 40
                        quantity: model.quantity
                        name: model.name
                    }
                }

                Label {
                    text: "Zasoby"
                    height: 40; width: parent.width
                    font.bold: true
                    font.pointSize: 14
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    background: Rectangle {
                        color: "#000"
                    }
                }

                Resources {
                    id: _resources
                    width: parent.width
                    height: 50
                }
            } // Column
        }
    }
} // Page
