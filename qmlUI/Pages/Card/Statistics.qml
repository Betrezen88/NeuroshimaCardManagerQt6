import QtQuick
import QtQuick.Controls

import core.view

import "../../Elements/Card/Statistics"
import "../../Elements/Card/Common"
import "../../Delegates/Card/Statistics"
import "../../Forms"
import "../../Common"

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

                    RoundButton {
                        text: "+"
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.rightMargin: 5
                        height: 35; width: 35
                        onClicked: _woundsForm.open()

                        FormPopup {
                            id: _woundsForm
                            contentItem: WoundForm {
                                wounds: sData.wounds.woundTypes
                                locations: sData.wounds.locations

                                onAccepted: function(wound, location, penalty) {
                                    sData.wounds.addWound(wound, location, penalty)
                                    _woundsForm.close()
                                }
                                onRejected: _woundsForm.close()
                            }
                        }
                    } // RoundButton
                } // HeaderLabel

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

                    RoundButton {
                        text: "+"
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.rightMargin: 5
                        height: 35; width: 35
                        onClicked: _experienceForm.open()

                        FormPopup {
                            id: _experienceForm
                            contentItem: ExperienceForm {
                                onAccepted: function(value) {
                                    sData.experience.add(value);
                                    _experienceForm.close()
                                }
                                onRejected: _experienceForm.close()
                            }
                        }
                    } // RoundButton
                } // HeaderLabel

                Experience {
                    id: _experience
                    width: parent.colWidth
                    experience: sData.experience
                }

                DifficultyLevels {
                    width: parent.colWidth; height: 57
                }
            } // Column
        } // Grid

    } // ScrollView

} // Page
