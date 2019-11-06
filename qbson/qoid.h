#ifndef QOID_H
#define QOID_H

#include <QObject>

class QOid : public QObject
{
    Q_OBJECT
public:
    explicit QOid(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QOID_H
