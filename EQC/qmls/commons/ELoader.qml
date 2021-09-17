import QtQuick 2.12

Loader {
    id: e_loader
    objectName: "ELoader.qml"
    asynchronous: true
    active: false

    function loadComponent() {
        active = true
    }

    function unloadComponent() {
        active = false
    }

    readonly property bool isLoaded: status === Loader.Ready
}
