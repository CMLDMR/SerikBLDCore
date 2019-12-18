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
#include "dilekcecevap.h"


namespace SerikBLDCore {

class SERIKBLDCORE_EXPORT DilekceManager : public DB
{
public:
    explicit DilekceManager();

    explicit DilekceManager( DB* mDB );

    explicit DilekceManager( mongocxx::database *_db );

    boost::optional<Dilekce*> Create_Dilekce();

    bool Update( Dilekce* dilekce );


    bool insertDilekce( const Dilekce* dilekce );

    boost::optional<bsoncxx::oid> insertCevap( const DilekceCevap* cevap );

    /**
     * @brief updateDilekce: Mevcut Dilekçeyi Günceller.
     * @param dilekce
     * @return
     */
    virtual bool updateDilekce( const Dilekce* dilekce );

    bool insertAciklama( const DilekceAciklama* aciklama  );

    QVector<Dilekce> findDilekce(const Item &itemFilter , const mongocxx::options::find findOptions = mongocxx::options::find() );

    QVector<Dilekce> findByTelefon(const QString &mTelefonNumarasi );

    QVector<Dilekce> findByTCNO( const QString &mTCNO );

    QVector<Dilekce> findBySayi( const int &sayi );

    QVector<DilekceAciklama> findAciklama(const std::string &dilekceOid );

    bool deleteAciklama( const std::string &oid );

    boost::optional<Dilekce*> LoadDilekce( const std::string &oid );

    boost::optional<DilekceCevap*> LoadDilekceCevap( const std::string &cevapOid );

    QString TaranmisDilekcePath( const QString &taranmisdilekceOid );

    /**
     * @brief insertYeniKategori
     * @param yeniKategori
     * @return
     */
    virtual bool insertYeniKategori( const QString& yeniKategori );


    /**
     * @brief Kategorilist
     * @return
     */
    QStringList Kategorilist();


    /**
     * @brief deleteKategori
     * @param kategoriName
     * @return
     */
    virtual bool deleteKategori( const QString& kategoriName );


    /**
     * @brief reNameKategori
     * @param oldName
     * @param newName
     * @return
     */
    virtual bool reNameKategori( const QString& oldName , const QString& newName );



};


}


#endif // DILEKCEMANAGER_H
