#pragma once
#ifndef EIMAGEPROVIDER_H_569B2D56_25DA_4E1E_8FFC_B7CC32128300
#define EIMAGEPROVIDER_H_569B2D56_25DA_4E1E_8FFC_B7CC32128300

#include <QQuickImageProvider>

class EImageProvider : public QQuickImageProvider
{
public:
    EImageProvider() : QQuickImageProvider(QQuickImageProvider::Image) {};

    QImage requestImage(const QString &id, QSize *size,
                        const QSize &requestedSize) override;
};

#endif // EIMAGEPROVIDER_H_569B2D56_25DA_4E1E_8FFC_B7CC32128300
