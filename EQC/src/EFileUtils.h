#pragma once
#ifndef EFILEUTILS_H_D4517E57_1FD8_44E1_8824_485D60AC6877
#define EFILEUTILS_H_D4517E57_1FD8_44E1_8824_485D60AC6877

#include <QObject>

class EFileUtils : public QObject
{
    Q_OBJECT
public:
    explicit EFileUtils(QObject *parent = nullptr);

    Q_INVOKABLE QString baseName(const QString &filename) const;
    Q_INVOKABLE bool exists(const QString &filename) const;
    Q_INVOKABLE qint64 fileSize(const QString &filename) const;
    Q_INVOKABLE QString fileName(const QString &filename) const;
    Q_INVOKABLE QString suffix(const QString &filename) const;
    Q_INVOKABLE QString dirPath(const QString &filename) const;

    Q_INVOKABLE bool removeDir(const QString &dirPath) const;
    Q_INVOKABLE bool copy(const QString &srcFilename,
                          const QString &dstFilename) const;
    Q_INVOKABLE bool rename(const QString &srcFilename,
                            const QString &dstFilename) const;

    Q_INVOKABLE QString removeSuffix(const QString &filename) const;
    Q_INVOKABLE bool dirExists(const QString &dirPath) const;
    Q_INVOKABLE bool remove(const QString &filename) const;
    Q_INVOKABLE bool mkdir(const QString &dirPath) const;

    Q_INVOKABLE void saveToFile(const QString &filename,
                                 const QByteArray &data) const;

};

#endif // EFILEUTILS_H_D4517E57_1FD8_44E1_8824_485D60AC6877
