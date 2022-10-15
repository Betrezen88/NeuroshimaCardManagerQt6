import QtQuick
import QtQuick.Controls

Page {
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

    Card {
        id: _cardView
        anchors.fill: parent
    }

} // Page
