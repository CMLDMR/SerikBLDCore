#ifndef DILEKCEMANAGER_H
#define DILEKCEMANAGER_H
#include <QtGlobal>
#include "item.h"
#include "db.h"
#include "dilekce.h"
#include "dilekceaciklama.h"
#include <QString>
#include "SerikBLDCore_global.h"
#include <QVector>

class SERIKBLDCORE_EXPORT DilekceManager : virtual public DB
{
public:
    explicit DilekceManager();

    DilekceManager( DB* mDB );

    DilekceManager( mongocxx::database *_db );

    boost::optional<Dilekce*> Create_Dilekce();

    bool Update( Dilekce* dilekce );

    bool insertDilekce( const Dilekce* dilekce );

    bool insertAciklama( const DilekceAciklama* aciklama  );

    QVector<Dilekce> findDilekce(const Item &itemFilter , const mongocxx::options::find findOptions = mongocxx::options::find() );

    QVector<Dilekce> findByTelefon(const QString &mTelefonNumarasi );

    QVector<Dilekce> findByTCNO( const QString &mTCNO );

    QVector<Dilekce> findBySayi( const int &sayi );

    QVector<DilekceAciklama> findAciklama(const std::string &dilekceOid );

    boost::optional<Dilekce*> LoadDilekce( const std::string &oid );

};

#endif // DILEKCEMANAGER_H
