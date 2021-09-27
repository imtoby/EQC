pragma Singleton
import QtQuick 2.12

QtObject {
    readonly property color red: "#FF0031"
    readonly property color green: "#03B85F"
    readonly property color gray: "#E8E8E8"
    readonly property color normalText: "#A0A0A0"
    readonly property color black: "#38303D"

    readonly property color transparent: "transparent"

    readonly property color grayText: "#909199"
    readonly property color grayNormal: "#1A1B1F"
    readonly property color graySwitchOff: "#515259"

    function randomColor() {
        const letters = '0123456789ABCDEF'
        let result = '#'
        for (let i = 0; i < 6; i++) {
            result += letters[Math.floor(Math.random() * 16)]
        }
        return result
    }
}
