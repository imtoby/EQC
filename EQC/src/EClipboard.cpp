#include "EClipboard.h"

#include <QApplication>
#include <QClipboard>
#include <QMimeData>
#include <QUrl>

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

void EClipboard::setText(const QString &text)
{
    d->clipboard->setText(text);
    if (d->clipboard->supportsSelection()) {
        d->clipboard->setText(text, QClipboard::Selection);
    }
    if (d->clipboard->supportsFindBuffer()) {
        d->clipboard->setText(text, QClipboard::FindBuffer);
    }
}

bool EClipboard::hasText() const
{
    return d->clipboard->mimeData()->hasText();
}

QString EClipboard::text() const
{
    return d->clipboard->text();
}

void EClipboard::setImage(const QImage &image)
{
    d->clipboard->setImage(image);
}

void EClipboard::setImageFromPath(const QString &imagePath)
{
    setImage(QImage(imagePath));
}

bool EClipboard::hasImage() const
{
    return d->clipboard->mimeData()->hasImage();
}

QImage EClipboard::image() const
{
    return d->clipboard->image();
}

void EClipboard::setFile(const QString &fileName)
{
    QMimeData *mimeData = new QMimeData();
    const QMimeData* oldMimeData = d->clipboard->mimeData();
    for (const auto& f : oldMimeData->formats()) {
        mimeData->setData(f, oldMimeData->data(f));
    }
    mimeData->setUrls({QUrl::fromLocalFile(fileName)});
    d->clipboard->setMimeData(mimeData);
}
