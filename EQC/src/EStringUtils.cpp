#include "EStringUtils.h"
#include <QByteArray>
#include <QCryptographicHash>

QString EStringUtils::md5(const QByteArray &data) const
{
    QByteArray ba = QCryptographicHash::hash(data, QCryptographicHash::Md5);
    return ba.toHex();
}

QString EStringUtils::bytesToSizeUnitString(qint64 bytes) const
{
    const static QStringList SizeUnit = {"B", "KB", "MB", "GB", "TB"};

    int nIndex = 0;
    QString sStr = QString::number(bytes) + SizeUnit[0];
    while (bytes > 1024 && nIndex < SizeUnit.size()) {
        bytes /= 1024.0;
        nIndex++;
    }
    if (nIndex > 0) {
        sStr = QString::number(bytes).left(3) + SizeUnit[nIndex];
    }
    return sStr;
}
