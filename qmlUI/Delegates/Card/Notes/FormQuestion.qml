import QtQuick
import QtQuick.Controls

Rectangle {
    property alias question: _question.text
    property alias description: _description.text
    property alias answer: _answer.text

    id: _root

    height: _column.implicitHeight

    Column {
        id: _column
        anchors.fill: parent

        Text {
            id: _question
            width: parent.width
            text: model.question
            font.pointSize: 12
            font.bold: true
            wrapMode: Text.WordWrap
            padding: 2
        }

        Text {
            id: _description
            width: parent.width
            text: model.description
            font.pointSize: 12
            font.italic: true
            wrapMode: Text.WordWrap
            padding: 2
        }

        TextArea {
            id: _answer
            width: parent.width
            font.pointSize: 12
            color: "#000"
            wrapMode: Text.WordWrap
            topPadding: 5
            leftPadding: 2
            rightPadding: 2
            bottomPadding: 2
        }
    } // Column
} // Rectangle
