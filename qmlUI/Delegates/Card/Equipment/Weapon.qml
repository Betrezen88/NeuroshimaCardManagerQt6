import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../../../Elements/Card/Equipment/"

Rectangle {
    property alias name: _name.text
    property string type
    property var stats

    id: _root
    height: _column.implicitHeight

    color: "#fff"

    border.color: "#000"
    border.width: 2

    Column {
        id: _column

        Label {
            id: _name
            width: _root.width
            padding: 5
            color: "#fff"
            font.pointSize: 12
            background: Rectangle {
                color: "#000"
            }
        }
        Component.onCompleted: addStatsComponent(_root.type)

        function addStatsComponent(type) {
            var componentType = type === "ranged" ? "StatsWeaponRanged.qml" : "StatsWeaponMelee.qml"

            var component = Qt.createComponent("qrc:/QmlUI/Elements/Card/Equipment/" + componentType);
            if (component.status === Component.Ready) {
                var object = component.createObject(_column, {width: _root.width - 4/*, stats: _root.stats*/});
            }
            else {
                console.log("Component status not ready: ", component.status)
                console.log(component.errorString())
            }
        }
    }
}
