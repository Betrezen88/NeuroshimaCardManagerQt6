import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../../Card/Common"

Item {
    property alias question: _question.text
    property alias description: _description.text
    property alias answer: _answer.text

    id: _root

    Column {
        spacing: 5

        onImplicitHeightChanged: _root.height = implicitHeight

        Text {
            id: _question
            font.pointSize: 14
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignJustify
            width: _root.width
        }

        Text {
            id: _description
            font.italic: true
            font.pointSize: 14
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignJustify
            width: _root.width
        }

        ScrollTextArea {
            id: _answer
            width: _root.width
            height: 100
        }
    } // Column
} // Item
