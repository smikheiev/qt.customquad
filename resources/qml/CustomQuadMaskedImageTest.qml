import QtQuick 2.7

import SM.Extensions 1.0

Item {
    id: customQuadMaskedImageTest

    readonly property var images: ["owl.jpg", "kingfisher.jpg", ""]
    property int currentImageIndex: 0

    property int topLeftX: 0
    property int topLeftY: 0
    property int topRightX: 300
    property int topRightY: 0
    property int bottomRightX: 300
    property int bottomRightY: 300
    property int bottomLeftX: 0
    property int bottomLeftY: 300

    Text {
        id: hintText

        anchors {
            bottom: customQuadMaskedImage.top
            bottomMargin: 20
            horizontalCenter: parent.horizontalCenter
        }

        text: qsTr("Click to change the image")
    }

    CustomQuadMaskedImage {
        id: customQuadMaskedImage

        width: 300
        height: 300
        anchors.centerIn: parent

        source: sourseImage
        topLeft: Qt.point(topLeftX, topLeftY)
        topRight: Qt.point(topRightX, topRightY)
        bottomRight: Qt.point(bottomRightX, bottomRightY)
        bottomLeft: Qt.point(bottomLeftX, bottomLeftY)
    }

    Image {
        id: sourseImage

        visible: false
        source: images[0]
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            currentImageIndex++
            if (currentImageIndex >= images.length) {
                currentImageIndex = 0
            }
            sourseImage.source = images[currentImageIndex]
        }
    }

    SequentialAnimation on topLeftX {
        loops: Animation.Infinite

        NumberAnimation { duration: 2000; from: 0; to: 100; }
        NumberAnimation { duration: 2000; from: 100;to: 0; }
    }

    SequentialAnimation on topLeftY {
        loops: Animation.Infinite

        NumberAnimation { duration: 1000; from: 0; to: 50; }
        NumberAnimation { duration: 1000; from: 50; to: 0; }
    }

    SequentialAnimation on topRightX {
        loops: Animation.Infinite

        NumberAnimation { duration: 1000; from: 250; to: 300; }
        NumberAnimation { duration: 2000; from: 300; to: 250; }
    }
    SequentialAnimation on topRightY {
        loops: Animation.Infinite

        NumberAnimation { duration: 1000; from: 50; to: 0; }
        NumberAnimation { duration: 2000; from: 0; to: 50; }
    }

    SequentialAnimation on bottomRightX {
        loops: Animation.Infinite

        PauseAnimation { duration: 2000; }
        NumberAnimation { duration: 2000; from: 300; to: 250; }
        PauseAnimation { duration: 2000; }
        NumberAnimation { duration: 2000; from: 250; to: 300; }
    }
    SequentialAnimation on bottomRightY {
        loops: Animation.Infinite

        NumberAnimation { duration: 2000; from: 300; to: 250; }
        PauseAnimation { duration: 2000; }
        NumberAnimation { duration: 2000; from: 250; to: 300; }
        PauseAnimation { duration: 2000; }
    }

    SequentialAnimation on bottomLeftX {
        loops: Animation.Infinite

        NumberAnimation { duration: 1000; from: 0; to: 50; }
        NumberAnimation { duration: 1000; from: 50; to: 0; }
        PauseAnimation { duration: 2000; }
    }
    SequentialAnimation on bottomLeftY {
        loops: Animation.Infinite

        PauseAnimation { duration: 2000 }
        NumberAnimation { duration: 1000; from: 300; to: 250; }
        NumberAnimation { duration: 1000; from: 250; to: 300; }
    }
}
