#include "EImageUtils.h"
#include <future>
#include <QDebug>

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

QImage EImageUtils::mergeImage(const QString &imagePath)
{
    if (d->m_fWorkThread.valid()) {
        while (d->m_fWorkThread.wait_for(std::chrono::milliseconds(0))
               != std::future_status::ready) {
            qWarning() << "thread try connect is running";
            return QImage();
        }
    }

    return QImage();
}
