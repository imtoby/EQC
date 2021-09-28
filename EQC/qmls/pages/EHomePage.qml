import QtQuick 2.12
import QtQuick.Controls 2.12

import "../commons"

Item {

    SwipeView {
        id: e_home_view
        anchors.fill: parent
        currentIndex: 1

        Item {
            id: e_first_page
        }
        Item {
            id: e_second_page
        }
        Item {
            id: e_third_page
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
