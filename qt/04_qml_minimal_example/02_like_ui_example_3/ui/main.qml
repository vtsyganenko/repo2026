// 2.15 for qt 5.15
import QtQuick 2.15             // base types and anchors
import QtQuick.Window 2.15
import QtQuick.Controls 2.15    // Label and Button
import QtQuick.Layouts 1.15     // ColumnLayout

Window {
    width: 300
    height: 300
    visible: true   // analog of window.show
    title: "Hello"

    property int counter: 0 // user property

    ColumnLayout {
        // connect all 4 sides to the parent
        anchors.fill: parent
        // remove standard spacing (5)
        spacing: 0

        Item {
            // every element gets equal width
            Layout.fillWidth: true
            // every element gets equal height
            Layout.fillHeight: true
            Label {
                // put to the center of parent
                anchors.centerIn: parent
                text: counter.toString()
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Button {
                anchors.centerIn: parent
                text: "Increase"
                onClicked: counter++
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Button {
                anchors.centerIn: parent
                text: "Exit"
                onClicked: Qt.quit()
            }
        }
    }
}
