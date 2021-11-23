#include "EFileUtils.h"
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <memory>
#include <QMimeDatabase>
#include "EFileFormatConstants.h"

Q_GLOBAL_STATIC(QMimeDatabase, MimeDatabase)

QString EFileUtils::baseName(const QString &filename)
{
    if (filename.isEmpty()) {
        return filename;
    }
    return QFileInfo(urlToLocalFile(filename)).baseName();
}

bool EFileUtils::exists(const QString &filename)
{
    if (filename.isEmpty()) {
        return false;
    }
    return QFileInfo::exists(urlToLocalFile(filename));
}

qint64 EFileUtils::fileSize(const QString &filename)
{
    if (!exists(filename)) {
        return 0;
    }

    return QFileInfo(urlToLocalFile(filename)).size();
}

QString EFileUtils::fileName(const QString &filename)
{
    if (filename.isEmpty()) {
        return filename;
    }

    return QFileInfo(urlToLocalFile(filename)).fileName();
}

QString EFileUtils::suffix(const QString &filename)
{
    if (filename.isEmpty()) {
        return filename;
    }

    return QFileInfo(urlToLocalFile(filename)).suffix();
}

QString EFileUtils::dirPath(const QString &filename)
{
    if (filename.isEmpty()) {
        return filename;
    }

    return QFileInfo(urlToLocalFile(filename)).absoluteDir().path();
}

bool EFileUtils::removeDir(const QString &dirPath)
{
    if (dirPath.isEmpty()) {
        return false;
    }

    return QDir(dirPath).removeRecursively();
}

bool EFileUtils::copy(const QString &srcFilename,
                          const QString &dstFilename)
{
    if (srcFilename.isEmpty() || dstFilename.isEmpty()) {
        return false;
    }
    return exists(srcFilename) && QFile(srcFilename).copy(dstFilename);
}

bool EFileUtils::rename(const QString &srcFilename,
                        const QString &dstFilename)
{
    if (srcFilename.isEmpty() || dstFilename.isEmpty()) {
        return false;
    }
    return exists(srcFilename) && QFile::rename(srcFilename, dstFilename);
}

QString EFileUtils::removeSuffix(const QString &filename)
{
    if (filename.isEmpty()) {
        return filename;
    }
    return QString("%1/%2").arg(dirPath(filename), baseName(filename));
}

bool EFileUtils::dirExists(const QString &dirPath)
{
    if (dirPath.isEmpty()) {
        return false;
    }

    return QDir(dirPath).exists();
}

bool EFileUtils::remove(const QString &filename)
{
    if (filename.isEmpty()) {
        return false;
    }

    return exists(filename) && QFile::remove(filename);
}

bool EFileUtils::mkdir(const QString &dirPath)
{
    if (dirPath.isEmpty()) {
        return false;
    }

    return QDir().mkpath(dirPath);
}

bool EFileUtils::dirIsEmpty(const QString &dirPath)
{
    if (dirExists(dirPath)) {
        return QDir(dirPath).entryInfoList(QDir::NoDotAndDotDot|QDir::NoSymLinks).empty();
    }
    return true;
}

bool EFileUtils::checkDirHasFileBySuffix(const QString &dirPath,
                                         const QString &suffix)
{
    if (!dirExists(dirPath)) {
        return !QDir(dirPath).entryInfoList({QString("*.%1").arg(suffix)},
                                            QDir::NoDotAndDotDot|QDir::NoSymLinks).empty();
    }
    return false;
}

void EFileUtils::saveToFile(const QString &filename,
                            const QByteArray &data)
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

QString EFileUtils::urlToLocalFile(const QString &fileUrl)
{
    if (fileUrl.isEmpty()) {
        return QStringLiteral("");
    }
    if (fileUrl.startsWith(QStringLiteral("qrc:/"))) {
        return fileUrl.sliced(4);
    }
    if (fileUrl.startsWith(QStringLiteral("file:///"))) {
#ifdef Q_OS_WIN32
    return fileUrl.sliced(8);
#elif defined Q_OS_MACOS
    return fileUrl.sliced(7);
#endif
    }
    return fileUrl;
}

QString EFileUtils::filenameToUrl(const QString &filename)
{
    if (filename.isEmpty()) {
        return QStringLiteral("");
    }
    if (filename.startsWith(QStringLiteral("qrc:/"))) {
        return QStringLiteral("file://") + filename.sliced(4);
    }
    return filename.startsWith(QStringLiteral("file:///"))
            ? filename : (QStringLiteral("file://") + filename);
}

QString EFileUtils::format(const QString &filename)
{
    const QString curFileName = urlToLocalFile(filename);
    QString format = MimeDatabase->mimeTypeForFile(
                curFileName, QMimeDatabase::MatchContent).preferredSuffix();
    if (format.isEmpty()) {
        format = MimeDatabase->mimeTypeForFile(
                    curFileName, QMimeDatabase::MatchExtension).preferredSuffix();
    }
    return format;
}

QString EFileUtils::mimeType(const QString &filename)
{
    return MimeDatabase->mimeTypeForFile(urlToLocalFile(filename),
                                         QMimeDatabase::MatchContent).name();
}

QString EFileUtils::suffixOnlyByFileName(const QString &filename)
{
    const QStringList list = filename.split(QStringLiteral("."));
    return list.isEmpty() ? QStringLiteral("") : list.last();
}

bool EFileUtils::mimeTypeIsVideo(const QString &filename)
{
    QString fileSuffix = suffixOnlyByFileName(filename).toLower();
    if (EFileFormatConstants::VideoFormatMap.contains(fileSuffix)) {
        return EFileFormatConstants::VideoFormatMap.value(
                    fileSuffix).contains(mimeType(filename).toLower());
    }
    return false;
}
