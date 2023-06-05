import QtQuick
import QtQuick.Controls

Rectangle {
    property string name
    property string value
    property Item tooltipItem: null
    property int tooltipWidth

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

    Popup {
        id: _tooltip
        width: _root.tooltipItem != null ? _root.tooltipItem.width : 0
        padding: 5
        x: parent.width
        y: -(height/2)

        contentItem: _root.tooltipItem

        background: Rectangle {
            border.width: 2
            border.color: "#000"
        }
    } // Popup

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (tooltipItem == null)
                return

            if (_tooltip.opened)
                _tooltip.close()
            else
                _tooltip.open()
        }
    } // MouseArea
}
