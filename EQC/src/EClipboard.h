#pragma once
#ifndef ECLIPBOARD_H_3863F9F2_F39E_4357_AEE7_BE54509B7FEE
#define ECLIPBOARD_H_3863F9F2_F39E_4357_AEE7_BE54509B7FEE

#include <QObject>
#include <QUrl>
#include <QImage>

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
    bool hasHtml() const;
    QString html() const;

    void setText(const QString& text);
    bool hasText() const;
    QString text() const;

    void setImage(const QImage& image);
    void setImageFromPath(const QString& imagePath);
    bool hasImage() const;
    QImage image() const;

    void setFile(const QString& fileName);
    void setUrls(const QList<QUrl> &urls);
    bool hasUrls() const;
    QList<QUrl> urls() const;

    QString saveClipboardImage(const QString& filename);
    QString saveImage(const QImage& image, const QString& filename);

private:
    HClipboardPrivate *d = nullptr;
};

#endif // ECLIPBOARD_H_3863F9F2_F39E_4357_AEE7_BE54509B7FEE
