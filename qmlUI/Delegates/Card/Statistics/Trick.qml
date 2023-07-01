import QtQuick

import core.view

import "../../../Common"
import "../../../Elements/Card/Statistics"

Item {
    property Trick trick: null

    id: _root

    Text {
        id: _name
        text: trick != null ? trick.name : "Trick name"
        font.pointSize: 12
        anchors.centerIn: parent
    }

    TooltipPopup {
        id: _tooltip

        x: parent.width
        y: -(height - _root.height)

        contentItem: TrickTooltip {
            width: 350
            maxHeight: 250
            title: _name.text
            requirements: trick != null ? trick.requirementsString() : ""
            description: trick != null ? trick.description : "Opis sztuczki"
            action: trick != null ? trick.action : "Wytłumaczenie sztuczki"
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
    }

    Rectangle {
        color: "#000"
        height: 2; width: _root.width
        anchors { bottom: parent.bottom }
    }
} // Rectangle
