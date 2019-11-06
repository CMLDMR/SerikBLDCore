#ifndef QOID_H
#define QOID_H

#include "Config.h"

#ifdef MOBILE

#include <QObject>
#include <QJsonValue>

class QOid : public QJsonValue
{
    Q_OBJECT
public:
    explicit QOid(QObject *parent = nullptr);

signals:

public slots:
};

#endif

#endif // QOID_H
