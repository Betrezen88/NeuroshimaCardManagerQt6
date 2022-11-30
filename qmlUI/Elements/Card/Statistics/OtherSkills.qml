import QtQuick

import "../../../Delegates/Card/Statistics/OtherSkill"

Rectangle {
    property alias skillsModel: _skills.model

    id: _root

    border.width: 2
    border.color: "#000"

    ListView {
        id: _skills
        clip: true
        spacing: 3
        anchors { fill: parent; margins: 4 }

        delegate: OtherSkill {
            width: ListView.view.width
            skillName: model.name
            skillAttribute: model.attribute
            skillValue: model.value
        }

    } // ListView
} // Rectangle
