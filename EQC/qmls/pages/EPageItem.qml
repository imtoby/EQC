import QtQuick 2.12

Item {
    GridView {
        anchors.fill: parent
        model: 20
        cellWidth: 120
        cellHeight: 120
        delegate: Rectangle {
            width: 120
            height: 120
            border.width: 1
            border.color: "#DFDFDF"
            radius: 24
        }
    }
}
