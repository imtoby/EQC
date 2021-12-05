import QtQuick 2.12

Item {
    GridView {
        anchors.fill: parent
        model: 20
        cellWidth: 120
        cellHeight: 120
        delegate: Item {
            width: 120
            height: 120

            Rectangle {
                implicitWidth: 76
                implicitHeight: 76
                anchors.centerIn: parent
                border.width: 1
                border.color: "#DFDFDF"
                radius: 16
            }
        }
    }
}
