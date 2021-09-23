import QtQuick 2.12

import "../commons"

EMouseArea {
    id: e_slide_path_locker
    objectName: "ESlidePathLocker.qml"
    implicitWidth: lockAreaSize
    implicitHeight: lockAreaSize

    property int lockAreaSize: 400
    readonly property int stepValue: parseInt(lockAreaSize / 8)
    property color mainColor: EColors.black

    Canvas {
        id: e_drawing_line
        anchors.fill: parent
        onPaint: {
            let ctx = getContext("2d")

            ctx.fillStyle = "white"
            ctx.fillRect(0, 0, e_drawing_line.width, e_drawing_line.height)

            ctx.lineWidth = 1;
            ctx.strokeStyle = mainColor
            ctx.beginPath()
            ctx.moveTo(100, 100)
            ctx.lineTo(200, 200)
            ctx.stroke()
        }
    }

    Grid {
        id: e_grid_container
        anchors.centerIn: parent
        columns: 3
        spacing: 0

        property int currentIndex: -1
        property var selectArray: []

        function positionIndex(posX, posY) {
            if (posX < stepValue || posY < stepValue) {
                return -1
            }
            if (posX < 7*stepValue && posY < 7*stepValue) {
                const tmpX = parseInt((posX - stepValue - 1)/(2 * stepValue))
                const tmpY = parseInt((posY - stepValue - 1)/(2 * stepValue))
                return tmpX + tmpY * 3
            }
            return -1
        }

        function indexCenterPosition(index) {
            const rowIndex = parseInt(index / 3) + 1
            const columnIndex = index % 3 + 1
            return Qt.size(columnIndex * 2 * stepValue,  rowIndex * 2 * stepValue)
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
            implicitWidth: stepValue * 2
            implicitHeight: stepValue * 2
            state: currentState

            EFrame {
                id: e_frame
                anchors.fill: parent
                anchors.margins: parseInt(stepValue * 2 / 5)
                radius: width/2
                border.width: 2
                border.color: mainColor
            }

            ERectangle {
                id: e_center
                implicitWidth: parseInt(stepValue * 1.6 / 5)
                implicitHeight: parseInt(stepValue * 1.6 / 5)
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
                        scale: 1
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
                        scale: 3.6
                    }
                }, State {
                    name: "selected"
                    PropertyChanges {
                        target: e_frame
                        visible: true
                        opacity: 1
                    }
                    PropertyChanges {
                        target: e_center
                        opacity: 1
                        scale: 1
                    }
                }
            ]
        }
    }

    ListModel {
        id: e_slide_path_locker_model
        Component.onCompleted: {
            for (let i = 0; i < 9; ++i) {
                append({"currentState": "normal"})
            }
        }
    }

    ETimer {
        id: e_interval_timer
        interval: 200
        repeat: true
        triggeredOnStart: true
        onTriggered: {
            const enterIndex = e_grid_container.positionIndex(mouseX, mouseY)
            if ((-1 !== enterIndex) && (-1 === e_grid_container.selectArray.indexOf(enterIndex))) {
                console.log("ZDS===currentIndex: ", enterIndex)
                e_slide_path_locker_model.get(enterIndex).currentState = "enter"
                e_grid_container.selectArray.push(enterIndex)
                EDelayCaller.run(200, function (){
                    e_slide_path_locker_model.get(enterIndex).currentState = "selected"
                })
                if (e_grid_container.currentIndex > -1) {
                    console.log("ZDS===currentIndex: ", e_grid_container.indexCenterPosition(e_grid_container.currentIndex))
                }
                e_grid_container.currentIndex = enterIndex
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
