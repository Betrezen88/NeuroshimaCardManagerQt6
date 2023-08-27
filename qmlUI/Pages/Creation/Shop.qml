import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../../Elements/Card/Common"

Page {
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
                text: "Opis kroku sprzętu."
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
                font.pointSize: 14
                wrapMode: Text.WordWrap
                verticalAlignment: Text.AlignJustify
            }

            Text {
                id: _money
                text: "Twoje gamble: 100"
                width: _root.width - _rightPanel.width - (_scrollView.anchors.margins*2)
                font.pointSize: 14
            }

            Grid {
                columnSpacing: 5
                columns: 2

                function columnWidth() {
                    var currentWidth = (_root.width - _rightPanel.width - (_scrollView.anchors.margins*2) - columnSpacing) / 2
                    if ( currentWidth < 300 )
                        return 300
                    else
                        return currentWidth
                }

                HeaderLabel {
                    text: "Sklep"
                    width: parent.columnWidth()
                }

                HeaderLabel {
                    text: "Plecak"
                    width: parent.columnWidth()
                }

                List {
                    id: _shop
                    width: parent.columnWidth()
                    height: _root.height - _description.height - _money.height - 40 - 10 - (_scrollView.anchors.margins*2)
                    spacing: 5

                    model: 5

                    delegate: Item {
                        width: ListView.view.width
                        height: 40

                        Button {
                            id: _buyBtn
                            text: "+"
                            font.pointSize: 12
                            height: parent.height; width: parent.height
                            anchors { left: parent.left; top: parent.top }
                        }

                        Text {
                            text: "Przedmiot"
                            padding: 5
                            font.pointSize: 12
                            verticalAlignment: Text.AlignVCenter
                            height: parent.height < implicitHeight ? implicitHeight : parent.height
                            anchors { left: _buyBtn.right; right: parent.right; top: parent.top }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: console.log("Item information popup")
                            }
                        }
                    }
                } // List

                List {
                    id: _backpack
                    width: parent.columnWidth()
                    height: _root.height - _description.height - _money.height - 40 - 10 - (_scrollView.anchors.margins*2)

                    spacing: 5

                    model: 5

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
                            text: "Przedmiot"
                            padding: 5
                            font.pointSize: 12
                            verticalAlignment: Text.AlignVCenter
                            height: parent.height < implicitHeight ? implicitHeight : parent.height
                            anchors { left: parent.left; right: _sellBtn.left; top: parent.top }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: console.log("Item information popup")
                            }
                        }
                    }
                }
            }
        } // Column

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
