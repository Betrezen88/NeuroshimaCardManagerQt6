import QtQuick
import QtQuick.Controls

import "Views"

Window {
    width: 640
    height: 480
    minimumWidth: 600
    minimumHeight: 400
    visible: true
    title: qsTr("Hello World")

    StackView {
        id: _stackView
        anchors.fill: parent

        initialItem: Welcome {
            id: _welcomeView
            onShowCreationView: {
                _creationView.visible = true
                _stackView.push( _creationView )
            }
            onShowCardsView: {
                _cardsView.visible = true
                _stackView.push( _cardsView )
            }
        }

        Creation {
            id: _creationView
            cardCreation: manager.cardCreation
            visible: false
            onCancelCreation: _stackView.pop()
        }

        Cards {
            id: _cardsView
            visible: false
            cardManager: manager.cardManager
            onCloseCardsView: _stackView.pop();
        }
    }
} // Window
