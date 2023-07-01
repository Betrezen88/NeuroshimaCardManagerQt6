import QtQuick
import QtQuick.Controls

import data.types
import core.view

import "../Pages/Card"

Item {
    property Card card: null

    id: _root

    Item {
        id: _sidePanel
        width: 50
        anchors { top: parent.top; bottom: parent.bottom; left: parent.left }

        ListView {
            id: _pageButtons
            clip: true
            spacing: 5
            width: _sidePanel.width
            anchors { top: parent.top; bottom: _buttons.top; left: parent.left }

            model: ListModel {
                ListElement { name: "S"; page: "qrc:/QmlUI/Pages/Card/Statistics.qml" }
                ListElement { name: "E"; page: "qrc:/QmlUI/Pages/Card/Equipment.qml" }
                ListElement { name: "N"; page: "qrc:/QmlUI/Pages/Card/Notes.qml" }
                ListElement { name: "F"; page: "" }
                ListElement { name: "B"; page: "qrc:/QmlUI/Views/Pets.qml" }
                ListElement { name: "P"; page: "" }
            }

            delegate: Button {
                width: _sidePanel.width; height: 50
                text: model.name
                onClicked: {
                    // TODO: Need to rework this
                    if (_leftPage.count > 0) {
                        _leftPage.removeItem( _leftPage.currentItem )
                    }

                    var item = Qt.createComponent(model.page)
                    if (item.status === Component.Ready) {
                        _leftPage.addItem(item.createObject(_leftPage, {}))
                        console.log("Component added")
                    }
                    else if (item.status === Component.Error) {
                        console.log("Error: ", item.errorString())
                    }
                }
            }
        }

        Column {
            id: _buttons
            spacing: 5
            anchors { bottom: parent.bottom; left: parent.left }

            Button {
                id: _sidePageBtn
                text: "[|]"
                width: _sidePanel.width; height: 50
                onClicked: _rightPage.visible = !_rightPage.visible
            }

            Button {
                id: _expandBtn
                text: ">"
                width: _sidePanel.width; height: 50
                onClicked: _sidePanel.width = (_sidePanel.width > 50) ? 50 : 150
            }
        }
    } // Item

    SplitView {
        id: _pageView
        orientation: Qt.Horizontal
        anchors { top: parent.top; bottom: parent.bottom; left: _sidePanel.right; right: parent.right }

        // TODO: Move it to seperate component ?
        SwipeView {
            id: _leftPage
            SplitView.minimumWidth: 200

            Component.onCompleted: {
                // TODO: Temporary solution
                var item = Qt.createComponent("qrc:/QmlUI/Pages/Card/Statistics.qml")
                if (item.status === Component.Ready) {
                    _leftPage.addItem(item.createObject(_leftPage, {}))
                    console.log("Component added")
                }
                else if (item.status === Component.Error) {
                    console.log("Error: ", item.errorString())
                }
            }
        }

        SwipeView {
            id: _rightPage
            visible: false
            SplitView.minimumWidth: 200
        }
    } // SplitView


    function pagePath(type) {
        switch(type) {
        case Types.Page.Statistics:
            return "qrc:/QmlUI/Pages/Card/Statistics.qml"
        case Types.Page.Equipment:
            return "qrc:/QmlUI/Pages/Card/Equipment.qml"
        case Types.Page.Notes:
            return "qrc:/QmlUI/Pages/Card/Notes.qml"
        case Types.Page.Friend:
            return ""
        case Types.Page.Beast:
            return "qrc:/QmlUI/Views/Pets.qml"
        case Types.Page.Vehicle:
            return ""
        default:
            return ""
        }
    }

    function pageData(type) {
        switch(type) {
        case Types.Page.Statistics:
            return card.statistics
        case Types.Page.Equipment:
            return null
        case Types.Page.Notes:
            return null
        case Types.Page.Friend:
            return null
        case Types.Page.Beast:
            return null
        case Types.Page.Vehicle:
            return null
        default:
            return null
        }
    }

    function pageTitle(type) {
        switch(type) {
        case Types.Page.Statistics:
            return "Statystyki"
        case Types.Page.Equipment:
            return "Eqwipunek"
        case Types.Page.Notes:
            return "Notatki"
        case Types.Page.Friend:
            return "Znajomi"
        case Types.Page.Beast:
            return "Bestie"
        case Types.Page.Vehicle:
            return "Pojazdy"
        default:
            return null
        }
    }

} // Item
