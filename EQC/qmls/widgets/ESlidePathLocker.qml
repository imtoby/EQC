import QtQuick 2.12

import "../commons"

EMouseArea {
    id: e_slide_path_locker
    objectName: "ESlidePathLocker.qml"
    implicitWidth: 400
    implicitHeight: 400

    property color mainColor: EColors.black

    Grid {
        id: e_grid_container
        anchors.centerIn: parent
        columns: 3
        spacing: 0
        Repeater {
            model: 9
            delegate: e_slide_path_locker_item_component
        }
    }

    Component {
        id: e_slide_path_locker_item_component
        Item {
            id: e_slide_path_locker_item
            implicitWidth: 100
            implicitHeight: 100
            state: "normal"

            EFrame {
                id: e_frame
                anchors.fill: parent
                anchors.margins: 20
                radius: width/2
                border.width: 2
                border.color: mainColor
            }

            ERectangle {
                id: e_center
                implicitWidth: 16
                implicitHeight: 16
                anchors.centerIn: parent
                radius: width/2
                color: mainColor
            }

            states: [
                State {
                    name: "normal"
                    PropertyChanges {
                        target: e_frame
                        visible: false
                    }
                    PropertyChanges {
                        target: e_center
                        opacity: 0.2
                    }
                }
            ]
        }
    }

    ListModel {
        id: e_slide_path_locker_model
    }
}
