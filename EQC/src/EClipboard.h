#pragma once
#ifndef ECLIPBOARD_H_3863F9F2_F39E_4357_AEE7_BE54509B7FEE
#define ECLIPBOARD_H_3863F9F2_F39E_4357_AEE7_BE54509B7FEE

#include <QObject>

class EClipboard : public QObject
{
    Q_OBJECT
public:
    explicit EClipboard(QObject *parent = nullptr);

signals:

};

#endif // ECLIPBOARD_H_3863F9F2_F39E_4357_AEE7_BE54509B7FEE
