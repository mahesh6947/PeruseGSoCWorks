import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.2
import QtQuick.Window 2.0



ToolBar {
    id: tool
    objectName: "toolbar"

    property Project  project
    property ImageCanvas canvas
    property Popup canvasSizePopup
    property Popup imageSizePopup

    property  alias toolButtonGroup: toolButtonGroup

    Connections {
        target: canvas
        onToolChanged: {
            if (root.ignoreToolChanges)
                return;

            switch (canvas.tool) {
            case TileCanvas.PenTool:
                toolButtonGroup.checkedButton = penToolButton;
                break;

            case TileCanvas.EraserTool:
                toolButtonGroup.checkedButton = eraserToolButton;
                break;


            case TileCanvas.SelectionTool:
                toolButtonGroup.checkedButton = selectionToolButton;
                break;
            case TileCanvas.CropTool:
                toolButtonGroup.checkedButton = cropToolButton;
                break;
            }
        }
    }



    Row {
        id: toolbarRow
        enabled: canvas
        anchors.fill: parent

        ToolButton{
            id: canvasSizeButton
            objectName: "canvasSizeButton"
            enabled: project && project.loaded

           onClicked: canvasSizePopup.open()

        }



        ToolButton {
            id: imageSizebutton
            objectName:  "ImageSizeButton"
        onClicked: imageSizePopup.open()
        }
    }

    Row {
        spacing:  5

        IconToolButton {
            objectName:  "undobutton"
            text: "\uf0e2"

          onClicked: project.undoStack.undo()


        }
        IconToolButton {
            objectName:  "redobutton"
            text: "\uf01e"

            onClicked: project.undoStack.redo()


        }
    }


        Row {
            id: toolLayout
            spacing: 5

            IconToolButton {
                id: penToolButton
                objectName: "penToolButton"
                text: "\uf040"
                checked: true


                onClicked: switchTool(ImageCanvas.PenTool)
            }


            IconToolButton {
                id: eraserToolButton
                objectName: "eraserToolButton"
                text: "\uf12d"
                checkable: true




                onClicked: switchTool(ImageCanvas.EraserTool)
            }



            ToolButton {
                id: selectionToolButton
                text: "Select"
                spacing: -4
                objectName: "selectionToolButton"
                checkable: true
                hoverEnabled: true
                focusPolicy: Qt.NoFocus
                visible: projectType === Project.ImageType || projectType === Project.LayeredImageType




                onClicked: switchTool(ImageCanvas.SelectionTool)
            }

            IconToolButton {
                id: cropToolButton
                objectName: "cropToolButton"
                text: "\uf125"
                checkable: true

                visible: true



                onClicked: switchTool(ImageCanvas.CropTool)
            }


        }






    }




