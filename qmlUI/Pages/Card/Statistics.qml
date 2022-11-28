import QtQuick
import QtQuick.Controls

import "../../Placeholders"
import "../../Elements/Card/Statistics"

Page {
    id: _root

    ScrollView {
        anchors.fill: parent

        Grid {
            columns: 4
            spacing: 5

            Column {
                property int colWidth: 300

                Personal {
                    id: _personal
                    width: parent.colWidth
                }

                Tricks {
                    id: _tricks
                    width: parent.colWidth
                }
            }

            Column {
                property int colWidth: 300

                Label {
                    text: "Wspolczynniki i umiejetnosci"
                    width: parent.colWidth; height: 40
                    font.bold: true
                    font.pointSize: 14
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    background: Rectangle {
                        color: "#000"
                    }
                }

                Attribute {
                    id: _body
                    aName: "Budowa"
                    skillpacks: 2
                    width: parent.colWidth
                }

                Attribute {
                    id: _dexterity
                    aName: "Zrecznosc"
                    skillpacks: 5
                    width: parent.colWidth
                }

                Label {
                    text: "Rany"
                    width: parent.colWidth; height: 40
                    font.bold: true
                    font.pointSize: 14
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    background: Rectangle {
                        color: "#000"
                    }
                }

                Rectangle {
                    id: _damage
                    color: "green"
                    width: parent.colWidth; height: 200
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }
            }

            Column {
                property int colWidth: 300

                Attribute {
                    id: _charisma
                    aName: "Charakter"
                    skillpacks: 3
                    width: parent.colWidth
                }

                Attribute {
                    id: _perception
                    aName: "Percepcja"
                    skillpacks: 4
                    width: parent.colWidth
                }

                Label {
                    text: "Modyfikatory"
                    width: parent.colWidth; height: 40
                    font.bold: true
                    font.pointSize: 14
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    background: Rectangle {
                        color: "#000"
                    }
                }

                Modifiers {
                    id: _modifiers
                    width: parent.colWidth; height: 200
                }
            }

            Column {
                property int colWidth: 300

                Attribute {
                    id: _cleaverness
                    aName: "Spryt"
                    skillpacks: 5
                    width: parent.colWidth
                }

                Rectangle {
                    id: _otherSkills
                    color: "green"
                    width: parent.colWidth; height: 300
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }
            }
        } // Grid

    } // ScrollView
} // Page
