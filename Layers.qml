

import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.2
import QtQuick.Window 2.0

BlankPanel {
    id : root
    title: qsTr("Layers")
    padding: 1

    property LayerImagecanvas layercanvas
    property LayeredImageProject project

   ButtonGroup
   {
       objectName: "LayersPanelbuttongroup"
       buttons: listlayer.contentItem.children
   }



   contentItem: ColumnLayout
   {
       visible: root.expanded
       spacing: 1


   }

   ListView{
       id: listlayer
       orientation: ListView.Horizontal
       objectName: "LayersList"
       visible: true
       clip: true

       Layout.fillHeight: true
       Layout.fillWidth: true

       ScrollBar.horizontal: ScrollBar {
           id: horizontalScrollBar
       }

       ScrollBar.vertical: ScrollBar {
           id: verticalScrollBar
       }

      // model: LayerModel {
           //layeredImageProject: project

       //}

       delegate: ItemDelegate {
           objectName: model.layer.name
           checkable: true
           width: listlayer.width
           leftPadding: 5
           rightPadding: 5
           focusPolicy:  Qt.NoFocus

           onClicked: project.currentLayerIndex = index
           onDoubleClicked:  layernameTextFeild.forceActiveFocus()


          TextField   {
               id: layernameTextFeild
               objectName: "LayerName"
               activeFocus: false
               background.visible: false
               font.pixelSize: 12
               visible: false

           onAccepted: {
               project.setLayerName(index, text);
               layercanvas.forceActiveFocus();
           }
          }

          CheckBox {
              id: visibilitycheckbox
              objectName: "LayervisiblityCheckBox"
              x: 15
              text: model.layer.visible ? "\uf06e" : "\uf070"
              indicator: null

              onClicked: project.setLayerVisible(index, !model.layer.visible)
          }

       }


   }
   MenuSeparator{
       padding: 6
       topPadding: 1
       bottomPadding: 2

       Layout.fillWidth: true
   }

   Button{
       x: 0
       y: 0
       objectName: "NewLayer"
       text: "+"
       flat: true
       hoverEnabled: true

       Layout.maximumWidth: implicitHeight
       Layout.fillWidth: true
       Layout.fillHeight: true
       Layout.leftMargin: 0

       onClicked: project.addNewLayer()
   }
   Button {
       objectName: "moveLayerDownButton"
       text: "\uf107"

       flat: true

       hoverEnabled: true
      enabled: project && project.currentLayerIndex < project.layerCount - 1

       Layout.maximumWidth: implicitHeight
       Layout.fillWidth: true
      Layout.fillHeight: true

       onClicked: project.moveCurrentLayerDown()
   }

   Button {
       objectName: "moveLayerUpButton"
       text: "\uf106"

       flat: true

       hoverEnabled: true
       enabled: project && project.currentLayerIndex > 0

       Layout.maximumWidth: implicitHeight
       Layout.fillWidth: true
       Layout.fillHeight: true

       onClicked: project.moveCurrentLayerUp()
   }

   Item {
       Layout.fillWidth: true
       Layout.fillHeight: true
   }

   Button {
       objectName: "deleteLayerButton"
       text: "\uf1f8"

       flat: true

       enabled: project && project.currentLayer && project.layerCount > 1
       hoverEnabled: true

       Layout.maximumWidth: implicitHeight
       Layout.fillWidth: true
       Layout.fillHeight: true
       Layout.rightMargin: 6

       onClicked: project.deleteCurrentLayer()
   }


}
