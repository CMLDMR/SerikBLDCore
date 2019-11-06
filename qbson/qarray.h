#ifndef QARRAY_H
#define QARRAY_H

#include "Config.h"

#ifdef MOBILE

#include <QObject>

class QArray : public QObject
{
    Q_OBJECT
public:
    explicit QArray(QObject *parent = nullptr);

signals:

public slots:
};

#endif

#endif // QARRAY_H
