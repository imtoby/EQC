#include "EAsyncImageProvider.h"
#include "EMacros.h"

#include <QDebug>
#include <QImage>
#include <QThreadPool>
#include <QQmlEngineExtensionPlugin>

struct EAsyncImageProviderPrivate
{
    QThreadPool pool;
};

EAsyncImageProvider::EAsyncImageProvider()
    : QQuickAsyncImageProvider()
    , d(new  EAsyncImageProviderPrivate())
{
}

EAsyncImageProvider::~EAsyncImageProvider()
{
    freePointer(d);
}

QQuickImageResponse *EAsyncImageProvider::requestImageResponse(
        const QString &id, const QSize &requestedSize)
{
    EAsyncImageResponse *response = new EAsyncImageResponse(
                id, requestedSize, &d->pool);
    return response;
}

struct EAsyncImageResponseRunnablePrivate
{
    EAsyncImageResponseRunnablePrivate(const QString &id,
                                       const QSize &requestedSize)
        : m_id(id), m_requestedSize(requestedSize) {}

    QString m_id;
    QSize m_requestedSize;
};

EAsyncImageResponseRunnable::EAsyncImageResponseRunnable(const QString &id, const QSize &requestedSize)
    : d(new EAsyncImageResponseRunnablePrivate(id, requestedSize))
{
}

EAsyncImageResponseRunnable::~EAsyncImageResponseRunnable()
{
    freePointer(d);
}

void EAsyncImageResponseRunnable::run()
{
    auto image = QImage(50, 50, QImage::Format_RGB32);
    if (d->m_id == QLatin1String("slow")) {
        qDebug() << "Slow, red, sleeping for 5 seconds";
        QThread::sleep(5);
        image.fill(Qt::red);
    } else {
        qDebug() << "Fast, blue, sleeping for 1 second";
        QThread::sleep(1);
        image.fill(Qt::blue);
    }
    if (d->m_requestedSize.isValid()) {
        image = image.scaled(d->m_requestedSize);
    }

    emit done(image);
}

struct EAsyncImageResponsePrivate
{
    QImage m_image;
};

EAsyncImageResponse::EAsyncImageResponse(const QString &id,
                                         const QSize &requestedSize,
                                         QThreadPool *pool)
    : QQuickImageResponse()
    , d (new EAsyncImageResponsePrivate)
{
    auto runnable = new EAsyncImageResponseRunnable(id, requestedSize);
    connect(runnable, &EAsyncImageResponseRunnable::done,
            this, &EAsyncImageResponse::handleDone);
    pool->start(runnable);
}

EAsyncImageResponse::~EAsyncImageResponse()
{
    freePointer(d);
}

void EAsyncImageResponse::handleDone(QImage image)
{
    d->m_image = image;
    emit finished();
}

QQuickTextureFactory *EAsyncImageResponse::textureFactory() const
{
    return QQuickTextureFactory::textureFactoryForImage(d->m_image);
}

void EImageProviderExtensionPlugin::initializeEngine(QQmlEngine *engine,
                                                     const char *uri)
{
    Q_UNUSED(uri);
    engine->addImageProvider("async", new EAsyncImageProvider);
    qDebug() << "add image provider \"async\" finished.";
}
