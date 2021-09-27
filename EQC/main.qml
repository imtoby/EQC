import QtQuick 2.12
import QtQuick.Window 2.12

import "./qmls/pages"
import "./qmls/commons"

Window {
    width: 480
    height: 848
    visible: true
    title: qsTr("EQC")

    EHomePage {
        anchors.fill: parent
    }
}
