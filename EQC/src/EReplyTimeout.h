#pragma once
#ifndef EREPLYTIMEOUT_H_854411AC_0795_4ABE_8888_ACA8862C8C84
#define EREPLYTIMEOUT_H_854411AC_0795_4ABE_8888_ACA8862C8C84

#include <QObject>

class QNetworkReply;
class EReplyTimeout : public QObject
{
    Q_OBJECT
public:
    EReplyTimeout(QNetworkReply *reply, const int timeout = 3000);

signals:
    void timeout();

private slots:
    void onTimeout();
};

#endif // EREPLYTIMEOUT_H_854411AC_0795_4ABE_8888_ACA8862C8C84

/*
 * USE EXAMPLE
 *
QNetworkAccessManager *pManger = new QNetworkAccessManager(this);
QNetworkReply *pReply = pManger->get(QNetworkRequest(QUrl("https://www.google.com")));
EReplyTimeout *pTimeout = new EReplyTimeout(pReply, 1000);
// 超时进一步处理
connect(pTimeout, &EReplyTimeout::timeout, [=]() {
    qDebug() << "Timeout";
});
 */
