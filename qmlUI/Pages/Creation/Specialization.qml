import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.creation 1.0
import core.source 1.0

import "../../Delegates/Creation"

Page {
    property CardCreation cardCreation: null

    id: _root

    ScrollView {
        id: _scrollView

        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
            right: _rightPanel.left
            margins: 5
        }

        Column {
            spacing: 10

            Text {
                text: cardCreation !== null && cardCreation.statisticsCreation.specialization !== null
                      ? cardCreation.statisticsCreation.specialization.name : ""
                font.bold: true
                font.pointSize: 16
                verticalAlignment: Text.AlignVCenter
                height: 40
                width: _root.width - _rightPanel.width - 50
            }

            Text {
                text: cardCreation !== null && cardCreation.statisticsCreation.specialization !== null
                      ? cardCreation.statisticsCreation.specialization.description : ""
                font.pointSize: 14
                wrapMode: Text.WordWrap
                width: _root.width - _rightPanel.width - 50
            }

            Text {
                text: "Na zakupienie Umiejętności związanych z daną specializacją masz dodatkowe 30 punktów. Co więcej, za każdym razem gdy będziesz wydawał punkty doświadczenia na umiejętności związane z wybraną specializacją, zapłacisz za nie mniej o 20%."
                font.pointSize: 14
                wrapMode: Text.WordWrap
                width: _root.width - _rightPanel.width - 50
            }
        }

    } // ScrollView

    ColumnLayout {
        id: _rightPanel

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
        }

        Label {
            text: "Specjalizacje"
            color: "#000"
            font.bold: true
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.preferredHeight: 40
            Layout.preferredWidth: 150
            Layout.alignment: Qt.AlignTop
        }

        ListView {
            id: _specializations
            spacing: 5
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: cardCreation !== null && cardCreation.statisticsSource !== null
                   ? cardCreation.statisticsSource.specializations : []

            delegate: SelectionButton {
                name: model.name
                selected: cardCreation !== null && cardCreation.statisticsCreation !== null
                          && cardCreation.statisticsCreation.specialization.name === model.name
                width: ListView.view.width; height: 50
                onClicked: cardCreation.statisticsCreation.specialization = modelData
            }
        } // ListView
    } // ColumnLayout

    background: Rectangle {
        color: "#fff"
    }
} // Page
