import QtQuick
import QtQuick.Controls

import data.types
import core.view

import "../Pages/Card"

Item {
    property Card card: null

    id: _root

    signal pageChanged(name: string)

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
                ListElement { name: "S"; type: Types.Page.Statistics }
                ListElement { name: "E"; type: Types.Page.Equipment }
                ListElement { name: "N"; type: Types.Page.Notes }
                ListElement { name: "F"; type: Types.Page.Friend }
                ListElement { name: "B"; type: Types.Page.Beast }
                ListElement { name: "P"; type: Types.Page.Vehicle }
            }

            delegate: Button {
                width: _sidePanel.width; height: 50
                text: model.name
                visible: card == null
                         ? false
                         : card.hasPage(model.type)
                onClicked: {
                    _root.loadPage( _leftPage, model.type )
                }
            } // Button
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
        }

        SwipeView {
            id: _rightPage
            visible: false
            SplitView.minimumWidth: 200
        }
    } // SplitView

    onCardChanged: {
        if ( card == null ) {
            return
        }

        loadPage( _leftPage, Types.Page.Statistics )
    }

    function loadPage(side, type) {
        if ( side.count > 0 ) {
            side.removeItem( side.currentItem )
        }

        var item = Qt.createComponent( pagePath(type) )
        if (item.status === Component.Ready) {
            side.addItem(item.createObject(side, { sData: pageData(type) }))
            _root.pageChanged( _root.pageTitle(type) )
        }
        else if (item.status === Component.Error) {
            console.log("Error: ", item.errorString())
        }
    }

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
