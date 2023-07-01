import QtQuick
import QtQuick.Controls

import core.view

import "../Common"
import "../../../Common"

Column {
    property Statistics pData: null

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
        value: pData === null ? "" : pData.fullname
    }

    DataField {
        id: _origin
        width: _root.width
        name: "Pochodzenie"
        value: pData.origin.name
        tooltipItem: TooltipContent {
            width: 350
            title: _origin.value
            description: pData.origin.description
        }
    }

    DataField {
        id: _profesion
        width: _root.width
        name: "Profesja"
        value: pData.profession.name
        tooltipItem: TooltipContent {
            width: 350
            title: _profesion.value
            description: pData.profession.description
        }
    }

    DataField {
        id: _specialization
        width: _root.width
        name: "Specjalizacja"
        value: pData.specialization.name
        tooltipItem: TooltipContent {
            width: 350
            title: _specialization.value
            description: pData.specialization.description
        }
    }

    DataField {
        id: _disease
        width: _root.width
        name: "Choroba"
        value: pData.disease.name
        tooltipItem: DiseaseTooltip {
            width: 350
            height: 300
            title: _disease.value
            description: pData.disease.description
            cure: pData.disease.cure
            symptoms: pData.disease.symptoms
        }
    }

    DataField {
        id: _originFeature
        width: _root.width
        name: "Cecha z pochodzenia"
        value: pData.origin.feature.name
        tooltipItem: TooltipContent {
            width: 350
            title: _originFeature.value
            description: pData.origin.feature.description
        }
    }

    DataField {
        id: _profesionFeature
        width: _root.width
        name: "Cecha z profesji"
        value: pData.profession.feature.name
        tooltipItem: TooltipContent {
            width: 350
            title: _profesionFeature.value
            description: pData.profession.feature.description
        }
    }

    DataField {
        id: _fame
        width: _root.width
        name: "Sława"
        value: pData.reputation.fame()
    }

    Button {
        width: _root.width; height: 40

        contentItem: Text {
            text: "Reputacja"
            color: "#000"
            font.pointSize: 12
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        background: Rectangle {
            border.width: 2
            border.color: "#000"
        }

        TooltipPopup {
            id: _repTooltip

            x: parent.width
            y: -(height/2)

            contentItem: ReputationTooltip {
                width: 300; height: 300
                title: "Reputacja"
                places: pData.reputation.places
            }
        }

        onClicked: {
            if (_repTooltip.opened)
                _repTooltip.close()
            else
                _repTooltip.open()
        }
    } // Button

} // Column
