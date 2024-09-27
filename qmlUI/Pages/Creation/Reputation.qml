import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.creation 1.0
import core.source 1.0

import "../../Elements/Creation/Reputation"

Page {
    property CardCreation cardCreation: null

    id: _root

    ScrollView {
        id: _scrollView

        anchors {
            fill: parent
            margins: 5
        }

        Column {
            spacing: 15

            Text {
                text: "Reputacja"
                font.bold: true
                font.pointSize: 16
                height: implicitHeight
                bottomPadding: 10
            }

            TabBar {
                id: _tabBar
                width: _scrollView.width
                height: 50
                currentIndex: 0

                Repeater {
                    model: [ "Początkowa reputacja",
                            "Reputacja a miejsce",
                            "Zwiększenie reputacji",
                            "Wyposażenie a Reputacja",
                            "Testy reputacji",
                            "Sława" ]
                    delegate: TabButton {
                        text: modelData
                        font.underline: _tabBar.currentIndex == index
                        height: _tabBar.height
                        onClicked: _tabBar.currentIndex = index
                    }
                }
            } // TabBar

            StackLayout {
                id: _stackLayout
                width: _scrollView.width
                height: children[currentIndex].implicitHeight
                currentIndex: _tabBar.currentIndex

                Text {
                    font.pointSize: 14
                    wrapMode: Text.WordWrap
                    text: "Jeśli jesteś Sędzią lub szefem mafii, to pewnie już masz kilka punktów i choć nie wiesz jeszcze jak działają, pewnie strasznie się tym podnieciłeś, co?
    To fakt, startować z Punktami Repuracji to duża sprawa - trochę ich jeszcze uzbierasz i już zacznie Ci rosnąć Sława. A potem już tylko ktok do autografów itd...
    No dobrze, może jednak wrócimy do tematu, co? Każda postać zaczyna z 1 Punkemt Reputacji w miejscu swojego Pochodzenia (jeśli pochodzisz \"z nie twój zasrany interes\", wybierasz sobie dowolne miejsce). Symbolicznym jednym punktem. Cała reszta to już Twoja robota i kolejne przygody.
    Poczytaj więc, jak się zwiększa ilość PR, bo ten jeden punkt to wstyd..."
                }

                Text {
                    font.pointSize: 14
                    wrapMode: Text.WordWrap
                    text: "Każdy Punkt Reputacji przypisany jest miejscu, gdzie go zdobyłeś. Gdy zdobywasz nowe PR, wtedy na Karcie Postaci, w polu PR, wpisujesz nazwę miejsca i cyferkę. Co prawda, nie będziemy się bawili w zbyt dokładne umiejscawianie Twojej Reputacji, wystarczy, że podasz nazwę jednej z krain świata Neuroshimy, zaznaczonych na mapie."
                }

                Text {
                    font.pointSize: 14
                    wrapMode: Text.WordWrap
                    text: "Zasady reputacji są bardzo proste. Po każdej sesji, jeżeli podczas gry zdziałałeś cokolwiek i ludzie usłyszeli o Twoich dokonaniach lub też dokonałeś czegoś rzeczywiście spektakularnego, dostajesz Punkty Reputacji. MG może zdecydować o przyznaniu Ci od 1 do 3 PR dla miejsc, w którym toczyła sie gra. Wraz z przżytymi przygodami przybuwa Punktów Reputacji. Stajesz się sławny.
    Ponadto Reputację możesz podnosić również za Punkty Doświadczenia. Punkt Reputacji kosztuje 25 PD. Jeżeli dbasz o Reputację i zależy Ci na niej, to zaprocentuje."
                }

                Text {
                    font.pointSize: 14
                    wrapMode: Text.WordWrap
                    text: "Reputacja zależna jest również od wyposażenia, jakim dysponujesz. Niektóre elementy ekwipunku dodają Ci kilka PR. Widzisz moje buty? Robią wrażenie, prawda? A kapelusz? No i oczywiście sreprne spinki, przyznaj, nieźle wyglądają, nie? Mam nadzieję, że zauważyłeś, czym odpalam cygara... To oryginalny Zippo! To, co posiadasz mówi, kim jesteś. Jeśli zechcesz, spróbój, przespaceruj się przez ruiny miasta z coltem o rękojeści wykładanej masą perłową, a możesz być pewny, że mieszkańcy zwrócą na Ciebie większą uwagę, niż gdybyś niósł sztachetę.
    Reguły są takie: wyobraź sobie, że Twoja postać posiada kilka slotów, które możesz zapełnić albo byle badziewiem, albo ciuchem lub sprzętem najwyższej klasy. Oto, co wpływa na Twoją Reputację:
- Ciuchy (kapelusz, kurtka, buty, biżuteria itd.)
- Broń
- Pojazd</b> lub <b>wierzchowiec
- Sprzęt (cybogizacje, najwyższej klasy sprzęt elektroniczny lub mechaniczny, zapalniczka Zippo, gadżety)</li>
    Za każdą z tych rzeczy możesz dostać od 0 do 3 RP. Jeśli posiadasz byle badziewie, zapomnij o PR i lepiej siedź cicho, bo MG jeszcze Ci odbierze punkt czy dwa. Jeśli udało Ci się zdobyć naprawdę najwyższej klasy ciuch (buty z krokodyla, garnitur od Schulzów z Detroit), daje Ci to 1 PR. Żeby osiągnąć w jednej kategorii aż 2 PR, musi to być coś naprawdę \"mega wypas\", niejeden złodziej będzie za Tobą chodził i przez cały rok, czekając na okazdję. A 3 PR? Nawet nic mi takiego nie przychodzi do głowy... Może pancerz Stalowej Policji? I żebyśmy się dobrze zrozumieli, zakłądanie po pięć skórzanych kurtek Harley Davidson i noszenie trzech zapalniczek Zippo nie polepszy Ci stylu i nie przsporzy większej Reputacji, co najwyżej ktoś weźmie Cię za handlarza. Dobre rzeczy trzeba umieć nosić, sam wiesz."
                }

                Text {
                    font.pointSize: 14
                    wrapMode: Text.WordWrap
                    text: "Po zsumowaniu wszystkich otrzymanych dotychczas PR otrzymasz liczbę. To właśnie Twoja Reputacja. Za każdym razem, gdy będziesz poproszony o rzut, wykonujesz Bardzo Trudny test Charakteru (MG może zmienić PT w zależności od okoliczności). Jeśli Ci się powiodło, zdałeś Właśnie test Reputacji.
    Reputację można testować niemal zawsze, gdy Bohater spotyka nową osobę. Wygląda to jak zwykły test; rzucasz 3k20 i wynik musi być mniejszy lub równy Twojej Reputacji w danym miejscu. Udany test oznacza, że BN Cię zna, słyszał o Tobie i być może nabiera większego respektu do Ciebie. Im więcej Punktów Sukcesu uzyskaszw tym teście tym lepiej jesteś rozpoznawany. Jeśli rzut się nie uda, Bohater wyjdzie na przeciętnego śmieciojada ze zniszczonego przez wojnę świata - osobę, któ©a niewiele znaczy. W podobny sposób można testować Reputację BN - wynik testu będzie wskazówką dla graczy, jak mają traktować napotkane osoby.
    MG może postanowić, że efekt Reputacji znajdzie odzwierciedlenie przy testowaniu niektórych Umiejętności (np. Zastraszania, Perswazji lub Blefu). Warto też pamiętać, że Reputacja ma dwa aspekty. Dobra sława wynika ze śmiałych i bohaterskich czynów. Złą słąwą cieszą się mordercy, złodzieje i bandyci. Czasami Reputacja jest po prostu mieszanką złej i dobrej sławy, częściej jednak Bohaterem kieruje określony światopogląd i przyczyny jego słąwy są jasne.
    W jednej \"Strefie Reputacji\" możesz uzbierać maksymalnie 20 PR."
                }

                Text {
                    font.pointSize: 14
                    wrapMode: Text.WordWrap
                    text: "Jeśli uzbierasz 20 PR dla jednego miejsca, dzieje się coś, co bardzo cieszy. Zyskujesz dodatkowo jeden Punkt Sławy. Sława nie odnosi się tylko do aktualnej sytuacji i wykracza daleko poza okolicę, gdzie zdobyłeś ten punkt. Każdy Punkt Sławy traktowany jest jako dodatkowy Punkt Reputacji, tyle że działający w każdym zakichanym zakątku całych Stanów. Dodajesz go do swojej Reputacji podczas testów.
    Sława ma również bardzo praktyczny aspekt. W testach Reputacji (rzuty na Charakter), działa jak Umiejętność, czyli pozwala zmniejszać liczbę oczek wyrzuconych na kostakch. Podobnie jak w testach Umiejętności, tak i przy testowaniu Reputacji odezwać może się Suwak. Sława o wartości 4 obniża PT testu Charakteru do Trudnego, a 8 oznacza test Problematyczny.
    Zastanawiasz się, po co komu Reputacja i Sława? Po pierwsze dobrze jest czucć się powszechnie znanym bohaterem (albo sukinkotem). Wiesz jak to jest, kwiatki, mdlejące dziewczyny, staruszki przynoszą ciasto z dyni. Nie przemawia to do Ciebie?
    Pomyśl zatem o pracodawcach, którzy sami proszą się, byś coś dla nich zrobił i o gangersach ustępujących Ci z drogi na autostradzi. Oszczędność czasu, wysiłku i amunicji. Oto, co gwarantuje Reputacja."
                }
            } // StackLayout

            Row {
                spacing: 5
                Text {
                    text: "Dostępne punkty reputacji: "
                    font.pointSize: 14
                    font.bold: true
                    topPadding: 5
                    bottomPadding: 5
                }

                Text {
                    text: cardCreation?.skillpointsManager?.availableReputationPoints ?? 0
                    font.pointSize: 14
                    topPadding: 5
                    bottomPadding: 5
                }
            } // Row

            Grid {
                columns: 2
                columnSpacing: 20
                rowSpacing: 5

                Repeater {
                    property int labelWidth: 0

                    id: _places

                    model: cardCreation?.statisticsCreation?.reputations ?? []
                    delegate: Place {
                        reputation: modelData
                        labelWidth: _places.labelWidth
                        hasAvailablePoints: cardCreation?.skillpointsManager?.availableReputationPoints ?? false
                        isGeneralPoint: cardCreation?.skillpointsManager?.isReputationGeneralPoint ?? false
                        Component.onCompleted: _places.labelWidth = _places.labelWidth < implicitLabelWith ? implicitLabelWith : _places.labelWidth
                    } // Place
                } // Repeater
            } // Grid
        } // Column

    } // ScrollView

    background: Rectangle {
        color: "#fff"
    }
} // Page
