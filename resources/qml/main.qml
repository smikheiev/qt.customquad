import QtQuick.Window 2.2
import QtQuick 2.7

import SM.Extensions 1.0

Window {
    width: 800
    height: 600

    visible: true
    title: qsTr("Custom Quad")

    CustomQuadTest {
        anchors.fill: parent
    }
}
