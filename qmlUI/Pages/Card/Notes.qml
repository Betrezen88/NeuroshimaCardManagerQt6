import QtQuick
import QtQuick.Controls

import "../../Delegates/Card/Notes"
import "../../Elements/Card/Common"

Page {
    id: _root

    ScrollView {
        anchors.fill: parent

        Column {
            spacing: 5

            Row {
                spacing: 5

                Column {
                    HeaderLabel {
                        text: "Biografia"
                        height: 40; width: 600 - (5 / 2)
                    }

                    ScrollTextArea {
                        id: _bibliography
                        width: 600 - (5 / 2); height: 400
                    }
                } // Column

                Column {
                    HeaderLabel {
                        text: "Notatki"
                        height: 40; width: 600 - (5 / 2)
                    }

                    ScrollTextArea {
                        id: _notes
                        width: 600 - (5 / 2); height: 400
                    }
                }
            } // Row

            HeaderLabel {
                text: "Formularz"
                height: 40; width: 1200
            }

            Repeater {
                model: ListModel {
                    ListElement {
                        question: "Jest pozny wieczor, od zachodu zbliza sie wichura, pierwsze podmuchy poruszaja konarami skarlowacialych drzew. Wylaniasz sie zza zalomu muru, przekraczasz ulice i wchodzisz do knajpy. Panujacy w niej zgielk ustaje, a zgromadzeni wewnatrz dostrzegaja..."
                        description: "Jak wygladasz ? Jak sie poruszas, jak spogladasz ? Czy jestes wysoki czy niski, ubierasz sie niechlujnie czy szpanersko ? Bron jest widoczna czy ukryta pod plaszczem ? Jestes pewny siebie czy raczej czujnym wzrokiem pogladasz w strone nieznajomych ?"
                        answer: ""
                    }
                    ListElement {
                        question: "Jest pozny wieczor, od zachodu zbliza sie wichura, pierwsze podmuchy poruszaja konarami skarlowacialych drzew. Wylaniasz sie zza zalomu muru, przekraczasz ulice i wchodzisz do knajpy. Panujacy w niej zgielk ustaje, a zgromadzeni wewnatrz dostrzegaja..."
                        description: "Jak wygladasz ? Jak sie poruszas, jak spogladasz ? Czy jestes wysoki czy niski, ubierasz sie niechlujnie czy szpanersko ? Bron jest widoczna czy ukryta pod plaszczem ? Jestes pewny siebie czy raczej czujnym wzrokiem pogladasz w strone nieznajomych ?"
                        answer: ""
                    }
                    ListElement {
                        question: "Jest pozny wieczor, od zachodu zbliza sie wichura, pierwsze podmuchy poruszaja konarami skarlowacialych drzew. Wylaniasz sie zza zalomu muru, przekraczasz ulice i wchodzisz do knajpy. Panujacy w niej zgielk ustaje, a zgromadzeni wewnatrz dostrzegaja..."
                        description: "Jak wygladasz ? Jak sie poruszas, jak spogladasz ? Czy jestes wysoki czy niski, ubierasz sie niechlujnie czy szpanersko ? Bron jest widoczna czy ukryta pod plaszczem ? Jestes pewny siebie czy raczej czujnym wzrokiem pogladasz w strone nieznajomych ?"
                        answer: ""
                    }
                    ListElement {
                        question: "Jest pozny wieczor, od zachodu zbliza sie wichura, pierwsze podmuchy poruszaja konarami skarlowacialych drzew. Wylaniasz sie zza zalomu muru, przekraczasz ulice i wchodzisz do knajpy. Panujacy w niej zgielk ustaje, a zgromadzeni wewnatrz dostrzegaja..."
                        description: "Jak wygladasz ? Jak sie poruszas, jak spogladasz ? Czy jestes wysoki czy niski, ubierasz sie niechlujnie czy szpanersko ? Bron jest widoczna czy ukryta pod plaszczem ? Jestes pewny siebie czy raczej czujnym wzrokiem pogladasz w strone nieznajomych ?"
                        answer: ""
                    }
                    ListElement {
                        question: "Jest pozny wieczor, od zachodu zbliza sie wichura, pierwsze podmuchy poruszaja konarami skarlowacialych drzew. Wylaniasz sie zza zalomu muru, przekraczasz ulice i wchodzisz do knajpy. Panujacy w niej zgielk ustaje, a zgromadzeni wewnatrz dostrzegaja..."
                        description: "Jak wygladasz ? Jak sie poruszas, jak spogladasz ? Czy jestes wysoki czy niski, ubierasz sie niechlujnie czy szpanersko ? Bron jest widoczna czy ukryta pod plaszczem ? Jestes pewny siebie czy raczej czujnym wzrokiem pogladasz w strone nieznajomych ?"
                        answer: ""
                    }
                    ListElement {
                        question: "Jest pozny wieczor, od zachodu zbliza sie wichura, pierwsze podmuchy poruszaja konarami skarlowacialych drzew. Wylaniasz sie zza zalomu muru, przekraczasz ulice i wchodzisz do knajpy. Panujacy w niej zgielk ustaje, a zgromadzeni wewnatrz dostrzegaja..."
                        description: "Jak wygladasz ? Jak sie poruszas, jak spogladasz ? Czy jestes wysoki czy niski, ubierasz sie niechlujnie czy szpanersko ? Bron jest widoczna czy ukryta pod plaszczem ? Jestes pewny siebie czy raczej czujnym wzrokiem pogladasz w strone nieznajomych ?"
                        answer: ""
                    }
                }

                delegate: FormQuestion {
                    width: 1200
                    question: model.question
                    description: model.description
                    answer: model.answer
                }
            } // Repeater

        } // Column
    } // ScrollView
} // Page
