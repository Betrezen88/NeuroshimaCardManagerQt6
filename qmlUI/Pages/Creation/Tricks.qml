import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.creation 1.0
import core.source 1.0

import "../../Elements/Card/Common"
import "../../Elements/Creation/Tricks"
import "../../Common"

Page {
    property CardCreation cardCreation: null

    id: _root

    ScrollView {
        anchors {
            fill: parent
            margins: 5
        }

        ColumnLayout {
            width: _root.width - 10
            height: _root.height - 10

            Text {
                text: "Sztuczki"
                font.bold: true
                font.pointSize: 16
                padding: 5
                Layout.fillWidth: true
            }

            Text {
                text: "Dobra wiadomość jest taka, że zaraz dostaniesz prezent - a będzie to Sztuczka. Jest tu ich cała masa, a więc wybór masz nie mały. Jedna ze stu - tak mniej więcej wygląają propocje...
    Musisz jednak zwrócić uwagę na to, że przy każdej ze Sztuczek podane są minimalne wymagania, jakie musisz spełnić, by móc ją zdobyć. Wymagania dotyczą poziomu Umiejętności oraz Współczynników. Jak zauważysz, czasem są bardzo wygórowane - to dlatego, że Sztuczki będziesz mógł kupować w przyszłości za Punkty Doświadczenia. Wtedy, jak już rozwiniesz sobie to \"Zastraszanie na ósemkę\", wrócisz tu i zrobisz drobne zakupy, co?
    A póki co, wybierz jedną."
                font.pointSize: 14
                padding: 5
                wrapMode: Text.WordWrap
                Layout.preferredWidth: _root.width - 10
            }

            RowLayout {
                Layout.preferredWidth: _root.width - 10
                Layout.maximumWidth: 1000

                ComboBox {
                    model: cardCreation?.statisticsSource?.sortModel?.sortByModel ?? []
                    font.pointSize: 12
                    Layout.preferredHeight: 40; Layout.preferredWidth: 120
                    onCurrentTextChanged: {
                        cardCreation.statisticsSource.sortModel.sortBy = currentText
                        _searchField.placeholderText = currentIndex === 0
                                ? "Wpisz nazwę sztuczki..."
                                : "Wpisz nazwę wymagania (np. blef)"
                    }
                } // ComboBox sort by

                TextField {
                    id: _searchField
                    placeholderText: "Szukaj..."
                    font.pointSize: 12
                    Layout.preferredHeight: 40
                    Layout.fillWidth: true
                }

                Button {
                    id: _clearBtn
                    Layout.preferredHeight: 40; Layout.preferredWidth: 40
                    contentItem: Image {
                        source: "qrc:/Images/icons/clear.svg"
                    }
                    background: Rectangle {
                        border.width: 2
                        border.color: "#000"
                    }
                    onClicked: _searchField.clear()
                } // Button clear

                Button {
                    id: _sortOrderBtn
                    Layout.preferredHeight: 40; Layout.preferredWidth: 40
                    contentItem: Image {
                        source: "qrc:/Images/icons/sort_ascending.svg"
                    }
                    background: Rectangle {
                        border.width: 2
                        border.color: "#000"
                    }
                    onClicked: _sortOrderMenu.open()

                    Menu {
                        id: _sortOrderMenu

                        MenuItem {
                            text: "Sortowanie A-Z"
                            height: 40
                            icon.source: "qrc:/Images/icons/sort_ascending.svg"
                            onClicked: _sortOrderBtn.contentItem = Qt.createQmlObject(`
                                        import QtQuick
                                        Image { source: "qrc:/Images/icons/sort_ascending.svg" }
                                        `, _sortOrderBtn, "Icon")
                        }
                        MenuItem {
                            text: "Sortowanie Z-A"
                            height: 40
                            icon.source: "qrc:/Images/icons/sort_descending.svg"
                            onClicked: _sortOrderBtn.contentItem = Qt.createQmlObject(`
                                        import QtQuick
                                        Image { source: "qrc:/Images/icons/sort_descending.svg" }
                                        `, _sortOrderBtn, "Icon")
                        }
                    }
                } // Button sort

                Button {
                    id: _availableOnlyBtn
                    Layout.preferredHeight: 40; Layout.preferredWidth: 40
                    contentItem: Image {
                        source: "qrc:/Images/icons/visible.svg"
                    }
                    background: Rectangle {
                        border.width: 2
                        border.color: "#000"
                    }
                    onClicked: _availableOnlyMenu.open()

                    Menu {
                        id: _availableOnlyMenu

                        MenuItem {
                            text: "Wszystkie sztuczki"
                            height: 40
                            icon.source: "qrc:/Images/icons/visible.svg"
                            onClicked: _availableOnlyBtn.contentItem = Qt.createQmlObject(`
                                        import QtQuick
                                        Image { source: "qrc:/Images/icons/visible.svg" }
                                        `, _availableOnlyBtn, "Icon")
                        }
                        MenuItem {
                            text: "Dostępne sztuczki"
                            height: 40
                            icon.source: "qrc:/Images/icons/non_visible.svg"
                            onClicked: _availableOnlyBtn.contentItem = Qt.createQmlObject(`
                                        import QtQuick
                                        Image { source: "qrc:/Images/icons/non_visible.svg" }
                                        `, _availableOnlyBtn, "Icon")
                        }
                    }
                } // Button available
            } // RowLayout

            GridLayout {
                columns: 2
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.minimumWidth: 600
                Layout.maximumWidth: 1000
                Layout.minimumHeight: 400

                HeaderLabel {
                    text: "Wszystkie"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 40
                }

                HeaderLabel {
                    text: "Posiadane"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 40
                }

                List {
                    id: _available
                    spacing: 5
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    model: cardCreation?.statisticsSource?.tricks ?? []

                    delegate: Item {
                        width: ListView.view.width

                        Trick {
                            source: model.source
                            anchors {
                                top: parent.top
                                bottom: parent.bottom
                                right: parent.right
                                left: _buyBtn.right
                            }
                            onHeightChanged: parent.height = height
                            onShowDetails: function(source) {
                                _trickDetails.contentItem.source = source
                                _trickDetails.open()
                            }
                        }

                        Button {
                            id: _buyBtn
                            width: 40; height: parent.height
                            anchors.left: parent.left
                            contentItem: Image {
                                source: "qrc:/Images/icons/move_right.svg"
                            }
                            background: Rectangle {
                                color: model.available ? "green" : "red"
                                border.width: 2
                                border.color: "#000"
                            }
                            onClicked: console.log("Buy trick")
                        }
                    } // Item
                } // List

                List {
                    id: _owned
                    spacing: 5
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    model: 3

                    delegate: Item {
                        width: ListView.view.width

                        Trick {
                            anchors {
                                top: parent.top
                                bottom: parent.bottom
                                right: _sellBtn.left
                                left: parent.left
                            }
                            onHeightChanged: parent.height = height
                        }

                        Button {
                            id: _sellBtn
                            width: 40; height: parent.height
                            anchors.right: parent.right
                            contentItem: Image {
                                source: "qrc:/Images/icons/move_left.svg"
                            }
                            background: Rectangle {
                                border.width: 2
                                border.color: "#000"
                            }
                            onClicked: console.log("Sell trick")
                        }
                    } // Item
                } // List
                }
            } // GridLayout

        } // ColumnLayout

    } // ScrollView

    background: Rectangle {
        color: "#fff"
    }
} // Page
