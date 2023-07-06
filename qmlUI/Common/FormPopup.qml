import QtQuick
import QtQuick.Controls

Popup {
    id: _root
    dim: true

    anchors.centerIn: Overlay.overlay
    Overlay.modeless: Rectangle {
        color: "#aacfdbe7"
    }

    background: Rectangle {
        color: "#fff"
        border.width: 2
        border.color: "#000"
    }
}
