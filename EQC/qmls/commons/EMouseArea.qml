import QtQuick 2.12

MouseArea {
    id: e_mouse_area
    objectName: "EMouseArea.qml"

    property bool isPressAndHold: false

    onPressAndHold: {
        isPressAndHold = true
    }

    onReleased: {
        isPressAndHold = false
    }

    onCanceled: {
        isPressAndHold = false
    }
}
