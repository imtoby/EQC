import QtQuick 2.12

import "../commons"

Item {
    id: e_slide_path_locker
    objectName: "ESlidePathLocker.qml"
    implicitWidth: 400
    implicitHeight: 400

    Grid {
        id: e_grid_container
        anchors.fill: parent
        anchors.margins: 50
        columns: 3
        spacing: 0
        Repeater {
            model: 9
            delegate: e_slide_path_locker_item_component
        }
    }

    Component {
        id: e_slide_path_locker_item_component
        EMouseArea {
            id: e_slide_path_locker_item
            implicitWidth: 100
            implicitHeight: 100

            EFrame {
                anchors.fill: parent
                anchors.margins: 20
                radius: width/2
                border.width: 2
                border.color: EColors.black
            }
        }
    }
}
