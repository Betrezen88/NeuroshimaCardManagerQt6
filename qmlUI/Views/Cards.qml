import QtQuick
import QtQuick.Controls

import core.managers

Page {
    property CardManager cardManager: null

    id: _root

    signal closeCardsView()

    header: ToolBar {
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        height: 50

        ToolButton {
            id: _menuBtn
            text: "M"
            width: parent.height; height: parent.height
            anchors { top: parent.top; left: parent.left }
            onClicked: _sidePanel.open()
        }

        Label {
            text: "Name 'Nickanem' Surname - Page Title"
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            height: 50
            anchors { top: parent.top; right: _settingsBtn.left; left: _menuBtn.right }
        }

        ToolButton {
            id: _settingsBtn
            text: "S"
            width: 50; height: 50
            anchors { top: parent.top; right: _closeBtn.left; rightMargin: 5 }
        }

        ToolButton {
            id: _closeBtn
            text: "C"
            width: 50; height: 50
            anchors { top: parent.top; right: parent.right }
            onClicked: _root.closeCardsView()
        }
    }

    Drawer {
        id: _sidePanel
        width: 200; height: _root.height

        Row {
            id: _buttons
            spacing: 5
            width: parent.width
            anchors { top: parent.top; left: parent.left }

            ToolButton {
                width: 50; height: 50
                text: "A"
                onClicked: _addCardMenu.open()

                Menu {
                    id: _addCardMenu
                    width: _sidePanel.width
                    y: parent.height

                    MenuItem {
                        text: "Nowa karta"
                        height: 40
                    }

                    MenuItem {
                        text: "Wczytaj karte"
                        height: 40
                    }
                }
            } // ToolButton

            ToolButton {
                width: 50; height: 50
                text: "S"
                onClicked: _saveCardMenu.open()

                Menu {
                    id: _saveCardMenu
                    width: _sidePanel.width
                    y: parent.height; x: -width

                    MenuItem {
                        text: "Zapisz karte"
                        height: 40
                    }

                    MenuItem {
                        text: "Zapisz karty"
                        height: 40
                    }
                }
            } // ToolButton

            ToolButton {
                width: 50; height: 50
                text: "E"
                onClicked: _editCardMenu.open()

                Menu {
                    id: _editCardMenu
                    width: _sidePanel.width
                    y: parent.height; x: -(width*2)

                    MenuItem {
                        text: "Rozdaj doswiadczenie"
                        height: 40
                    }

                    MenuItem {
                        text: "Dodaj strone"
                        height: 40
                    }
                }
            } // ToolButton
        } // Row

        Label {
            id: _label
            text: "Otwarte karty"
            anchors {
                top: _buttons.bottom; topMargin: 5
                left: parent.left; right: parent.right
            }
            height: 30
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        } // Label

        ListView {
            id: _openCards
            clip: true
            spacing: 5
            anchors {
                top: _label.bottom; left: parent.left
                right: parent.right; bottom: parent.bottom
            }

            model: cardManager.cards

            delegate: Rectangle {
                width: ListView.view.width; height: 50
                color: "lightgray"

                Text {
                    text: model.filename
                    anchors.centerIn: parent
                }
            }
        } // ListView
    } // Drawer

    Card {
        id: _cardView
        anchors.fill: parent
    }

} // Page
