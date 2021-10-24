#include "EImageUtils.h"
#include <future>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QList>
#include <QSize>
#include <QImageReader>
#include <QPainter>
#include <QImage>

struct EImageUtilsPrivate
{
    std::future<bool> m_fWorkThread;
};

EImageUtils::EImageUtils(QObject *parent) : QObject(parent)
{

}

EImageUtils::~EImageUtils()
{
    if (d->m_fWorkThread.valid()) {
        d->m_fWorkThread.get();
    }
}

bool EImageUtils::mergeImages(const QString &imagesDir,
                                Qt::Orientation mergeOrientation,
                                const QStringList& imagesFilters)
{
    if (d->m_fWorkThread.valid()) {
        while (d->m_fWorkThread.wait_for(std::chrono::milliseconds(0))
               != std::future_status::ready) {
            qWarning() << "thread merge images is running";
            return false;
        }
    }

    d->m_fWorkThread = std::async(std::launch::async, [&]() -> bool {
        QDir dir(imagesDir);
        QFileInfoList fileInfoList = dir.entryInfoList(
                    imagesFilters,
                    QDir::Files|QDir::NoDotAndDotDot,
                    QDir::Name);

        int currentWidth = 0; // for Qt::VHorizontal
        int currentHeight = 0; // for Qt::Vertical

        int maxWidth = 0; // for Qt::Vertical
        int maxHeight = 0; // for Qt::VHorizontal

        QList<QSize> imageSizeList;
        QSize imageSize;
        if (Qt::Horizontal == mergeOrientation) {
            for (const auto& fileInfo : fileInfoList) {
                QImageReader imageReader(fileInfo.absoluteFilePath());
                imageSize = imageReader.size();
                imageSizeList.append(imageSize);
                if (imageSize.height() > maxHeight) {
                    maxHeight = imageSize.height();
                }
            }

            for (auto imageSize : imageSizeList) {
                currentWidth += static_cast<int>(
                            (maxHeight * 1.0 / imageSize.height())
                            * imageSize.width());
            }
            currentHeight = maxHeight;
        } else {
            for (const auto& fileInfo : fileInfoList) {
                QImageReader imageReader(fileInfo.absoluteFilePath());
                imageSize = imageReader.size();
                imageSizeList.append(imageSize);
                if (imageSize.width() > maxWidth) {
                    maxWidth = imageSize.width();
                }
            }

            for (auto imageSize : imageSizeList) {
                currentHeight += static_cast<int>(
                            (maxWidth * 1.0 / imageSize.width())
                            * imageSize.height());
            }
            currentWidth = maxWidth;
        }

        QImage resultFillImage(currentWidth, currentHeight,
                               QImage::Format_RGB32);
        resultFillImage.fill(Qt::white);

        QPainter painter;
        painter.begin(&resultFillImage);

        int pos = 0;

        if (Qt::Horizontal == mergeOrientation) {
            for (const auto& fileInfo : fileInfoList) {
                QImage image(fileInfo.absoluteFilePath());
                image = image.scaledToHeight(maxHeight);
                painter.drawImage(pos, 0, image);
                pos += image.width();
            }
        } else {
            for (const auto& fileInfo : fileInfoList) {
                QImage image(fileInfo.absoluteFilePath());
                image = image.scaledToWidth(maxWidth);
                painter.drawImage(pos, 0, image);
                pos += image.height();
            }
        }

        painter.end();

        QString name = (imagesDir.endsWith("/") ? imagesDir : imagesDir + "/")
                + "EImageUtils_Merged.png";
        return resultFillImage.save(name, "png");
    });

    return false;
}
