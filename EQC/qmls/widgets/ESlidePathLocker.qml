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

        property int currentIndex: -1

        function positionIndex(posX, posY) {
            if (posX < 50 || posY < 50) {
                return -1
            }
            if (posX < 350 && posY < 350) {
                const tmpX = parseInt((posX - 51)/100)
                const tmpY = parseInt((posY - 51)/100)
                return tmpX + tmpY * 3
            }
            return -1
        }

        Repeater {
            model: e_slide_path_locker_model
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
                }, State {
                    name: "enter"
                    PropertyChanges {
                        target: e_frame
                        visible: true
                        opacity: 0.1
                    }
                    PropertyChanges {
                        target: e_center
                        opacity: 0.2
                        scale: 2
                    }
                }
            ]
        }
    }

    ListModel {
        id: e_slide_path_locker_model
        Component.onCompleted: {
            for (let i = 0; i < 9; ++i) {
                append({"selected": false})
            }
        }
    }

    ETimer {
        id: e_interval_timer
        interval: 500
        repeat: true
        onTriggered: {
            if (isPressAndHold) {
                let tmpIndex = e_grid_container.positionIndex(mouseX, mouseY)
                console.log("ZDS===currentIndex: ", tmpIndex)
            }
        }
    }

    onPressed: {
        e_interval_timer.restart()
    }

    onReleased: {
        e_interval_timer.stop()
    }

    onCanceled: {
        e_interval_timer.stop()
    }
}
