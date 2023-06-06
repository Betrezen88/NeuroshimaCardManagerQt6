import QtQuick

import "../../../Common"
import "../../../Elements/Card/Statistics"

Item {
    property alias name: _name.text

    id: _root

    Text {
        id: _name
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
            title: "Sztuczka"
            requirements: "Mechanika 3, Mat. wybuchowe 3"
            description: "Wszystkie urządzenia na świecie można podzielić na takie, które czasem wybuchają i takie, które nigdy nie wybuchają. Szczególnie interesują Cię te pierwsze. Wystarczy tu przeciąć wężyk, tam skręcić kabel, tu znów poluzować śrubkę. I gotowe. Teraz wystarczy poczekać na fajerwerki."
            action: "Możesz uzbroić - jak bombę - dowolny pojazd, urządzenie czy maszynę napędzaną łatwopalnym paliwem. Kwadrans spokojnej pracy i możesz zacząć odliczanie. Czas wybuchu określa z pięćdziesięcio procentową dokładnością na sekundę, minutę, , kwadrans lub godzinę(np. gdy wybierzesz minutę, spodziewaj się między pół a półtorej minuty). Czasem, jeśli MG pozwoli nawet na tydzień . Siła wybuchu zależy od rodzaju urządzenia. Możesz uzbroić - jak bombę - dowolny pojazd, urządzenie czy maszynę napędzaną łatwopalnym paliwem. Kwadrans spokojnej pracy i możesz zacząć odliczanie. Czas wybuchu określa z pięćdziesięcio procentową dokładnością na sekundę, minutę, , kwadrans lub godzinę(np. gdy wybierzesz minutę, spodziewaj się między pół a półtorej minuty). Czasem, jeśli MG pozwoli nawet na tydzień . Siła wybuchu zależy od rodzaju urządzenia."
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
