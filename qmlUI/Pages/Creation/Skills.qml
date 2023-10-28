import QtQuick
import QtQuick.Controls

import core.creation 1.0
import core.source 1.0

import "../../Elements/Creation/Skills"
import "../../Elements/Card/Common"
import "../../Elements/Common"
import "../../Forms"
import "../../Common"

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
                text: "Masz do dyspozycji 30 punktów za Specjalizację, na zakup Umiejętności z nią związanych. Dodatkowo masz 35 punktów na zakup dowolnych innych Umiejętności. Umiejętności są pogrupowane w pakiety, którego zakup kosztuje 5 punktów. Po zakupie umiejętności w pakiecie otrzymujesz na poziomie 1. Możesz kupić pojedyncze umiejętności, podniesienie ich na poziom 1 kosztuje 3 punkty, każdy kolejny poziom kosztuje tyle ile poziom na który podnosisz. Maksymalny poziom na który możesz podnieść umiejętność to poziom 5.
    Zasada suwaka: Jeśli masz umiejętność na poziomie +4 lub większej, Poziom Trudności testu obniżasz o jeden stopień w dół, na łatwiejszy. Każda wielokrotność 4 zmniejsza poziom trudności o jeden w dół. Jeśli masz umiejętność na poziomie 0, Poziom trudności rośnie o jeden stopień w górę. Suwak nie działa poczas walki w testach akcji strzelania, rzucania, ciosów itd. Działa w testach zwyczajnych np. Morale, Odporność na ból utd. Działa dla każdej umiejetności przed rozpoczęciem walki turowej."
                font.pointSize: 14
                wrapMode: Text.WordWrap
                width: _root.width - 10
            }

            Row {
                spacing: 5

                Text {
                    text: "<b>Specjalizacja:</b>"
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
                    text: "<b>Ogólne:</b>"
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

                        IconButton {
                            source: "qrc:/Images/icons/add.svg"
                            width: _label.height - 5; height: _label.height - 5
                            anchors {
                                rightMargin: 2.5
                                topMargin: 2.5
                                top: parent.top
                                right: parent.right
                            }
                            onClicked: _otherSkillForm.open()
                        }
                    }

                    List {
                        id: _otherSkills
                        width: _cleaverness.width
                        height: _character.height + _perception.height - _cleaverness.height - _label.height - parent.spacing

                        model: cardCreation?.statisticsCreation?.otherSkills ?? []

                        delegate: OtherSkill {
                            source: modelData
                            width: ListView.view.width
                            onRemove: cardCreation.statisticsCreation.removeOtherSkill(modelData)
                        }
                    }
                } // Column

            } // Row

        } // Column

    } // ScrollView

    FormPopup {
        id: _otherSkillForm

        ToolTip {
            id: _tooltip
            onAboutToHide: visible = false
        }

        contentItem: OtherSkillForm {
            attributes: cardCreation?.statisticsCreation?.attributesNames() ?? []
            onAccepted: function(name, attribute, description) {
                if ( name === "" ) {
                    _tooltip.text = "Nazwa umiejętności nie może być pusta."
                    _tooltip.visible = true
                    return
                }

                if ( cardCreation?.statisticsCreation?.isSkillNameTaken(name) ) {
                    _tooltip.text = "Podana umiejętność już istnieje ("+name+")."
                    _tooltip.visible = true
                    return
                }

                if ( description === "" ) {
                    _tooltip.text = "Opis umiejętności nie może byc pusty."
                    _tooltip.visible = true
                    return
                }

                cardCreation?.statisticsCreation?.addOtherSkill(name, description, attribute)
                _otherSkillForm.close()
            }
            onRejected: _otherSkillForm.close()
        }

        onAboutToHide: {
            contentItem.clear()
        }
    } // FormPopup

    background: Rectangle {
        color: "#fff"
    }
} // Page
