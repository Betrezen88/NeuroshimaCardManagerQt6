import QtQuick
import QtQuick.Controls

import core.creation 1.0
import core.source 1.0

import "../../Elements/Creation/Skills"
import "../../Elements/Card/Common"

Page {
    property CardCreation cardCreation: null

    id: _root

    ScrollView {
        id: _scrollView

        anchors {
            fill: parent
            margins: 5
        }

        Column {
            spacing: 5

            Text {
                text: "Umiejętności"
                font.bold: true
                font.pointSize: 16
                width: _root.width - 10
            }

            Text {
                id: _description
                text: "Opis zasad wydawania punktów umiejętności, oraz działania suwaków."
                font.pointSize: 14
                wrapMode: Text.WordWrap
                width: _root.width - 10
            }

            Row {
                spacing: 5

                Text {
                    text: "Specjalizacja:"
                    font.pointSize: 14
                }

                Text {
                    id: _specializationPoints
                    text: cardCreation !== null && cardCreation.statisticsCretion !== null
                          ? cardCreation.statisticsCreation.skillpointsManager.specializationSkillpoints : 0
                    font.pointSize: 14
                    rightPadding: 20
                }

                Text {
                    text: "Ogólne:"
                    font.pointSize: 14
                }

                Text {
                    id: _generalPoints
                    text: cardCreation !== null && cardCreation.statisticsCretion !== null
                          ? cardCreation.statisticsCreation.skillpointsManager.generalSkillpoints : 0
                    font.pointSize: 14
                }
            } // Row

            Row {
                spacing: 5

                Column {
                    spacing: 5

                    Attribute {
                        attribute: cardCreation !== null && cardCreation.statisticsCreation !== null
                                   ? cardCreation.statisticsCreation.attribute("Budowa") : null
                    }

                    Attribute {
                        attribute: cardCreation !== null && cardCreation.statisticsCreation !== null
                                   ? cardCreation.statisticsCreation.attribute("Zręczność") : null
                    }
                } // Column

                Column {
                    spacing: 5

                    Attribute {
                        id: _character
                        attribute: cardCreation !== null && cardCreation.statisticsCreation !== null
                                   ? cardCreation.statisticsCreation.attribute("Charakter") : null
                    }

                    Attribute {
                        id: _perception
                        attribute: cardCreation !== null && cardCreation.statisticsCreation !== null
                                   ? cardCreation.statisticsCreation.attribute("Percepcja") : null
                    }
                } // Column

                Column {
                    spacing: 5

                    Attribute {
                        id: _cleaverness
                        attribute: cardCreation !== null && cardCreation.statisticsCreation !== null
                                   ? cardCreation.statisticsCreation.attribute("Spryt") : null
                    }

                    HeaderLabel {
                        id: _label
                        text: "Inne Umiejętności"
                        width: _cleaverness.width
                    }

                    List {
                        width: _cleaverness.width
                        height: _character.height + _perception.height - _cleaverness.height - _label.height - parent.spacing

                        model: 3

                        delegate: OtherSkill {
                            width: ListView.view.width
                        }
                    }
                } // Column

            } // Row

        } // Column

    } // ScrollView

    background: Rectangle {
        color: "#fff"
    }
} // Page
