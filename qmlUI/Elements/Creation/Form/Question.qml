import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import core.creation 1.0

import "../../Card/Common"

Item {
    property AnswerCreation answer: null
    property int number: 0

    id: _root

    Column {
        spacing: 5

        onImplicitHeightChanged: _root.height = implicitHeight

        Text {
            text: (number > 0 ? number + ". " : "") + answer?.source?.question ?? ""
            font.pointSize: 14
            font.bold: true
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignJustify
            width: _root.width
        }

        Text {
            text: answer?.source?.description
            font.italic: true
            font.pointSize: 14
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignJustify
            width: _root.width
        }

        ScrollTextArea {
            width: _root.width
            height: 100
            onTextUpdated: function(text) {
                answer.answer = text
            }
        }
    } // Column
} // Item
