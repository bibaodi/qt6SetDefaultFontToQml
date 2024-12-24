#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#else
#endif

#include <QFont>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);
  qDebug() << "default: family:" << app.font().family() << ",d:" << app.font().defaultFamily();
  QFont font("Source Han Sans CN");
  app.setFont(font);
  qDebug() << "2default family:" << app.font().family() << ",d:" << app.font().defaultFamily();

  QTranslator translator;
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  for (const QString &locale : uiLanguages) {
    const QString baseName = "qt6-i18n-demo_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + baseName)) {
      app.installTranslator(&translator);
      break;
    }
  }

  QQmlApplicationEngine engine;
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
