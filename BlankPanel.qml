import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0


//import Peruse 2.2 as Peruse

Page {
    id: root
    objectName: "BlankPanel"


    property bool  expanded: true
    property Popup settingsPopup: null

    header: RowLayout {
        spacing:  1
    }

    Label {
        text: root.title
        font.bold: true

        Layout.leftMargin: 16
    }

   Item {

       Layout.fillWidth: true
   }

   ToolButton{
       objectName: root.objectName + "SettingsToolButton"
       text: "\uf013"
       visible: true
       font.family: "FontAwesome"
       focusPolicy: Qt.NoFocus

       Layout.preferredWidth: 16

       onClicked: settingsPopup.open()

   }



   ToolButton
   {
       x: 342
       y: 6
       text: "\uf146"
       objectName: root.objectName + "HideShowToolButton"

       Layout.leftMargin: -7
       Layout.preferredWidth: 15

       onClicked: expanded = !expanded
   }

  }
