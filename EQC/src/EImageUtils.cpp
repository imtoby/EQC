#include "EImageUtils.h"
#include <future>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

struct EImageUtilsPrivate
{
    std::future<void> m_fWorkThread;
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

QImage EImageUtils::mergeImages(const QString &imagesDir,
                               const QStringList& imagesFilters)
{
    if (d->m_fWorkThread.valid()) {
        while (d->m_fWorkThread.wait_for(std::chrono::milliseconds(0))
               != std::future_status::ready) {
            qWarning() << "thread merge images is running";
            return QImage();
        }
    }

    d->m_fWorkThread = std::async(std::launch::async, [&]() -> void {
        QDir dir(imagesDir);
        QFileInfoList fileInfoList = dir.entryInfoList(
                    imagesFilters, QDir::Files|QDir::NoDotAndDotDot);
    });

    return QImage();
}
