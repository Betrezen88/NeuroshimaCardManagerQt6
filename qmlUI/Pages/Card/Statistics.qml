import QtQuick
import QtQuick.Controls

import core.view

import "../../Elements/Card/Statistics"
import "../../Elements/Card/Common"
import "../../Delegates/Card/Statistics"

Page {
    property Statistics sData

    id: _root

    ScrollView {
        anchors.fill: parent

        Grid {
            columns: 4
            spacing: 5

            Column {
                property int colWidth: 300
                spacing: 3

                Personal {
                    id: _personal
                    width: parent.colWidth
                }

                HeaderLabel {
                    text: "Sztuczki"
                    width: parent.colWidth
                }

                List {
                    id: _triicks
                    width: parent.colWidth; height: 830
                    model: 5

                    delegate: Trick {
                        width: ListView.view.width; height: 40
                        name: "Sztuczka"
                    }
                }
            } // Column

            Column {
                property int colWidth: 300

                HeaderLabel {
                    text: "Współczynniki i umiejętności"
                    width: parent.colWidth; height: 40
                }

                Attribute {
                    id: _body
                    aName: "Budowa"
                    skillpacks: 2
                    width: parent.colWidth
                }

                Attribute {
                    id: _dexterity
                    aName: "Zręczność"
                    skillpacks: 5
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
                    width: parent.colWidth; height: 160
                }
            } // Column

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

                HeaderLabel {
                    text: "Rany"
                    width: parent.colWidth; height: 40
                }

                Wounds {
                    id: _wounds
                    width: parent.colWidth; height: 200
                }
            } // Column

            Column {
                property int colWidth: 300

                Attribute {
                    id: _cleaverness
                    aName: "Spryt"
                    skillpacks: 5
                    width: parent.colWidth
                }

                HeaderLabel {
                    text: "Inne Umiejętności"
                    width: parent.colWidth; height: 40
                }

                List {
                    id: _otherSkills
                    width: parent.colWidth; height: _charisma.height + _perception.height - _cleaverness.height
                    spacing: 3
                    model: sData.otherSkills

                    delegate: OtherSkill {
                        otherSkill: modelData
                        width: ListView.view.width
                    }
                }

                HeaderLabel {
                    text: "Doświadczenie"
                    width: parent.colWidth; height: 40
                }

                Experience {
                    id: _experience
                    width: parent.colWidth
                }

                DifficultyLevels {
                    width: parent.colWidth; height: 57
                }
            } // Column
        } // Grid

    } // ScrollView

} // Page
