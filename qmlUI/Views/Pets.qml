import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../Pages/Card"

Page {
    id: _root

    header: TabBar {
        id: _tabBar
        clip: true

        background: Rectangle {
            color: "#000"
        }

        Repeater {
            model: ListModel{
                ListElement { name: "Fafik" }
                ListElement { name: "Grogon" }
                ListElement { name: "Niedźwiedziołak" }
            }

            delegate: TabButton {
                width: 150; height: 80
                contentItem: Text {
                    text: model.name
                    color: "#fff"
                    padding: 10
                    font.pointSize: 12
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    color: _tabBar.currentItem == parent ? "gray" : "#000"
                    border.width: 2
                    border.color: "#000"
                }
                onClicked: console.log("Loading Beast info.")
            }
        } // TabButton
    } // TabBar

    Beast {
        id: _beast
        anchors.fill: parent
        anchors.topMargin: 5
    }
}
