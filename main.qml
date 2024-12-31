import QtQuick
import CustomItems 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello Font World")

    Text {
        id: id_text01
        text: qsTr("da jia hao")
    }
    // Load the custom font
    FontLoader {
        id: customFont
        source: "file:///usr/local/share/fonts/SourceHanSansCN-Medium.otf"
    }

    // Set the default font for the application
    Component.onCompleted: {
        console.debug("fontFamily:", customFont.name)
    }
    //Column {
    Item {
        y: 100
        width: parent.width
        height: parent.height
        Text {
            text: qsTr("Hello, World!-default思源")
            font.pointSize: 34
        }
        Text {
            text: qsTr("Hello, World!-Load   思源")
            font.family: customFont.name
            font.pointSize: 34
        }
    }

    HtmlDocumentItem {
        y: 300
        width: 400
        height: 300
        html: "<p>
<span style=\"font-size: 14px;\">Frame:</span>
<span style=\"font-size: 30px;\">45678</span>
</p>
<p>
<span style=\"font-size: 14px;\">Pullback:</span>
<span style=\"font-size: 30px;\">99234</span>mm
</p>
"
    }
}
