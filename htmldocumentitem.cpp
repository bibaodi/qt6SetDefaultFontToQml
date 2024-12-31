#include "htmldocumentitem.h"

HtmlDocumentItem::HtmlDocumentItem(QQuickItem *parent) : QQuickPaintedItem(parent) { setFlag(ItemHasContents, true); }

void HtmlDocumentItem::paint(QPainter *painter) {
  QTextDocument document;
  document.setHtml(m_html);
  // document.setTextWidth(width());

  painter->save();
  // painter->translate(0, 0);
  document.drawContents(painter);
  painter->restore();
}
