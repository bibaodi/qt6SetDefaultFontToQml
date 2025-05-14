#include "languagemanager.h"
#include <QGuiApplication>
#include <QLocale>
#include <QQmlApplicationEngine>
#include <QTranslator>

LanguageManager::LanguageManager(QQmlApplicationEngine *engine, QObject *parent) : QObject(parent), m_engine(engine) {}

void LanguageManager::changeLanguage(const QString &locale, const QString &translationFile) {
  // Set the new locale
  QLocale regionlocal = QLocale(locale);
  QLocale::setDefault(regionlocal);
  qDebug() << "local Name=" << regionlocal.name() << ", translationFile=" << translationFile;

  QString translationFpath = ":i18n/i18n/" + translationFile;
  // Load the new translation file
  QTranslator translator;
  if (false == translator.load(translationFpath)) {
    qDebug() << "local file Err: Name=" << translationFpath;
  } else {
    qDebug() << "translator:" << translator.language();
    bool ret = qApp->installTranslator(&translator);
    qDebug() << "installTranslator=" << ret;
  }
  m_engine->setUiLanguage(locale); // this will fix text in loader not translated(tks tang junchong).--eton@250513
  m_engine->retranslate();         // if not found the new ts file, apply to default.--eton@250327

  // Emit a signal to update the QML UI
  // emit languageChanged(locale, translationFile);
}
