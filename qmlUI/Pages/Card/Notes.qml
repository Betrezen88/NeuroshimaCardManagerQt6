import QtQuick
import QtQuick.Controls

import "../../Delegates/Card/Notes"

Page {
    id: _root

    ScrollView {
        anchors.fill: parent

        Column {
            spacing: 5

            Row {
                spacing: 5

                Column {
                    Label {
                        text: "Biografia"
                        height: 40; width: 600 - (5 / 2)
                        font.bold: true
                        font.pointSize: 14
                        horizontalAlignment: Qt.AlignHCenter
                        verticalAlignment: Qt.AlignVCenter
                        background: Rectangle {
                            color: "#000"
                        }
                    }

                    ScrollView {
                        width: 600 - (5 / 2)
                        height: 400

                        TextArea {
                            id: _bibliography
                            width: parent.width
                            wrapMode: Text.WordWrap
                            font.pointSize: 12
                            color: "#000"

                            background: Rectangle {
                                color: "#fff"
                                border.width: 2
                                border.color: "#000"
                            }
                        }
                    }
                } // Column

                Column {
                    Label {
                        text: "Notatki"
                        height: 40; width: 600 - (5 / 2)
                        font.bold: true
                        font.pointSize: 14
                        horizontalAlignment: Qt.AlignHCenter
                        verticalAlignment: Qt.AlignVCenter
                        background: Rectangle {
                            color: "#000"
                        }
                    }

                    ScrollView {
                        width: 600 - (5 / 2)
                        height: 400

                        TextArea {
                            id: _notes
                            width: parent.width
                            wrapMode: Text.WordWrap
                            font.pointSize: 12
                            color: "#000"

                            background: Rectangle {
                                color: "#fff"
                                border.width: 2
                                border.color: "#000"
                            }
                        }
                    }
                }
            } // Row

            Label {
                text: "Formularz"
                height: 40; width: 1200
                font.bold: true
                font.pointSize: 14
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                background: Rectangle {
                    color: "#000"
                }
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
