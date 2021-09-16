import QtQuick 2.12

Timer {
    objectName: "ETimer.qml"

    onRunningChanged: {
        if (EConstants.isBaseDebugInfoShow) {
            console.log("ETimer_", objectName, running ? " running" : " stop")
        }
    }
}
