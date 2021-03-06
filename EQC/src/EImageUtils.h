#pragma once
#ifndef EIMAGEUTILS_H_D4BD9295_BF01_4835_84F7_DAC770A3C6DC
#define EIMAGEUTILS_H_D4BD9295_BF01_4835_84F7_DAC770A3C6DC

#include <QObject>
#include <QImage>

#include "ESingleton.h"

struct EImageUtilsPrivate;

class EImageUtils : public QObject
{
    Q_OBJECT
public:
    explicit EImageUtils(QObject *parent = nullptr);
    ~EImageUtils();

    Q_INVOKABLE bool mergeImages(
            const QString& imagesDir,
            Qt::Orientation mergeOrientation = Qt::Horizontal,
            const QStringList& imagesFilters = {"*.png"});

    Q_INVOKABLE static QString imageFileRealSuffix(const QString& filename);
    Q_INVOKABLE static QString imageFileRenameByRealSuffix(const QString& filename);
    Q_INVOKABLE static bool mimeTypeIsImage(const QString& filename);

    Q_INVOKABLE static QSize imageSize(const QString& filename);

    Q_INVOKABLE static bool isSupportedImage(const QString& filename);
    Q_INVOKABLE static bool isImageUrl(const QString& url);
    Q_INVOKABLE static bool isStartWithHttpsOrHttp(const QString& url);
    Q_INVOKABLE static QString supportedImageFormatJoin(const QString& join = " ");

    Q_INVOKABLE static QByteArray imageToBase64(const QString& filename,
                                                const QString& format = "jpg");
    Q_INVOKABLE static QImage base64ToImage(const QString& base64);

    Q_INVOKABLE static const char* defaultSaveImageFormat();

    Q_INVOKABLE static QString saveImage(const QImage& image,
                                         const QString& filename,
                                         const QString& format = "png");

signals:
    void errorMessage(const QString& msg);

private:
    EImageUtilsPrivate *d = nullptr;
};

#define EIMAGEUTILS ESingleton<EImageUtils>::instance()

#endif // EIMAGEUTILS_H_D4BD9295_BF01_4835_84F7_DAC770A3C6DC
