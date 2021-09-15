import QtQuick 2.12

import "../commons"

EMouseArea {
    id: e_clicked_counter
    objectName: "EClickedCounter.qml"

    property int times: 5
    property alias clickedInterval: e_trigger_timer.interval

    signal triggered()

    onClicked: {
        e_trigger_timer.restart()
        ++e_trigger_timer.times
        if (e_trigger_timer.times >= times) {
            e_clicked_counter.triggered()

            e_trigger_timer.stop()
            e_trigger_timer.triggered()
        }
    }

    Timer {
        id: e_trigger_timer
        interval: 800
        objectName: parent.objectName + "e_trigger_timer"
        property int times: 0
        onTriggered: {
            times = 0
        }
    }
}
