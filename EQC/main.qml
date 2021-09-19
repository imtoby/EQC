import QtQuick 2.12
import QtQuick.Window 2.12

import "./qmls/widgets"
import "./qmls/commons"

Window {
    width: 480
    height: 848
    visible: true
    title: qsTr("EQC")

    ESlidePathLocker {
        anchors.centerIn: parent

        EFrame {
            anchors.fill: parent
            border.color: EColors.gray
        }
    }
}
