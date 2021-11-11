#pragma once
#ifndef ECLIPBOARD_H_3863F9F2_F39E_4357_AEE7_BE54509B7FEE
#define ECLIPBOARD_H_3863F9F2_F39E_4357_AEE7_BE54509B7FEE

#include <QObject>

struct HClipboardPrivate;
class EClipboard : public QObject
{
    Q_OBJECT
public:
    explicit EClipboard(QObject *parent = nullptr);
    ~EClipboard();

signals:
    void errorMessage(const QString& message);

public slots:
    void setHtml(const QString& html);

private:
    HClipboardPrivate *d = nullptr;
};

#endif // ECLIPBOARD_H_3863F9F2_F39E_4357_AEE7_BE54509B7FEE
