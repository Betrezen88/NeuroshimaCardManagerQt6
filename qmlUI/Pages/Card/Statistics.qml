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
                    pData: sData
                }

                HeaderLabel {
                    text: "Sztuczki"
                    width: parent.colWidth
                }

                List {
                    id: _tricks
                    width: parent.colWidth; height: 830
                    model: sData != null ? sData.tricks : 0

                    delegate: Trick {
                        trick: modelData
                        width: ListView.view.width; height: 40
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
                    attribute: sData.attribute("Budowa")
                    width: parent.colWidth
                }

                Attribute {
                    id: _dexterity
                    attribute: sData.attribute("Zręczność")
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
                    attribute: sData.attribute("Charakter")
                    width: parent.colWidth
                }

                Attribute {
                    id: _perception
                    attribute: sData.attribute("Percepcja")
                    width: parent.colWidth
                }

                HeaderLabel {
                    text: "Rany"
                    width: parent.colWidth; height: 40
                }

                Wounds {
                    id: _wounds
                    width: parent.colWidth; height: 200
                    wounds: sData.wounds
                }
            } // Column

            Column {
                property int colWidth: 300

                Attribute {
                    id: _cleaverness
                    attribute: sData.attribute("Spryt")
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
