import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.creation 1.0

import "../../Elements/Card/Common"
import "../../Elements/Creation/Equipment"
import "../../Common"

Page {
    property CardCreation cardCreation: null

    id: _root

    ScrollView {
        id: _scrollView

        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
            right: _rightPanel.left
            margins: 5
        }

        Column {
            spacing: 5

            Text {
                id: _description
                text: "Witamy na etapie zakupów. W tym miejscu spróbujemy Ci wcisnąc kilka zupełnie niepotrzebnych rzeczy i jedną czy dwie, które ratują tyłek z opresji. W prezencie od firmy dostajesz 100 gambli i możesz je wydać na dowlony z wymienionych przedmiotów. Jeżeli potrzebujesz gratów, których nie ma na liście, zapytaj swojego MG, czy pozwoli Ci je wybrać i za jaką cenę.
    Niektóre egzemplarze wymienionych tutaj przedmiotów są w jakiś sposób szczególne. Tak jak volkgwagen Garbus jest perełką wśród samochodów, tak karabin należący do sławnego Łowcy budzi respekt i szacunek (albo nienawiść). Możesz uznać, że wybrany przez Ciebie przedmiot jest wyjątkowy. Posiaa on wówczas Punkty Reputacji, dodawane do Twojej Reputacji. Określz jakiego powodu przzedmiot jest szczególny i przyznaj mu od 1 do 2 Punktów Reputacji. Za każdy PR płacisz dodatkowo 50 gambli.
    Jeżeli po zakupach zostały Ci jakieś wolne gamble, zamień je na amunicję lub leki, czyli odpowiednik pieniądza."
                font.pointSize: 14
                wrapMode: Text.WordWrap
                verticalAlignment: Text.AlignJustify
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
            }

            Row {
                id: _moneyRow
                spacing: 5

                Text {
                    text: "Twoje gamble:"
                    font.pointSize: 14
                    font.bold: true
                }
                Text {
                    id: _money
                    text: "100"
                    font.pointSize: 14
                }
            } // Row

            Row {
                id: _searchRow
                spacing: 5

                TextField {
                    id: _searchField
                    height: 40; width: _scrollView.width - _clearBtn.width - _sortBtn.width - _filterBtn.width - parent.spacing*3
                    placeholderText: "Szukaj przedmiotu..."
                } // TextField

                Button {
                    id: _clearBtn
                    height: 40; width: 40
                    contentItem: Image {
                        source: "qrc:/Images/icons/clear.svg"
                    }
                    background: Rectangle {
                        border.width: 2
                        border.color: "#000"
                    }
                    onClicked: _searchField.clear()
                } // Button

                Button {
                    id: _sortBtn
                    height: 40; width: 40
                    contentItem: Image {
                        source: "qrc:/Images/icons/sort_ascending.svg"
                    }
                    background: Rectangle {
                        border.width: 2
                        border.color: "#000"
                    }
                    onClicked: _searchField.clear()
                } // Button

                Button {
                    id: _filterBtn
                    height: 40; width: 40
                    text: "F"
                    // contentItem: Image {
                    //     source: "qrc:/Images/icons/sort_ascending.svg"
                    // }
                    background: Rectangle {
                        border.width: 2
                        border.color: "#000"
                    }
                    onClicked: _searchField.clear()
                } // Button
            } // RowLayout

            Item {
                height: _scrollView.height - _description.height - _moneyRow.height - _searchRow.height - parent.spacing*3 < 400
                            ? 400 : _scrollView.height - _description.height - _moneyRow.height - _searchRow.height - parent.spacing*3
                width: _scrollView.width

                GridLayout {
                    anchors.fill: parent
                    columns: 2

                    HeaderLabel {
                        text: "Sklep"
                        Layout.preferredWidth: ((_root.width - _rightPanel.width - (_scrollView.anchors.margins*2)) / 2) - 5
                        Layout.preferredHeight: 40
                    }

                    HeaderLabel {
                        text: "Plecak"
                        Layout.preferredWidth: ((_root.width - _rightPanel.width - (_scrollView.anchors.margins*2)) / 2) - 5
                        Layout.preferredHeight: 40
                    }

                    List {
                        id: _shop
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        spacing: 5

                        model: cardCreation?.statisticsSource?.items ?? []

                        delegate: Item {
                            width: ListView.view.width
                            height: 40

                            Button {
                                id: _buyBtn
                                text: "+"
                                font.pointSize: 12
                                height: parent.height; width: parent.height
                                anchors { left: parent.left; top: parent.top }
                                onClicked: function() { console.log("Item quick bougth: ", model.source.name) }
                            }

                            Text {
                                text: model.source.name
                                padding: 5
                                font.pointSize: 12
                                verticalAlignment: Text.AlignVCenter
                                height: parent.height < implicitHeight ? implicitHeight : parent.height
                                anchors { left: _buyBtn.right; right: parent.right; top: parent.top }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: _itemDetails.openItemDetails(model.source)
                                }
                            }
                        }
                    } // List

                    List {
                        id: _backpack
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        spacing: 5

                        model: cardCreation?.statisticsCreation?.items ?? []

                        delegate: Item {
                            width: ListView.view.width
                            height: 40

                            Button {
                                id: _sellBtn
                                text: "-"
                                font.pointSize: 12
                                height: parent.height; width: parent.height
                                anchors { right: parent.right; top: parent.top }
                            }

                            Text {
                                text: model.source.name
                                padding: 5
                                font.pointSize: 12
                                verticalAlignment: Text.AlignVCenter
                                height: parent.height < implicitHeight ? implicitHeight : parent.height
                                anchors { left: parent.left; right: _sellBtn.left; top: parent.top }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: _itemDetails.openItemDetails(model.source)
                                }
                            }
                        }
                    } // List
                } // GridLayout
            } // Item
        } // Column

        FormPopup {
            id: _itemDetails
            width: _root.width * 0.5
            contentItem: ItemContent {
                id: _itemContent
                onImplicitHeightChanged: _itemDetails.height = implicitHeight
                onClose: _itemDetails.close()
                onItemBougth: function(itemSource) { console.log("Item bougth: ", itemSource?.name ?? "Null object") }
            }

            onClosed: _itemContent.itemSource = null

            function openItemDetails(itemDetails) {
                _itemContent.itemSource = itemDetails
                _itemDetails.open()
            }
        }

    } // ScrollView

    ColumnLayout {
        id: _rightPanel

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
        }

        Label {
            text: "Sprzęt"
            color: "#000"
            font.bold: true
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.preferredHeight: 40
            Layout.preferredWidth: 150
            Layout.alignment: Qt.AlignTop
        }

        ListView {
            id: _forms
            spacing: 5
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: ListModel {
                ListElement { name: "Broń ręczna" }
                ListElement { name: "Broń miotana" }
                ListElement { name: "Pistolety i rewolwery" }
                ListElement { name: "Pistolety maszynowe" }
                ListElement { name: "Karabiny powtarzalne i samopowtarzalne" }
                ListElement { name: "Karabiny automatyczne" }
                ListElement { name: "Strzelby" }
                ListElement { name: "Karabiny maszynowe" }
                ListElement { name: "Karabiny snajperskie" }
                ListElement { name: "Granatniki" }
                ListElement { name: "Pancerz" }
                ListElement { name: "Amunicja" }
                ListElement { name: "Leki" }
                ListElement { name: "Inne" }
            }

            delegate: Rectangle {
                width: ListView.view.width; height: 40
                color: "lightgray"

                Text {
                    text: model.name
                    width: parent.width; height: parent.height
                    wrapMode: Text.WordWrap
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        } // ListView
    } // ColumnLayout

    background: Rectangle {
        color: "#fff"
    }
} // Page
