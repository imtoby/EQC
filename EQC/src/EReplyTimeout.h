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

private slots:
    void onTimeout();
};

#endif // EREPLYTIMEOUT_H_854411AC_0795_4ABE_8888_ACA8862C8C84
