import QtQuick
import QtQuick.Controls

import "../../Elements/Card/Beast"
import "../../Elements/Card/Common"
import "../../Delegates/Card/Beast"

Page {
    id: _root

    ScrollView {
        anchors.fill: parent

        Row {
            spacing: 2

            Column {
                id: _leftColumn
                spacing: 2
                width: 250

                Data {
                    id: _data
                    width: _leftColumn.width
                }

                HeaderLabel {
                    text: "Manewry"
                    width: _leftColumn.width
                }

                List {
                    id: _maneuvers
                    width: _leftColumn.width
                    height: 300

                    model: ListModel {
                        ListElement { name: "Zwiększone tempo walki" }
                        ListElement { name: "Szarża" }
                        ListElement { name: "Furia" }
                    }

                    delegate: Maneuver {
                        name: model.name
                        width: ListView.view.width
                    }
                }
            } // Column

            Column {
                id: _centerColumn
                width: 500
                spacing: 2

                HeaderLabel {
                    text: "Współczynniki"
                    width: _centerColumn.width
                }

                Stats {
                    id: _stats
                    width: _centerColumn.width
                }

                HeaderLabel {
                    text: "Akcje"
                    width: _centerColumn.width
                }

                List {
                    id: _actions
                    width: _centerColumn.width; height: 300

                    model: ListModel {
                        ListElement {
                            successes: 1
                            name: "Atak szczypcami"
                            damage: "Lekka"
                        }
                        ListElement {
                            successes: 2
                            name: "Atak żądłem"
                            damage: "Ciężka"
                        }
                    }

                    delegate: CombatAction {
                        successes: model.successes
                        name: model.name
                        damage: model.damage
                        width: ListView.view.width
                    }
                }

                HeaderLabel {
                    text: "Opis"
                    width: _centerColumn.width
                }

                ScrollTextArea {
                    id: _description
                    width: _centerColumn.width; height: 300
                }
            } // Column

            Column {
                id: _rightColumn
                width: 250
                spacing: 2

                HeaderLabel {
                    text: "Uwarunkowania"
                    width: _rightColumn.width
                }

                List {
                    id: _conditions
                    width: _rightColumn.width; height: 300
                    model: ListModel {
                        ListElement { name: "Kryj się, gdy komuś odwali" }
                        ListElement { name: "Mów mi, jak zwęszysz tornado" }
                        ListElement { name: "Mów mi, jak zwęszysz tchórza" }
                        ListElement { name: "Nie zadawaj się z obcymi" }
                        ListElement { name: "Od dzisiaj jesteś zwiadowcą" }
                        ListElement { name: "Od dzisiaj jesteś obrońcą zasobów i ogniska domowego" }
                    }

                    delegate: Condition {
                        name: model.name
                        width: ListView.view.width
                    }
                }

                HeaderLabel {
                    text: "Komendy"
                    width: _rightColumn.width
                }

                List {
                    id: _commands
                    width: _rightColumn.width; height: 300
                    spacing: 1
                    model: ListModel {
                        ListElement { name: "Przywołanie" }
                        ListElement { name: "Cisza" }
                        ListElement { name: "Walcz" }
                        ListElement { name: "Broń" }
                        ListElement { name: "Do mnie" }
                        ListElement { name: "Leżeć" }
                        ListElement { name: "Szukaj" }
                        ListElement { name: "Przodem" }
                        ListElement { name: "Skacz" }
                        ListElement { name: "Ukryj się" }
                        ListElement { name: "Dystans" }
                        ListElement { name: "Przynieś" }
                    }

                    delegate: Command {
                        name: model.name
                        width: ListView.view.width
                    }
                }

                HeaderLabel {
                    text: "Obrażenia"
                    width: _rightColumn.width
                }

                Damage {
                    id: _damage
                    width: _rightColumn.width
                }
            } // Column
        } // Row

    } // ScrollView
} // Page
