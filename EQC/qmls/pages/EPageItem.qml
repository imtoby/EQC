import QtQuick 2.12

Item {
    GridView {
        anchors.fill: parent
        model: 20
        cellWidth: 120
        cellHeight: 120
        property bool dragActived: false
        delegate: Item {
            width: 120
            height: 120

            Rectangle {
                implicitWidth: 76
                implicitHeight: 76
                anchors.centerIn: e_drag_mouse_area.drag.active ? undefined : parent
                border.width: 1
                border.color: "#DFDFDF"
                radius: 16

                Drag.active: e_drag_mouse_area.drag.active
                Drag.hotSpot.x: width/2
                Drag.hotSpot.y: height/2

                MouseArea {
                    id: e_drag_mouse_area
                    anchors.fill: parent
                    drag.target: parent
                }
            }

            Rectangle {
                implicitWidth: 76
                implicitHeight: 76
                color: "transparent"
                border.width: 1
                border.color: "#3264C8"
                radius: 16
                anchors.centerIn: parent
                visible: e_drag_mouse_area.drag.active
            }
        }
    }
}
