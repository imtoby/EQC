#include "EReplyTimeout.h"

#include <QNetworkReply>
#include <QTimer>

struct EReplyTimeoutPrivate
{
    EReplyTimeoutPrivate() {}
};

EReplyTimeout::EReplyTimeout(QNetworkReply *reply, const int timeout)
    : QObject(reply)
{
    Q_ASSERT(reply);
    if (reply && reply->isRunning()) {
        QTimer::singleShot(timeout, this, &EReplyTimeout::onTimeout);
    }
}

void EReplyTimeout::onTimeout()
{
    QNetworkReply *reply = static_cast<QNetworkReply*>(parent());
    if (reply->isRunning()) {
        reply->abort();
        reply->deleteLater();
        emit timeout();
    }
}
