import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: _root

    Label {
        id: _label
        height: 40
        text: qsTr("Witaj !")
        color: "black"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 20
        font.pixelSize: 20
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    RowLayout {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: _label.bottom
        anchors.bottom: parent.bottom
        anchors.topMargin: 20
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        spacing: 10

        ColumnLayout {
            spacing: 5
            Layout.preferredWidth: (parent.width / 2) - parent.spacing / 2
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillHeight: true

            Button {
                text: qsTr("Stwórz nową postać")
                Layout.preferredWidth: parent.width < 200 ? 200 : parent.width > 500 ? 500 : parent.width
                Layout.preferredHeight: 40
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                onClicked: {
                    // TODO: open creation view.
                    console.log( "Open creation view." )
                }
            }
        } // ColumnLayout

        ColumnLayout {
            spacing: 5
            Layout.preferredWidth: (parent.width / 2) - parent.spacing / 2
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillHeight: true

            Button {
                text: qsTr("Wczytaj kartę postaci")
                Layout.preferredWidth: parent.width < 200 ? 200 : parent.width > 500 ? 500 : parent.width
                Layout.preferredHeight: 40
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                onClicked: {
                    // TODO: open load dialog.
                    console.log( "Open load dialog." )
                }
            }

            Label {
                text: qsTr("Ostatnio otwierane")
                color: "black"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                Layout.preferredHeight: 30
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            Repeater {
                id: _recentFiles

                model: 3

                delegate: Button {
                    text: "Filename.json"
                    hoverEnabled: true
                    Layout.preferredWidth: parent.width < 200 ? 200 : parent.width > 500 ? 500 : parent.width
                    Layout.preferredHeight: 40
                    Layout.alignment: Qt.AlignHCenter

                    onClicked: {
                        // TODO: Load selected card.
                        console.log( "Loading selected card " + text )
                    }

                    ToolTip {
                        parent: parent
                        visible: parent.hovered
                        text: "/home/miwy/Workspace/Qt/build-NeuroshimaCardManagerQt6-Desktop_Qt_6_4_0_GCC_64bit-Debug/qmlUI/appQmlUI"
                    }
                } // Button delegate
            } // Repeater
        } // ColumnLayout
    } // RowLayout
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1}D{i:6}D{i:2}
}
##^##*/
