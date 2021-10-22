#pragma once
#ifndef EIMAGEUTILS_H_D4BD9295_BF01_4835_84F7_DAC770A3C6DC
#define EIMAGEUTILS_H_D4BD9295_BF01_4835_84F7_DAC770A3C6DC

#include <QObject>
#include <QImage>

struct EImageUtilsPrivate;

class EImageUtils : public QObject
{
    Q_OBJECT
public:
    explicit EImageUtils(QObject *parent = nullptr);
    ~EImageUtils();

    QImage mergeImages(const QString& imagesDir,
                       const QStringList& imagesFilters = {"*.png"});

signals:

private:
    EImageUtilsPrivate *d= nullptr;
};

#endif // EIMAGEUTILS_H_D4BD9295_BF01_4835_84F7_DAC770A3C6DC
