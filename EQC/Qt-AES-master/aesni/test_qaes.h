#pragma once
#ifndef TEST_QAES_H_8F732711_E9C1_4196_9CBE_CB1CC8797646
#define TEST_QAES_H_8F732711_E9C1_4196_9CBE_CB1CC8797646

#include "qaesencryption.h"
#include <QCryptographicHash>
#include <QDebug>
#include <QByteArray>
#include <QString>

void test_AES128_CBC_PKCS7() {
    // test AES128_CBC_PKCS7 ======= start
    QAESEncryption encryption(QAESEncryption::AES_128,
                              QAESEncryption::CBC, QAESEncryption::PKCS7);
    QString inputStr("1234567890123456");
    int blockLen = 16;
    QByteArray hashKey = QCryptographicHash::hash("key123456789123",
                                                  QCryptographicHash::Md5);
    QByteArray hashIv = QCryptographicHash::hash("whdjk81235&^%$&2hwgwg",
                                                  QCryptographicHash::Md5);
    QByteArray encodeText = encryption.encode(inputStr.toLocal8Bit(), hashKey, hashIv);
    qDebug() << "encodeText:" << encodeText;
    QByteArray decodeText = encryption.decode(encodeText, hashKey, hashIv);
    qDebug() << "decodeText:" << decodeText;
    QByteArray result = encryption.removePadding(decodeText);
    qDebug() << "result:" << result;
    QByteArray padding = decodeText.remove(0, encryption.removePadding(decodeText).length());
    qDebug() << "padding:" << padding;
    qDebug() << (padding.size() == blockLen);
    // test AES128_CBC_PKCS7 ======= end
}

#endif // TEST_QAES_H_8F732711_E9C1_4196_9CBE_CB1CC8797646
