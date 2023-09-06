import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../../Delegates/Creation"

import core.creation 1.0
import core.source 1.0

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

            Text {
                id: _name
                text: cardCreation !== null && cardCreation.statisticsCreation.profession !== null
                      ? cardCreation.statisticsCreation.profession.name : ""
                font.bold: true
                font.pointSize: 16
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                height: 40
                width: _root.width - _rightPanel.width - 50
            }

            Text {
                id: _quote
                text: cardCreation !== null &&  cardCreation.statisticsCreation.profession !== null
                      ? cardCreation.statisticsCreation.profession.quote : ""
                font.italic: true
                font.pointSize: 14
                horizontalAlignment: Text.AlignHCenter
                height: 40
                width: _root.width - _rightPanel.width - 50
            }

            Row {
                spacing: 5

                Text {
                    id: _description
                    text: cardCreation !== null &&  cardCreation.statisticsCreation.profession !== null
                          ? cardCreation.statisticsCreation.profession.description : ""
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
            } // RowLayout

            Text {
                text: "Cechy (Wybierz jedną):"
                font.bold: true
                font.pointSize: 14

                width: _root.width - _rightPanel.width - 10
            }

            ButtonGroup { id: _featureButtons }

            Repeater {
                id: _features
                model: cardCreation !== null && cardCreation.statisticsCreation.profession !== null
                       ? cardCreation.statisticsCreation.profession.features : []

                delegate: Feature {
                    width: _root.width - _rightPanel.width - 10
                    buttonGroup: _featureButtons
                    source: modelData
                    selected: index === 0
                    onSelectedChanged: cardCreation.statisticsCreation.professionFeature = modelData
                }
            } // Repeater
        } // ColumnLayout

    } // ScrollView

    ColumnLayout {
        id: _rightPanel

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
        }

        Label {
            text: "Profesje"
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
            id: _professions
            spacing: 5
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: cardCreation !== null ? cardCreation.statisticsSource.professions : []

            delegate: SelectionButton {
                name: model.name
                selected: cardCreation !== null && cardCreation.statisticsCreation.profession !== null
                          && cardCreation.statisticsCreation.profession.name === model.name
                width: ListView.view.width; height: 50
                onClicked: {
                    if ( cardCreation !== null ) {
                        cardCreation.statisticsCreation.profession = modelData
                    }
                }
            }
        } // ListView
    } // ColumnLayout

    background: Rectangle {
        color: "#fff"
    }
} // Page
