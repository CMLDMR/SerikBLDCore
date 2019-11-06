#ifndef QDOCUMENT_H
#define QDOCUMENT_H

#include <QObject>

class QDocument : public QObject
{
    Q_OBJECT
public:
    explicit QDocument(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QDOCUMENT_H
