import QtQuick 2.15

import "../../../Delegates/Card/Equipment/"

Item {
    id: _root

    Row {
        anchors.fill: parent
        spacing: 1

        Resource {
            id: _drugs
            name: "Leki"
            value: 7
            width: (_root.width / 3) - parent.spacing
            height: _root.height
        }

        Resource {
            id: _food
            name: "Zywnosc"
            value: 7
            width: (_root.width / 3) - parent.spacing
            height: _root.height
        }

        Resource {
            id: _water
            name: "Woda"
            value: 7
            width: (_root.width / 3)
            height: _root.height
        }
    }
}
