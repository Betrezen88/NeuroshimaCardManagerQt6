import QtQuick
import QtQuick.Controls

ScrollView {
    id: _root
    clip: true

    Column {
        anchors.fill: parent

        Rectangle {
            width: 1000; height: 1000

            Text {
                text: "Placeholder"
                anchors.centerIn: parent
            }
        }
    }
}
