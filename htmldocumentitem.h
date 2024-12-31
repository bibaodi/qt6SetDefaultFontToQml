#ifndef HTMLDOCUMENTITEM_H
#define HTMLDOCUMENTITEM_H
#include <QPainter>
#include <QQuickPaintedItem>
#include <QTextCursor>
#include <QTextDocument>
#include <qqml.h>

class HtmlDocumentItem : public QQuickPaintedItem {
  Q_OBJECT
  Q_PROPERTY(QString html READ html WRITE setHtml NOTIFY htmlChanged)

public:
  HtmlDocumentItem(QQuickItem *parent = nullptr);

  QString html() const { return m_html; }

  void setHtml(const QString &html) {
    if (m_html != html) {
      m_html = html;
      emit htmlChanged();
    }
  }

signals:
  void htmlChanged();

protected:
  void paint(QPainter *painter) override;

private:
  QString m_html;
};

#endif // HTMLDOCUMENTITEM_H
