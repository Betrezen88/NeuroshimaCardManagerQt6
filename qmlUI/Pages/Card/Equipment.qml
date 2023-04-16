import QtQuick
import QtQuick.Controls

import "../../Elements/Card/Equipment"

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
            } // Column
        }
    }
} // Page
