#pragma once
#ifndef EASYNCIMAGEPROVIDER_H_6EF395B5_9513_4B7E_9058_8041A3ABAAB1
#define EASYNCIMAGEPROVIDER_H_6EF395B5_9513_4B7E_9058_8041A3ABAAB1

#include <QQuickAsyncImageProvider>
#include <QRunnable>
#include <QQmlEngineExtensionPlugin>

class QThreadPool;
struct EAsyncImageResponsePrivate;
class EAsyncImageResponse : public QQuickImageResponse
{
    Q_OBJECT
public:
    EAsyncImageResponse(const QString &id,
                        const QSize &requestedSize,
                        QThreadPool *pool);
    ~EAsyncImageResponse();

    void handleDone(QImage image);

    QQuickTextureFactory *textureFactory() const override;

private:
    EAsyncImageResponsePrivate *d = nullptr;
};


struct EAsyncImageResponseRunnablePrivate;
class EAsyncImageResponseRunnable : public QObject, public QRunnable
{
    Q_OBJECT

signals:
    void done(QImage image);

public:
    EAsyncImageResponseRunnable(const QString &id, const QSize &requestedSize);
    ~EAsyncImageResponseRunnable();

    void run() override;

private:
    EAsyncImageResponseRunnablePrivate *d = nullptr;
};

struct EAsyncImageProviderPrivate;
class EAsyncImageProvider : public QQuickAsyncImageProvider
{
public:
    explicit EAsyncImageProvider();
    virtual ~EAsyncImageProvider();

    QQuickImageResponse *requestImageResponse(
            const QString &id, const QSize &requestedSize) override;

private:
    EAsyncImageProviderPrivate *d = nullptr;
};

class EImageProviderExtensionPlugin : public QQmlEngineExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)
public:
    void initializeEngine(QQmlEngine *engine, const char *uri) ;
};

#endif // EASYNCIMAGEPROVIDER_H_6EF395B5_9513_4B7E_9058_8041A3ABAAB1
