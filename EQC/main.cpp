#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCryptographicHash>
#include <QDebug>

#include "src/EAsyncImageProvider.h"
#include "SingleApplication-master/singleapplication.h"
#include "qaesencryption.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    // test AES128_CBC_PKCS7 ======= start
    QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::CBC, QAESEncryption::PKCS7);
    //16 byte string
    QString inputStr("1234567890123456");
    int blockLen = 16;
    QString key("123456789123");

    QByteArray iv;
    quint8 iv_16[16]  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    for (int i=0; i<16; i++)
        iv.append(iv_16[i]);
    QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
    QByteArray encodeText = encryption.encode(inputStr.toLocal8Bit(), hashKey, iv);
    qDebug() << "encodeText:" << encodeText;
    QByteArray decodeText = encryption.decode(encodeText, hashKey, iv);
    qDebug() << "decodeText:" << decodeText;
    QByteArray result = encryption.removePadding(decodeText);
    qDebug() << "result:" << result;
    QByteArray padding = decodeText.remove(0, encryption.removePadding(decodeText).length());
    qDebug() << "padding:" << padding;
    qDebug() << (padding.size() == blockLen);
    // test AES128_CBC_PKCS7 ======= end

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.addImageProvider("async", new EAsyncImageProvider);
    engine.load(url);

    return app.exec();
}
