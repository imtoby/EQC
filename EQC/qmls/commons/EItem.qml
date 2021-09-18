import QtQuick 2.12

Item {
    id: e_item
    objectName: "EItem.qml"

    function createComponentByQrcBaseName(baseName, baseDir = "qmls") {
        return Qt.createComponent(("qrc:/%1/%2.qml").arg(baseDir).arg(baseName))
    }
}
