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
  static QTranslator translator; // make translator keep in memory will fix text in loader not translated(tks tang
                                 // junchong).--eton@250513
  if (false == translator.load(translationFpath)) {
    qDebug() << "local file Err: Name=" << translationFpath;
  } else {
    qDebug() << "translator:" << translator.language();
    bool ret = qApp->installTranslator(&translator);
#if 0
    m_engine->setUiLanguage(locale);
    // this will fix text in loader not translated(tks tang junchong), not work.
    // if change translator to static, it works, so comment this.--eton@250513
#endif
    qDebug() << "installTranslator=" << ret << ", uilanguage=" << m_engine->uiLanguage();
  }

  m_engine->retranslate(); // if not found the new ts file, apply to default.--eton@250327

  // Emit a signal to update the QML UI
  // emit languageChanged(locale, translationFile);
}
