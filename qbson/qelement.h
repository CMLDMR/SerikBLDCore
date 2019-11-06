#ifndef QELEMENT_H
#define QELEMENT_H

#include "Config.h"

#ifdef MOBILE

#include <QObject>
#include <QDebug>








class QElement : public QObject
{
    Q_OBJECT
public:
    explicit QElement(QObject *parent = nullptr);


    enum class ElementType
    {
        e_Bool = 0,
        e_Int32,
        e_Int64,
        e_Double,
        e_Oid,
        e_Utf8,
        e_Binary
    };





signals:

public slots:

private:
    QString mKey;
    ElementType mType;
    QVariant mValue;
};

Q_DECLARE_METATYPE(QElement);









#endif

#endif // QELEMENT_H
