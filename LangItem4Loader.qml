import QtQuick

Item {
id: id_redSquare
property  int var001: -1
Rectangle {
             id:id_rect23
             y:400
             color: "red";
             width: 300;
             height: 100;
             z:1
             Text {
                          text:  id_redSquare.var001 >0 ?qsTr("HelloLoader"):qsTr("HelloLoaderValue")
                          font.pointSize: 25
                          anchors.horizontalCenter: parent.horizontalCenter
             }
}
Component.onCompleted: {
             console.log("Dynamic Component Locale:", Qt.locale().name, Qt.locale().uiLanguages)
}
}
