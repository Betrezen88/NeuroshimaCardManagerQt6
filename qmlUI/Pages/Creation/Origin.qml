import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.creation 1.0
import core.source 1.0

import "../../Delegates/Creation"
import "../../Elements/Creation/Origin"

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
            Row {
                Text {
                    id: _name
                    text: cardCreation.statisticsCreation.origin !== null ? cardCreation.statisticsCreation.origin.name : ""
                    font.bold: true
                    font.pointSize: 16
                    verticalAlignment: Text.AlignVCenter
                    height: 40
                    width: _root.width - _rightPanel.width - _bonus.width - 50
                }

                AttributeBonus {
                    id: _bonus
                    bonus: cardCreation.statisticsCreation.origin !== null ? cardCreation.statisticsCreation.origin.bonus : null
                }
            } // Row

            Row {
                spacing: 5

                Text {
                    id: _description
                    text: cardCreation.statisticsCreation.origin !== null ?  cardCreation.statisticsCreation.origin.description : ""
                    font.pointSize: 14
                    wrapMode: Text.WordWrap
                    horizontalAlignment: Text.AlignJustify
                    width: _root.width - parent.spacing - _rightPanel.width - _picture.width - 10
                }

                Rectangle {
                    id: _picture
                    color: "green"
                    width: {
                        if ( 300 > _root.width - _rightPanel.width )
                            return 150
                        if ( 700 > _root.width - _rightPanel.width )
                            return 250
                        return 350
                    }
                    height: 500
                }
            } // Row

            Item { height: 10; width: 1 }

            Text {
                text: "Cechy (Wybierz jedną):"
                font.bold: true
                font.pointSize: 14
                width: _root.width - _rightPanel.width - 10
            }

            ButtonGroup { id: _featureButtons }

            Repeater {
                model: cardCreation.statisticsCreation.origin !== null ? cardCreation.statisticsCreation.origin.features : []

                delegate: Feature {
                    width: _root.width - _rightPanel.width - 10
                    buttonGroup: _featureButtons
                    source: modelData
                    selected: index === 0

                    onSelectedChanged: cardCreation.statisticsCreation.originFeature = source
                }
            } // Repeater
        } // Column

    } // ScrollView

    ColumnLayout {
        id: _rightPanel

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
        }

        Label {
            text: "Pochodzenie"
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
            id: _origins
            spacing: 5
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: cardCreation.statisticsSource.origins

            delegate: SelectionButton {
                name: model.name
                selected: cardCreation.statisticsCreation.origin !== null && cardCreation.statisticsCreation.origin.name === model.name
                width: ListView.view.width; height: 50
                onClicked: cardCreation.statisticsCreation.origin = modelData
            }
        } // ListView
    } // ColumnLayout

    background: Rectangle {
        color: "#fff"
    }
} // Page
