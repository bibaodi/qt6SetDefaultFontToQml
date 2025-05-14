// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
import QtQuick
import QtQuick.Window
import QtQuick.Controls

Rectangle {
    visible: true
    width: 200
    height: 100
    property  int var001: 0
    id: id_i18nRoot

    Column {
        anchors.fill: parent
        spacing: 20

        Text {
            text: "If a translation is available for the system language (eg. French) then the "
                  + "string below will be translated (eg. 'Bonjour'). Otherwise it will show 'Hello'."
            width: parent.width
            wrapMode: Text.WordWrap
        }

        Text {
            text: qsTr("Hello")
            font.pointSize: 25
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            text: qsTr("English")
            onClicked: {
                languageManager.changeLanguage("en_US", "qml_en_AU.qm")
                id_loader.source="LangItem4Loader.qml"
            }
        }

        Button {
            //% "text-ID-based for id-French"
            text: id_i18nRoot.var001 >0 ?qsTr("id-French"):qsTr("id2-French")
            onClicked: {
                //languageManager.changeLanguage("fr_FR", "qml_fr.qm")
                id_loader.source=""
                id_i18nRoot.var001=3
            }
        }
        Button {
            text: qsTr("yuyan")
            onClicked: {
                languageManager.changeLanguage("zh_CN", "qml_zh.qm")
                console.log("after click Locale:", Qt.locale().name)
                id_loader.source="LangItem4Loader.qml"
                id_i18nRoot.var001=0
            }
        }
    }
    Loader{
        id: id_loader
        source: ""
        // This signal is emitted when the component starts loading
        Component.onCompleted: {
            console.log("Loader Component.onCompleted:Dynamic component loading started.")
        }

        // This signal is emitted when the component has been fully loaded
        onLoaded: {
            console.log("Loader onLoaded:Dynamic component loaded successfully.")
        }
        onStatusChanged: {
            if (id_loader.status === Loader.Error) {
                console.error("Loader-status:", id_loader.status, "::",id_loader.errorString)
            }
            console.error("Loader-status:", id_loader.status, "::",Qt.locale().name)
        }
    }
}
