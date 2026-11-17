import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import Backend.Calculation 1.0
import Backend.Logger 1.0
import Backend.History 1.0

Window {
    width: 300
    height: 600
    visible: true
    title: "Addition and subtraction"

    Calculator {
        id: calc
    }

    // signal also could be caught in the Calculator above
    Connections {
        target: calc
        // Qt 5.15
        function onExpressionEvaluated(expression) {
            console.log(expression)
            Logger.log(expression)
            historyModel.addItem(expression)
        }
    }

    History {
        id: historyModel
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 15
        spacing: 10

        TextField {
            id: firstValueField
            Layout.fillWidth: true
            selectByMouse: true
            validator: DoubleValidator {}
        }

        TextField {
            id: secondValueField
            Layout.fillWidth: true
            selectByMouse: true
            validator: DoubleValidator {}
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Button {
                text: "Add"
                Layout.fillWidth: true
                onClicked: calc.add(firstValueField.text, secondValueField.text)
            }
            Button {
                text: "Sub"
                Layout.fillWidth: true
                onClicked: calc.sub(firstValueField.text, secondValueField.text)
            }
            Button {
                text: "Clear"
                Layout.fillWidth: true
                onClicked: {
                    firstValueField.text = ""
                    secondValueField.text = ""
                    calc.clearResult()
                }
            }
        }

        TextField {
            id: resultField
            Layout.fillWidth: true
            readOnly: true
            selectByMouse: true
            text: calc.result
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: historyModel
            delegate: Text {
                text: "[" + model.timestamp + "] " + model.expression
            }
            onCountChanged: positionViewAtEnd()
        }

        Button {
            text: "Exit"
            Layout.alignment: Qt.AlignHCenter
            onClicked: Qt.quit()
        }
    }
}
