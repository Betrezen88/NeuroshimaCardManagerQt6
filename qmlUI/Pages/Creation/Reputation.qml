import QtQuick
import QtQuick.Controls
import "../../Elements/Creation/Reputation"

Page {
    id: _root

    ScrollView {
        id: _scrollView

        anchors {
            fill: parent
            margins: 5
        }

        Column {
            spacing: 5

            Text {
                text: "Reputacja"
                font.bold: true
                font.pointSize: 16
            }

            Text {
                text: "Opis kroku reputacji."
                font.pointSize: 14
            }

            Grid {
                columns: 2
                columnSpacing: 20
                rowSpacing: 5

                Repeater {
                    property int labelWidth: 0

                    id: _places

                    model: [ "Kalifornia",
                        "Nevada",
                        "Vegas",
                        "Południowa Hegemonia",
                        "Meksyk",
                        "Salt Lake City",
                        "Wyoming",
                        "Kolorado",
                        "Nebraska",
                        "Kansas i Oklahoma",
                        "Teksas",
                        "Minnesota",
                        "Iowa",
                        "Missouri",
                        "Missisipi",
                        "Wisconsin",
                        "Illinois",
                        "Federacja Apallachów",
                        "Georgia",
                        "Miami",
                        "Detroit",
                        "Nowy Jork",
                        "Karolina" ]

                    delegate: Place {
                        name: modelData
                        labelWidth: {
                            _places.labelWidth = _places.labelWidth < implicitLabelWith ? implicitLabelWith : _places.labelWidth
                            return _places.labelWidth
                        }
                    } // Item
                }
            } // Grid
        } // Column

    } // ScrollView

    background: Rectangle {
        color: "#fff"
    }
} // Page
