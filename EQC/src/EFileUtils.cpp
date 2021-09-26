#include "EFileUtils.h"
#include <QFileInfo>
#include <QDir>
#include <QFile>

EFileUtils::EFileUtils(QObject *parent) : QObject(parent)
{

}

QString EFileUtils::baseName(const QString &filename) const
{
    if (filename.isEmpty()) {
        return filename;
    }

    return QFileInfo(filename).baseName();
}

bool EFileUtils::exists(const QString &filename) const
{
    if (filename.isEmpty()) {
        return false;
    }

    return QFileInfo::exists(filename);
}

qint64 EFileUtils::fileSize(const QString &filename) const
{
    if (!this->exists(filename)) {
        return 0;
    }

    return QFileInfo(filename).size();
}

QString EFileUtils::fileName(const QString &filename) const
{
    if (filename.isEmpty()) {
        return filename;
    }

    return QFileInfo(filename).fileName();
}

QString EFileUtils::suffix(const QString &filename) const
{
    if (filename.isEmpty()) {
        return filename;
    }

    return QFileInfo(filename).suffix();
}

QString EFileUtils::dirPath(const QString &filename) const
{
    if (filename.isEmpty()) {
        return filename;
    }

    return QFileInfo(filename).absoluteDir().path();
}

bool EFileUtils::removeDir(const QString &dirPath) const
{
    if (dirPath.isEmpty()) {
        return false;
    }

    return QDir(dirPath).removeRecursively();
}

bool EFileUtils::copy(const QString &srcFilename,
                          const QString &dstFilename) const
{
    if (srcFilename.isEmpty() || dstFilename.isEmpty()) {
        return false;
    }
    return QFile(srcFilename).copy(dstFilename);
}

bool EFileUtils::rename(const QString &srcFilename,
                        const QString &dstFilename) const
{
    if (srcFilename.isEmpty() || dstFilename.isEmpty()) {
        return false;
    }
    return QFile::rename(srcFilename, dstFilename);
}

QString EFileUtils::removeSuffix(const QString &filename) const
{
    if (filename.isEmpty()) {
        return filename;
    }
    return QString("%1/%2").arg(dirPath(filename), baseName(filename));
}

bool EFileUtils::dirExists(const QString &dirPath) const
{
    if (dirPath.isEmpty()) {
        return false;
    }

    return QDir(dirPath).exists();
}

bool EFileUtils::remove(const QString &filename) const
{
    if (filename.isEmpty()) {
        return false;
    }

    return QFile::remove(filename);
}

bool EFileUtils::mkdir(const QString &dirPath) const
{
    if (dirPath.isEmpty()) {
        return false;
    }

    return QDir().mkpath(dirPath);
}

void EFileUtils::saveToFile(const QString &filename,
                            const QByteArray &data) const
{
    if (data.isEmpty()) {
        return;
    }

    if (!dirExists(dirPath(filename))) {
        mkdir(dirPath(filename));
    }

    QFile *pFile = nullptr;
    std::unique_ptr<QFile> file(new QFile(filename));
    if (file->open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        pFile = file.release();
    }

    if (pFile) {
        pFile->write(data);
        pFile->close();
    }
}
