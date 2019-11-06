#ifndef QELEMENT_H
#define QELEMENT_H

#include <QObject>

class QElement : public QObject
{
    Q_OBJECT
public:
    explicit QElement(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QELEMENT_H
