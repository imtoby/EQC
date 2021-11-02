#pragma once
#ifndef EIMAGEUTILS_H_D4BD9295_BF01_4835_84F7_DAC770A3C6DC
#define EIMAGEUTILS_H_D4BD9295_BF01_4835_84F7_DAC770A3C6DC

#include <QObject>
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

    Q_INVOKABLE static QString imageFileRealSuffix(const QString & filename);
    Q_INVOKABLE static QString imageFileRenameByRealSuffix(const QString & filename);
    Q_INVOKABLE static bool mimeTypeIsImage(const QString & filename);

signals:

private:
    EImageUtilsPrivate *d = nullptr;
};

#define EIMAGEUTILS ESingleton<EImageUtils>::instance()

#endif // EIMAGEUTILS_H_D4BD9295_BF01_4835_84F7_DAC770A3C6DC
