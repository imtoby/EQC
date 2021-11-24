#include "EClipboard.h"

#include <QApplication>
#include <QClipboard>
#include <QMimeData>
#include <QUrl>

#include "EFileUtils.h"
#include "EImageUtils.h"

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

void EClipboard::setUrls(const QList<QUrl> &urls)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setUrls(urls);
    d->clipboard->setMimeData(mimeData, QClipboard::Clipboard);
    d->clipboard->setMimeData(mimeData, QClipboard::Selection);
}

bool EClipboard::hasUrls() const
{
    return d->clipboard->mimeData()->hasUrls();
}

QList<QUrl> EClipboard::urls() const
{
    return d->clipboard->mimeData()->urls();
}

QString EClipboard::saveClipboardImage(const QString &filename)
{
    if (hasImage()) {
        QImage tmpImage;
        qDebug() << Q_FUNC_INFO << d->clipboard->mimeData()->formats();
        qDebug() << Q_FUNC_INFO << d->clipboard->mimeData()->urls();
        if (d->clipboard->mimeData()->formats().contains("text/uri-list")) {
            auto allUrls = d->clipboard->mimeData()->urls();
            for (const auto& everyUrl : allUrls) {
                qDebug() << Q_FUNC_INFO << "everyUrl: " << everyUrl;
                if (everyUrl.isEmpty()) {
                    continue;
                }
                qDebug() << Q_FUNC_INFO << "clipboard->mimeData()->text(): "
                         << d->clipboard->mimeData()->text();
                auto filename = everyUrl.toLocalFile();
                if (EFileUtils::exists(filename)) {
                    if (EIMAGEUTILS->mimeTypeIsImage(filename)) {
                        return filename;
                    }
                }
            }
        }
        tmpImage = image();
        if (!tmpImage.isNull()) {
            return saveImage(tmpImage, filename);
        }
    }
    return QStringLiteral("");
}

QString EClipboard::saveImage(const QImage &image, const QString &filename)
{
    return EIMAGEUTILS->saveImage(image, filename);
}
