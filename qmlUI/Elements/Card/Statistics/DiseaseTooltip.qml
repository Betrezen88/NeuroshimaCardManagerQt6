import QtQuick
import QtQuick.Controls

Item {
    property alias title: _title.text
    property string description: _description.text
    property string cure: _cure.text
    property ListModel penalties

    id: _root

    Column {
        id: _column

        Text {
            id: _title
            width: _root.width
            font.pointSize: 12
            font.bold: true
            padding: 5
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
        }

        ScrollView {
            width: _root.width; height: _root.height - _title.height

            Column {
                spacing: 5

                Text {
                    id: _description
                    width: _root.width
                    text: "<b>Opis:</b> " + _root.description
                    font.pointSize: 10
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: _cure
                    width: _root.width
                    text: "<b>Lekarstwo:</b> " + _root.cure
                    font.pointSize: 10
                    wrapMode: Text.WordWrap
                }

                Text {
                    width: _root.width
                    text: "Kary"
                    font.pointSize: 12
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }

                Repeater {
                    model: _root.penalties
                    delegate: Item {
                        width: _root.width
                        height: _col.implicitHeight

                        Column {
                            id: _col
                            spacing: 5

                            Text {
                                text: "<b>"+model.name+"</b> - " + model.description
                                width: _root.width
                                font.pointSize: 10
                                wrapMode: Text.WordWrap
                            }

                            Text {
                                text: model.penalties
                                width: _root.width
                                font.pointSize: 10
                                wrapMode: Text.WordWrap
                            }
                        }
                    }
                } // Repeater
            } // Column
        } // Scrollview
    } // Column

} // Item
