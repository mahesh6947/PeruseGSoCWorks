import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 640
    title: qsTr("Create Mode")

    SwipeView {
        id : swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        header: ToolBar {
                RowLayout {
                    anchors.fill: parent
                    ToolButton {
                        text: qsTr("‹")
                        onClicked: stack.pop()
                    }
                    Label {
                        text: "Title"
                        elide: Label.ElideRight
                        horizontalAlignment: Qt.AlignHCenter
                        verticalAlignment: Qt.AlignVCenter
                        Layout.fillWidth: true
                    }
                    ToolButton {
                        text: qsTr("⋮")
                        onClicked: menu.open()
                    }
                }
            }


        }





    }






