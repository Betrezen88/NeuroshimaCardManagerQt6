import QtQuick
import QtQuick.Controls

import "../../Elements/Card/Common"
import "../../Elements/Creation/Tricks"

Page {
    id: _root

    ScrollView {
        id: _scrollView

        anchors {
            fill: parent
            margins: 5
        }

        Column {
            id: _column
            spacing: 5

            Text {
                id: _title
                text: "Sztuczki"
                font.bold: true
                font.pointSize: 16
                padding: 5
            }

            Text {
                id: _description
                text: "Opis etapu sztuczek."
                font.pointSize: 14
                padding: 5
            }

            Row {
                id: _row
                spacing: 5

                TextField {
                    id: _searchFiled
                    placeholderText: "Szukaj..."
                    font.pointSize: 12
                    height: _filters.height; width: _root.width - _filters.width - parent.spacing - 10
                }

                Button {
                    id: _filters
                    text: "F"
                    height: 40; width: 40
                }
            } // Row

            Grid {
                columns: 2
                columnSpacing: 5

                HeaderLabel {
                    text: "Wszystkie"
                    width: (_root.width - parent.columnSpacing - 10) / 2
                }

                HeaderLabel {
                    text: "Posiadane"
                    width: (_root.width - parent.columnSpacing - 10) / 2
                }

                List {
                    id: _available
                    spacing: 5
                    width: (_root.width - parent.columnSpacing - 10) / 2
                    height: _root.height - _title.height - _description.height - _row.implicitHeight - 40 - 30 > 400
                            ? _root.height - _title.height - _description.height - _row.implicitHeight - 40 - 30
                            : 400

                    model: 3

                    delegate: Item {
                        width: ListView.view.width

                        Trick {
                            name: "Sztuczka " + index
                            anchors {
                                top: parent.top
                                bottom: parent.bottom
                                right: parent.right
                                left: _buyBtn.right
                            }
                            onHeightChanged: parent.height = height
                        }

                        Button {
                            id: _buyBtn
                            text: ">"
                            width: 40; height: parent.height
                            anchors.left: parent.left
                        }
                    } // Item
                } // List

                List {
                    id: _owned
                    spacing: 5
                    width: (_root.width - parent.columnSpacing - 10) / 2
                    height: _root.height - _title.height - _description.height - _row.implicitHeight - 40 - 30 > 400
                            ? _root.height - _title.height - _description.height - _row.implicitHeight - 40 - 30
                            : 400

                    model: 3

                    delegate: Item {
                        width: ListView.view.width

                        Trick {
                            name: "Sztuczka " + index
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
                            text: "<"
                            width: 40; height: parent.height
                            anchors.right: parent.right
                        }
                    } // Item
                }
            } // Grid

        } // Column

    } // ScrollView

    background: Rectangle {
        color: "#fff"
    }
} // Page
