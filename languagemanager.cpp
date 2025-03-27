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
  qDebug() << "local Name=" << regionlocal.name();

  // Load the new translation file
  QTranslator translator;
  if (false == translator.load(translationFile)) {
    qDebug() << "local file Err: Name=" << translationFile;
  } else {
    qDebug() << "translator:" << translator.language();
    bool ret = qApp->installTranslator(&translator);
    qDebug() << "installTranslator=" << ret;
    m_engine->retranslate();
  }

  // Emit a signal to update the QML UI
  // emit languageChanged(locale, translationFile);
}
