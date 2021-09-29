import QtQuick 2.12

Image {
    id: e_image
    objectName: "EImage.qml"
    asynchronous: true
    cache: false

    signal loaded()

    readonly property bool isLoaded: Image.Ready === status

    onStatusChanged: {
        if (Image.Ready === status) {
            loaded()
        }
    }
}
