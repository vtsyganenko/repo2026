import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    width: 300
    height: 300
    visible: true
    title: "Addition and subtraction"

    ColumnLayout {
        // stretches the container to fill the entire area of ​​the parent
        anchors.fill: parent
        // make margins from the window edges
        anchors.margins: 15
        // vertical space between elements in the layout
        spacing: 10

        TextField {
            id: firstValueField
            // take whole width
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
                Layout.fillWidth: true  // The buttons divide the width equally 
                onClicked: calc.add(firstValueField.text, secondValueField.text)
            }
            Button {
                text: "Sub"
                Layout.fillWidth: true  // The buttons divide the width equally 
                onClicked: calc.sub(firstValueField.text, secondValueField.text)
            }
            Button {
                text: "Clear"
                Layout.fillWidth: true  // The buttons divide the width equally 
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

        Button {
            text: "Exit"
            Layout.alignment: Qt.AlignHCenter
            onClicked: Qt.quit()
        }
    }
}
