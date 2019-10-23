#ifndef DILEKCEMANAGER_H
#define DILEKCEMANAGER_H
#include <QtGlobal>
#include "item.h"
#include "db.h"
#include "dilekce.h"
#include <QString>
#include "SerikBLDCore_global.h"
#include <QVector>

class SERIKBLDCORE_EXPORT DilekceManager : public DB
{
public:
    explicit DilekceManager();
    DilekceManager( DB* mDB );


    boost::optional<Dilekce*> Create_Dilekce();

    bool Update( Dilekce* dilekce );

    bool insertDilekce( const Dilekce* dilekce );

    QVector<Dilekce> findDilekce(const Item &itemFilter );

    QVector<Dilekce> findByTelefon(const QString &mTelefonNumarasi );

    QVector<Dilekce> findByTCNO( const QString &mTCNO );

    QVector<Dilekce> findBySayi( const int &sayi );


};

#endif // DILEKCEMANAGER_H
