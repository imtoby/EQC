import QtQuick 2.12
import QtQuick.Controls 2.12

import "../commons"
import "../../qqr.js-master"

Item {

    SwipeView {
        id: e_home_view
        anchors.fill: parent
        currentIndex: 2

        Item {
            id: e_first_page
            QRCode {
                id: loginQrcodeContainer
                width: 196
                height: 196
                anchors.centerIn: parent
                value: "https://github.com/M4rtinK/qqr.js"
            }
        }

        Item {
            id: e_second_page
            Column {
                Image { source: "image://async/slow" }
                Image { source: "image://async/fast" }
            }
        }

        Item {
            id: e_third_page

            DropArea {
                x: 75; y: 75
                width: 50; height: 50

                Rectangle {
                    anchors.fill: parent
                    color: "green"

                    visible: parent.containsDrag
                }
            }

            Rectangle {
                x: 10; y: 10
                width: 20; height: 20
                color: "red"

                Drag.active: dragArea.drag.active
                Drag.hotSpot.x: 10
                Drag.hotSpot.y: 10

                MouseArea {
                    id: dragArea
                    anchors.fill: parent

                    drag.target: parent
                }
            }
        }
    }

    PageIndicator {
        id: e_home_indicator

        count: e_home_view.count
        currentIndex: e_home_view.currentIndex

        anchors.bottom: e_home_view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
