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
            onShowCreationView: _stackView.push( _creationView )
        }

        Creation {
            id: _creationView
            onCancelCreation: _stackView.pop()
        }
    }
} // Window
