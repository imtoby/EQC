#include "EStringUtils.h"
#include <QByteArray>
#include <QCryptographicHash>

QString EStringUtils::md5(const QByteArray &data) const
{
    QByteArray ba = QCryptographicHash::hash(data, QCryptographicHash::Md5);
    return ba.toHex();
}
