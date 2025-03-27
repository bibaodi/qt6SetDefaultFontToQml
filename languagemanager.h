#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

// #include <QQmlContext>
// #include <QTranslator>

#include <QObject>

class QQmlApplicationEngine;
class LanguageManager : public QObject {
  Q_OBJECT
public:
  LanguageManager(QQmlApplicationEngine *engine, QObject *parent = nullptr);

public slots:
  Q_INVOKABLE void changeLanguage(const QString &locale, const QString &translationFile);

signals:
  void languageChanged(const QString, const QString);

private:
  QQmlApplicationEngine *m_engine;
};

#endif // LANGUAGEMANAGER_H
