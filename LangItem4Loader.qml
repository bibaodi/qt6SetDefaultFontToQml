import QtQuick

Item {
         id: redSquare
         Rectangle {
             y:400
             color: "red";
             width: 300;
             height: 100;
             z:1
             Text {
                 text: qsTr("HelloLoader")
                 font.pointSize: 25
                 anchors.horizontalCenter: parent.horizontalCenter
             }
         }
         Component.onCompleted: {
             console.log("Dynamic Component Locale:", Qt.locale().name, Qt.locale().uiLanguages)
         }
     }
