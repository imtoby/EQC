#include "EImageProvider.h"
#include <QCoreApplication>
#include <QImage>

static const char DEFAULT_LOAD_IMAGE_FORMAT[] = "png";

QImage EImageProvider::requestImage(const QString &id, QSize *size,
                                    const QSize &requestedSize)
{
    const static QString ProviderImagePath
            = QCoreApplication::applicationDirPath() + "/images/";
    QImage image;
    bool loaded = image.load(ProviderImagePath + id, DEFAULT_LOAD_IMAGE_FORMAT);
    if (loaded && !image.isNull()) {
        if (requestedSize.width() > 0 && requestedSize.height() > 0) {
            image = image.scaled(requestedSize, Qt::KeepAspectRatio,
                                 Qt::SmoothTransformation);
        }
        if (size) {
            *size = image.size();
        }
    }
    return image;
}
