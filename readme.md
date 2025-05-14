# apply customer font in Qt6
- eton@241224 init the demo for font in qt;
- eton@241231 add HtmlDocumentItem for demonstrate the `QTextDocument`;
- eton@250514 try resolve text load by loader not translated error, not work.
- eton@250514 junchong suggest 'change `QTranslator translator;` to long life cycle varibale', I change it to static, it works, and the **translator is the key**.

## Contents
if the font file in system wide path, then direct set is valid, otherwise follow steps:
1. add font file(ttf/otf) to qt resources system, make it available to app;
2. `QFontDatabase::addApplicationFont(":/fonts/komika_font.ttf");` add to qt font DB; //this make font load available;

3. load font `QFont font = QFont("Komika Axis", 10, 1);`;

4. `app.setFont(font);`;

5. done;

## update translates
```
~/Qt/6.5.3/gcc_64/bin/lupdate -recursive ./ -target-language zh_CN -ts i18n/
~/Qt/6.5.3/gcc_64/bin/linguist ./i18n/qml_zh.ts
```

## Env:
- qt6.5;
- debian12;
## Results

- ![set](./result-images/Font-set-result.png)
- ![noset](./result-images/Font-noset-result.png)


## Infos
`m_engine->setUiLanguage(locale);` 有用的原因是因为这会自动安装cmake生成的qm文件。
> Applications reload translations when the QJSEngine::uiLanguage or Qt.uiLanguage property value changes. The following code snippet changes the language dynamically when the user clicks the button:
[Writing Source Code for Translation | Qt 6.8](https://doc.qt.io/qt-6.8/zh/i18n-source-translation.html#qml-use-qqmlapplicationengine "Click to open https://doc.qt.io/qt-6.8/zh/i18n-source-translation.html#qml-use-qqmlapplicationengine")

## Refs:
ref:[Embedding Fonts in Your Qt Application](https://amin-ahmadi.com/2016/01/07/embedding-fonts-in-your-qt-app/)
