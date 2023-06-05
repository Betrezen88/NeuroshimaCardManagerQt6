import QtQuick
import QtQuick.Controls

import "../Common"

Column {
    id: _root

    spacing: 3

    Portrait {
        id: _portrait
        width: _root.width; height: 250
    }

    HeaderLabel {
        text: "Postać"
        width: _root.width; height: 40
    }

    DataField {
        id: _fullname
        width: _root.width
        name: "Imię"
        value: "Nick 'Happy' Sax"
    }

    DataField {
        id: _origin
        width: _root.width
        name: "Pochodzenie"
        value: "Vegas"
        tooltipItem: TooltipContent {
            width: 350
            title: _origin.value
            description: "Vegas to mieszanka mafiozów spod ciemnej gwiazdy i świrów. Gdy widzę - bez urazy - takich palantów jak Ty, spluwa sama wskakuje mi do ręki. Wszędzie węszycie interes i zysk, a najlepiej, gdy można jeszcze w coś zagrać i zgarnąć podwójną pulę. To jakaś choroba, nie wiem czym pieprznął w was Moloch, ale siadło wam na mózg i zlasowało go bez reszty. Nie potraficie żyć bez ryzyka.
        No dobra, ale kilku rzeczy nie można wam odmówić. Macie farta, zasrańcy, o tym wiedzą wszyscy. Nie wiem, czy to jakieś promieniowanie, czy inna cholera, ale to działa. Wtedy, dwa lata temu, zanim rozwaliłem tego palanta od drabiny, dwa razy pod rząd zaciął mi się Glock. Chłopcze, to się nie zdarza. No chyba, że akurat walisz do kogoś z Vegas.
        A nie uważasz tego za śmieszne, że wy wszyscy wierzycie w każddy głupie przesąd i dziecinne opowieści o duchach?
        A wiesz, co najbardziej mnie wkurza? Brak zasad. Wasze podejście do życia, ciągłe kantowanie i matactwa. Kombinowanie, jak zrobić krzywdę drugiemu, jak podłożyć mu nogę i zająć jego miejsce. Fakt, to daje wam niezłą odporność na działania innych. Fakt, zrobić w wała kogoś z Vegas, to sztuka. Fakt, często wychodzi na Twoje, bo potrafisz ściemniać jak nikt inny. Ale nie myśli, że Cię za to szanują. Ani trochę, cholerny, zakłamany, wierzący w duchy palancie."
        }
    }

    DataField {
        id: _profesion
        width: _root.width
        name: "Profesja"
        value: "Wojownik Autostrady"
        tooltipItem: TooltipContent {
            width: 350
            title: _profesion.value
            description: "Mieszkańcy Vegas mogą mówić, że w mieście jest niebezpiecznie. Że miasto to dżungla, w której przetrwa najsilniejszy. Miastowi... Nie widzieli prawdziwego niebezpieczeństwa. Nigdy nie byli ścigani przez zgraję żądnych krwi renegatów. Nie natkneli się na Keer Stonesów, czy Black Cats. Nie stali na środku Mohawe z pustym bakiem, przebita komorą silnika i stadem czerwonych na horyzoncie. Prawda jest taka, że jeśli miasto jest dżunglą, to autostrada jest piekłem.
        Jeśli chcesz żyć na autostradzie, jesli kochasz prędkość, ryk silnika i prawdziwe emocje - witaj na trasie. Ale wiedz jedno, od razu musisz podjąć decyzję albo dasz się wciągnąć do jednego z gangów - lecz wiedz, że prędzej czy później trafisz na mnie i pożałujesz tej decyzji. Albo naprawdę masz jaja i postanowisz działać w jedynkę, sprzątająć te bandy szumowin na rozklekotanych maszynach. W tym wypadku lepiej byś celnie strzelał, bo ich zawsze będzie zdecydowanie zbyt wielu, by móc sobie pozwolić na pudło. Lepiej byś cholernie dobrze prowadził swoją maszynę - bo zawsze te palanty próbują rozbić Cię w drobny mak. I wreszcie, lepiej byś miał ciepły koc.
        A co, chcesz marznąć po nocach?!"
        }
    }

    DataField {
        id: _specialization
        width: _root.width
        name: "Specjalizacja"
        value: "Technik"
        tooltipItem: TooltipContent {
            width: 350
            title: _specialization.value
            description: "Tak brachu, urodziłeś się ze śubokrętem w ręce. Potrafisz naprawić dosłownie wszystko, od samochodu, przez system sterowania pociskami, na mikserze kończąc. Wystarczy, że spojrzysz na jakieś plany, a już wiesz, co przedstawiają. Wystarczy, że dotkniesz, a już działa. To dar. Nie lekceważ go."
        }
    }

    DataField {
        id: _disease
        width: _root.width
        name: "Choroba"
        value: "Goraczka Sobotniej Nocy"
    }

    DataField {
        id: _originFeature
        width: _root.width
        name: "Cecha z pochodzenia"
        value: "Zalety klasycznego wyksztalcenia"
        tooltipItem: TooltipContent {
            width: 350
            title: _originFeature.value
            description: "Miałeś bardzo dobrych nauczycieli. Jeżeli na dalszym etapie tworzenia postaci wybierzesz jako specjalizację Technika, otrzymujesz dodatkowe 10 punktów do wydania na umiejętności oparte o Spryt."
        }
    }

    DataField {
        id: _profesionFeature
        width: _root.width
        name: "Cecha z profesji"
        value: "Drzwi w drzwi"
        tooltipItem: TooltipContent {
            width: 350
            title: _profesionFeature.value
            description: "Podtrafisz używać swojej maszynki jak broni i z tej właśnie okazji w czasie walki na autostradzie, podczas wszystkich manewrów samochodem masz +2 do Zręczności."
        }
    }

    DataField {
        id: _fame
        width: _root.width
        name: "Sława"
        value: "0"
    }

    Rectangle {
        id: _reputation
        color: "#fff"
        width: _root.width; height: 40
        radius: 10
        border.width: 2
        border.color: "#000"

        Text {
            text: "Reputacja"
            font.pointSize: 12
            font.bold: true
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: console.log("Show reputation popup")
        }
    }
} // Column
