import QtQuick
import QtQuick.Controls

import "../../Elements/Creation/Skills"
import "../../Elements/Card/Common"

Page {
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
                    text: "30"
                    font.pointSize: 14
                    rightPadding: 20
                }

                Text {
                    text: "Ogólne:"
                    font.pointSize: 14
                }

                Text {
                    id: _generalPoints
                    text: "35"
                    font.pointSize: 14
                }
            } // Row

            Row {
                spacing: 5

                Column {
                    spacing: 5

                    Attribute {
                        name: "Budowa"
                        value: 0
                        skillpacks: [ "Sprawność", "Jeździectwo" ]
                    }

                    Attribute {
                        name: "Zręczność"
                        value: 0
                        skillpacks: [ "Walka wręcz", "Prowadzenie pojazdów", "Zdolności manualne", "Broń strzelecka", "Broń dystansowa" ]
                    }
                } // Column

                Column {
                    spacing: 5

                    Attribute {
                        id: _character
                        name: "Charakter"
                        value: 0
                        skillpacks: [ "Negocjacje", "Empatia", "Siła woli" ]
                    }

                    Attribute {
                        id: _perception
                        name: "Percepcja"
                        value: 0
                        skillpacks: [ "Orientacja w terenie", "Spostrzegawczość", "Kamuflaż", "Przerwanie" ]
                    }
                } // Column

                Column {
                    spacing: 5

                    Attribute {
                        id: _cleaverness
                        name: "Spryt"
                        value: 0
                        skillpacks: [ "Medycyna", "Technika", "Wiedza ogólna", "Sprzęta", "Pirotechnika" ]
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
