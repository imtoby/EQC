import QtQuick 2.12

import "../commons"

Item {
    ListView {
        id: e_icons_container
        anchors.fill: parent
        orientation: ListView.Horizontal
        snapMode: ListView.SnapOneItem
        model: 3

        delegate: Item {
            implicitWidth: ListView.view.width
            implicitHeight: ListView.view.height

            Rectangle { // todo remove this codes
                anchors.fill: parent
                color: EColors.randomColor()
            }
        }
    }
}
