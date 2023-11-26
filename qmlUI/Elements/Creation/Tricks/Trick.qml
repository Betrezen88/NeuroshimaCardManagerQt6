import QtQuick

import core.source 1.0

Item {
    property TrickSource source: null

    id: _root

    signal showDetails(TrickSource source)

    Text {
        text: source?.name ?? ""
        font.pointSize: 12
        anchors.verticalCenter: parent.verticalCenter
        wrapMode: Text.WordWrap
        padding: 5
        width: _root.width

        onImplicitHeightChanged: _root.height = implicitHeight > 40 ? implicitHeight : 40
    }

    MouseArea {
        anchors.fill: parent
        onClicked: _root.showDetails(_root.source)
    }

} // Item
