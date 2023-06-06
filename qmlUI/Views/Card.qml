import QtQuick
import QtQuick.Controls

import "../Pages/Card"

Item {
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

            model: 6

            delegate: Button {
                width: _sidePanel.width; height: 50
                text: index
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
} // Item
