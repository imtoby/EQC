import QtQuick 2.12

Rectangle {
    id: e_switcher
    objectName: "ESwitcher.qml"
    implicitWidth: 80
    implicitHeight: 44
    radius: 22
    smooth: true
    color: switchOn ? onColor : offColor

    property color onColor: EColors.green
    property color offColor: EColors.graySwitchOff

    readonly property bool switching: e_transition_animation.running

    property bool switchOn: false

    function setSwitchOn() {
        switchOn = true
    }

    function setSwitchOff() {
        switchOn = false
    }

    Rectangle {
        implicitWidth: 36
        implicitHeight: 36
        radius: 18
        color: EColors.white
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: !switchOn ? 4 : 40
        Behavior on anchors.leftMargin {
            NumberAnimation {
                id: e_transition_animation
            }
        }
    }
}
