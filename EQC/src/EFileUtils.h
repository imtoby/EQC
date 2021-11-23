#pragma once
#ifndef EFILEUTILS_H_D4517E57_1FD8_44E1_8824_485D60AC6877
#define EFILEUTILS_H_D4517E57_1FD8_44E1_8824_485D60AC6877

#include <QObject>

namespace EFileUtils
{
    Q_INVOKABLE QString baseName(const QString &filename);
    Q_INVOKABLE bool exists(const QString &filename);
    Q_INVOKABLE qint64 fileSize(const QString &filename);
    Q_INVOKABLE QString fileName(const QString &filename);
    Q_INVOKABLE QString suffix(const QString &filename);
    Q_INVOKABLE QString dirPath(const QString &filename);

    Q_INVOKABLE bool removeDir(const QString &dirPath);
    Q_INVOKABLE bool copy(const QString &srcFilename,
                          const QString &dstFilename);
    Q_INVOKABLE bool rename(const QString &srcFilename,
                            const QString &dstFilename);

    Q_INVOKABLE QString removeSuffix(const QString &filename);
    Q_INVOKABLE bool dirExists(const QString &dirPath);
    Q_INVOKABLE bool remove(const QString &filename);
    Q_INVOKABLE bool mkdir(const QString &dirPath);
    Q_INVOKABLE bool dirIsEmpty(const QString &dirPath);
    Q_INVOKABLE bool checkDirHasFileBySuffix(const QString &dirPath,
                                             const QString &suffix);

    Q_INVOKABLE void saveToFile(const QString &filename,
                                 const QByteArray &data);

    Q_INVOKABLE QString urlToLocalFile(const QString &fileUrl);
    Q_INVOKABLE QString filenameToUrl(const QString &filename);

    Q_INVOKABLE QString format(const QString & filename);
    Q_INVOKABLE QString mimeType(const QString & filename);
    Q_INVOKABLE QString suffixOnlyByFileName(const QString & filename);

    Q_INVOKABLE bool mimeTypeIsVideo(const QString & filename);
};

#endif // EFILEUTILS_H_D4517E57_1FD8_44E1_8824_485D60AC6877
