import QtQuick
import QtQuick.Controls

import "Views"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    StackView {
        id: _stackView
        anchors.fill: parent

        initialItem: Welcome {}
    }
}
