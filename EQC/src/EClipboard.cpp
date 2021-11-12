#include "EClipboard.h"

#include <QApplication>
#include <QClipboard>
#include <QMimeData>


struct HClipboardPrivate
{
    QClipboard *clipboard = nullptr;
};

EClipboard::EClipboard(QObject *parent)
    : QObject(parent)
    , d(new HClipboardPrivate)
{
    d->clipboard = qApp->clipboard();
}

EClipboard::~EClipboard()
{
    if (d) {
        delete d;
        d = nullptr;
    }
}

void EClipboard::setHtml(const QString &html)
{
    QMimeData *mimeData = new QMimeData();
    const QMimeData* oldMimeData = d->clipboard->mimeData();
    const auto formats = oldMimeData->formats();
    for (const auto& f : formats) {
        mimeData->setData(f, oldMimeData->data(f));
    }
    mimeData->setHtml(html);
    d->clipboard->setMimeData(mimeData);
}

bool EClipboard::hasHtml() const
{
    return d->clipboard->mimeData()->hasHtml();
}

QString EClipboard::html() const
{
    return d->clipboard->mimeData()->html();
}
