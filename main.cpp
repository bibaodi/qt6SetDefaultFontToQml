#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#else
#endif
#include "htmldocumentitem.h"

#include "languagemanager.h"
#include <QFont>
#include <QLocale>
#include <QQmlContext>
#include <QTranslator>

int main(int argc, char *argv[]) {
  QLocale::setDefault(QLocale(QLocale::Chinese, QLocale::China));

  QGuiApplication app(argc, argv);
  qmlRegisterType<HtmlDocumentItem>("CustomItems", 1, 0, "HtmlDocumentItem");
  qmlRegisterType<LanguageManager>("LanguageManager", 1, 0, "LanguageManagerItem");

  qDebug() << "default: family:" << app.font().family() << ",d:" << app.font().defaultFamily();
  const QFont font("Source Han Sans CN");
  app.setFont(font);
  if (0 == font.family().compare(QGuiApplication::font().family())) {
    qDebug() << "set font success";
  } else {
    qDebug() << "set font failed";
  }
  qDebug() << "2default family:" << app.font().family() << ",d:" << app.font().defaultFamily();
#if 0
  QTranslator translator;
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  qDebug() << "uiLanguages=" << uiLanguages;
  const QStringList transfiles{"qml_zh.qm", "qml_fr.qm", "qml_en_AU.qm"};
  for (const QString &itf : transfiles) {
    QString translationFpath = ":i18n/i18n/" + itf;
    if (translator.load(translationFpath)) {
      bool ret = app.installTranslator(&translator);
      qDebug() << translator.language() << "::installTranslator=" << ret;
    }
  }
#endif
  QQmlApplicationEngine engine;
  LanguageManager languageManager(&engine);
  engine.rootContext()->setContextProperty("languageManager", &languageManager);
  const QUrl url(QStringLiteral("qrc:/qt6-i18n-demo/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
