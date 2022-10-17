import QtQuick
import QtQuick.Controls

import "../../Placeholders"

Page {
    id: _root

    ScrollView {
        anchors.fill: parent

        Grid {
            columns: 4
            spacing: 5

            Column {
                property int colWidth: 300
                spacing: 3

                Rectangle {
                    id: _portret
                    color: "green"
                    width: parent.colWidth; height: 250
                    radius: 5

                    Text {
                        text: "Portret"
                        anchors.centerIn: parent
                    }
                }

                Label {
                    text: "Postac"
                    width: parent.colWidth; height: 40
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                }

                Rectangle {
                    id: _fullname
                    color: "green"
                    width: parent.colWidth; height: 40
                    radius: 5

                    Text {
                        text: "Imie"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _origin
                    color: "green"
                    width: parent.colWidth; height: 40
                    radius: 5

                    Text {
                        text: "Pochodzenie"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _profesion
                    color: "green"
                    width: parent.colWidth; height: 40
                    radius: 5

                    Text {
                        text: "Profesja"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _specialization
                    color: "green"
                    width: parent.colWidth; height: 40
                    radius: 5

                    Text {
                        text: "Specjalizacja"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _disease
                    color: "green"
                    width: parent.colWidth; height: 40
                    radius: 5

                    Text {
                        text: "Choroba"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _originFeature
                    color: "green"
                    width: parent.colWidth; height: 40
                    radius: 5

                    Text {
                        text: "Cecha z pochodzenia"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _profesionFeature
                    color: "green"
                    width: parent.colWidth; height: 40
                    radius: 5

                    Text {
                        text: "Cecha z profesji"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _reputation
                    color: "green"
                    width: parent.colWidth; height: 40
                    radius: 5

                    Text {
                        text: "Reputacja"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _fame
                    color: "green"
                    width: parent.colWidth; height: 40
                    radius: 5

                    Text {
                        text: "Slawa"
                        anchors.centerIn: parent
                    }
                }

                Label {
                    text: "Sztuczki"
                    width: parent.colWidth; height: 40
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                }

                ListView {
                    spacing: 3
                    clip: true
                    width: parent.colWidth; height: 500

                    model: 3

                    delegate: Rectangle {
                        color: "green"
                        width: ListView.view.width; height: 40
                        radius: 5

                        Text {
                            text: "Sztuczka"
                            anchors.centerIn: parent
                        }
                    }
                }
            }

            Column {
                property int colWidth: 300
                spacing: 3

                Label {
                    text: "Wspolczynniki \ni umiejetnosci"
                    width: parent.colWidth; height: 40
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                }

                Rectangle {
                    id: _body
                    color: "green"
                    width: parent.colWidth; height: 250
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _dexterity
                    color: "green"
                    width: parent.colWidth; height: 500
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _damage
                    color: "green"
                    width: parent.colWidth; height: 250
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }
            }

            Column {
                property int colWidth: 300
                spacing: 3

                Rectangle {
                    id: _charizma
                    color: "green"
                    width: parent.colWidth; height: 250
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _perception
                    color: "green"
                    width: parent.colWidth; height: 500
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _mods
                    color: "green"
                    width: parent.colWidth; height: 250
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }
            }

            Column {
                property int colWidth: 300
                spacing: 3

                Rectangle {
                    id: _cleverness
                    color: "green"
                    width: parent.colWidth; height: 600
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    id: _otherSkills
                    color: "green"
                    width: parent.colWidth; height: 300
                    radius: 5

                    Text {
                        text: "Placeholder"
                        anchors.centerIn: parent
                    }
                }
            }
        }

    } // ScrollView
} // Page
