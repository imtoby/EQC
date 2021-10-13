#pragma once
#ifndef ESTRINGUTILS_H_79F37B59_2EE8_4F60_A7FA_6536B7AB03BF
#define ESTRINGUTILS_H_79F37B59_2EE8_4F60_A7FA_6536B7AB03BF

#include <QObject>

class EStringUtils : public QObject
{
    Q_OBJECT

    QString md5(const QByteArray& data) const;
};

#endif // ESTRINGUTILS_H_79F37B59_2EE8_4F60_A7FA_6536B7AB03BF
