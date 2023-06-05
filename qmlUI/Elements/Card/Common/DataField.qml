import QtQuick
import QtQuick.Controls

import "../../../Common"

Rectangle {
    property string name
    property string value
    property Item tooltipItem: null

    id: _root

    color: "#fff"
    height: _text.implicitHeight < 40 ? 40 : _text.implicitHeight
    border.color: "#000"
    border.width: 2

    Text {
        id: _text
        text: "<b>" + _root.name + ":</b> " + _root.value
        font.pointSize: 12
        wrapMode: Text.WordWrap
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        padding: 5
    }

    TooltipPopup {
        id: _tooltip

        x: parent.width
        y: -(height/2)

        contentItem: _root.tooltipItem
    } // TooltipPopup

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (_root.tooltipItem == null)
                return

            if (_tooltip.opened)
                _tooltip.close()
            else
                _tooltip.open()
        }
    } // MouseArea
}
