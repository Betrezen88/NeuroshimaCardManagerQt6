import QtQuick

import "../../../Elements/Card/Common"
import "../../../Common"

Item {
    property alias name: _name.text

    id: _root
    height: _column.implicitHeight

    Column {
        id: _column

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

        x: parent.width
        y: -(height/2)

        contentItem: TooltipContent {
            width: 300
            title: _name.text
            description: "Walczący, który posiada Inicjatywę, może zdecydować się na zwiększenie tempa walki. Podnonosi PT własnych testów akcji, a jego przeciwnik będzie musiał zdawać testy na tym samym podwyższonym PT. Walczący może zwiększyć PT maksymalnie o tyle poziomów, ile posiada punktów używanej Umiejętności walki (Bijatyka lub Broń ręczna) i nie więcej niż 3."
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
