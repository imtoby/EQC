import QtQuick 2.12

import "../commons"

EMouseArea {
    id: e_slide_path_locker
    objectName: "ESlidePathLocker.qml"
    implicitWidth: lockAreaSize
    implicitHeight: lockAreaSize

    property int lockAreaSize: 400
    readonly property int stepValue: parseInt(lockAreaSize / 8)
    readonly property int cellMargin: parseInt(stepValue * 2 / 5)
    readonly property int cellSize: (stepValue - cellMargin) * 2
    property color mainColor: EColors.black

    Canvas {
        id: e_drawing_line
        anchors.fill: parent
        onPaint: {
            if (e_grid_container.selectPoint.length > 0) {
                let ctx = getContext("2d")

                ctx.fillStyle = "transparent"
                ctx.fillRect(0, 0, e_drawing_line.width, e_drawing_line.height)

                ctx.lineWidth = 3;
                ctx.strokeStyle = mainColor
                ctx.beginPath()
                const startPoint = e_grid_container.selectPoint[0]
                ctx.moveTo(startPoint.width, startPoint.height)
                let nextPoint = null
                for (let i = 1; i < e_grid_container.selectPoint.length; ++i) {
                    nextPoint = e_grid_container.selectPoint[i]
                    ctx.lineTo(nextPoint.width, nextPoint.height)
                    ctx.moveTo(nextPoint.width, nextPoint.height)
                }
                ctx.stroke()
            }
        }
    }

    Grid {
        id: e_grid_container
        anchors.centerIn: parent
        columns: 3
        spacing: 0

        property var selectArray: []
        property var selectPoint: []

        function checkTimerRunnable() {
            return selectPoint.length < 9
        }

        function childIndex(pos) {
            if ((pos > (stepValue + cellMargin))
                    && (pos < (stepValue + cellMargin + cellSize))) {
                return 0
            } else if ((pos > (stepValue + cellMargin*3 + cellSize*1))
                       && (pos < (stepValue + cellMargin*3 + cellSize*2))) {
                return 1
            } else if ((pos > (stepValue + cellMargin*5 + cellSize*2))
                       && (pos < (stepValue + cellMargin*5 + cellSize*3))) {
                return 2
            }
            return -1
        }

        function positionIndex(posX, posY) {
            const tmpX = childIndex(posX)
            const tmpY = childIndex(posY)
            return (tmpX >= 0 && tmpY >= 0) ? (tmpX + tmpY * 3) : -1
        }

        function indexCenterPosition(index) {
            const rowIndex = parseInt(index / 3) + 1
            const columnIndex = index % 3 + 1
            return Qt.size(columnIndex * 2*stepValue, rowIndex * 2*stepValue)
        }

        function pushPoint(index) {
            selectPoint.push(indexCenterPosition(index))
            e_drawing_line.requestPaint()
            if (!checkTimerRunnable) {
                e_interval_timer.stop()
            }
        }

        function selectable(index) {
            return -1 === selectArray.indexOf(index)
        }

        function insert(index) {
            selectArray.push(index)
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

        function setState(index, state) {
            get(index).currentState = state
        }
    }

    ETimer {
        id: e_interval_timer
        objectName: "check_enter"
        interval: 100
        repeat: true
        triggeredOnStart: true
        onTriggered: {
            const enterIndex = e_grid_container.positionIndex(mouseX, mouseY)
            if ((-1 !== enterIndex)
                    && e_grid_container.selectable(enterIndex)) {
                e_slide_path_locker_model.setState(enterIndex, "enter")
                e_grid_container.insert(enterIndex)
                EDelayCaller.run(200, function () {
                    e_slide_path_locker_model.setState(enterIndex, "selected")
                })
                e_grid_container.pushPoint(enterIndex)
            }
        }
    }

    onPressed: {
        if (e_grid_container.checkTimerRunnable()) {
            e_interval_timer.restart()
        }
    }

    onReleased: {
        e_interval_timer.stop()
    }

    onCanceled: {
        e_interval_timer.stop()
    }
}
