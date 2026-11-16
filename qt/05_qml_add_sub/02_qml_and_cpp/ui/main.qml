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
                onClicked: add()
            }
            Button {
                text: "Sub"
                Layout.fillWidth: true  // The buttons divide the width equally 
                onClicked: sub()
            }
            Button {
                text: "Clear"
                Layout.fillWidth: true  // The buttons divide the width equally 
                onClicked: clear()
            }
        }

        TextField {
            id: resultField
            Layout.fillWidth: true
            readOnly: true
            selectByMouse: true
        }

        Button {
            text: "Exit"
            Layout.alignment: Qt.AlignHCenter
            onClicked: Qt.quit()
        }
    }

    function parse() {
        let first = parseFloat(firstValueField.text.replace(",", "."))
        let second = parseFloat(secondValueField.text.replace(",", "."))

        if (isNaN(first) || isNaN(second)) {
            resultField.text = "Error: NaN"
            return undefined
        }
        return [first, second]
    }

    function add() {
        let values = parse()
        if(values) {
            let res = calc.add(values[0], values[1])
            resultField.text = res.toString()
        }
    }

    function sub() {
        let values = parse()
        if(values) {
            let res = calc.sub(values[0], values[1])
            resultField.text = res.toString()
        }
    }

    function clear() {
        firstValueField.text = ""
        secondValueField.text = ""
        resultField.text = ""
    }
}
