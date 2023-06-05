import QtQuick

import "../../../Elements/Card/Common"
import "../../../Common"

Item {
    property alias name: _name.text

    id: _root
    height: _column.implicitHeight

    Column {
        id: _column
        anchors.fill: parent

        Text {
            id: _name
            width: _root.width
            font.pointSize: 12
            padding: 8
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
        }

        Rectangle {
            width: _root.width
            height: 2
            color: "#000"
        }
    } // Column

    TooltipPopup {
        id: _tooltip

        x: -width

        contentItem: TooltipContent {
            width: 300
            title: _name.text
            description: "Podczas strzelaniny zwierze kładzie się płasko na ziemi lub kryje się, dzięki czemu zmniejsza szanse zarobienia przypadkowej kulki."
        }
    } // TooltipPopup

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (_tooltip.opened)
                _tooltip.close()
            else
                _tooltip.open()
        }
    } // MouseArea

} // Item
