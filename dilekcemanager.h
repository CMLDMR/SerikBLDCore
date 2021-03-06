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

#ifdef Q_CC_MSVC
        boost::optional<Dilekce*> Create_Dilekce();
        boost::optional<bsoncxx::oid> insertCevap( const DilekceCevap* cevap );
        boost::optional<Dilekce*> LoadDilekce( const std::string &oid );
        boost::optional<DilekceCevap*> LoadDilekceCevap( const std::string &cevapOid );
#endif
#ifdef Q_CC_GNU
        std::optional<Dilekce*> Create_Dilekce();
        std::optional<bsoncxx::oid> insertCevap( const DilekceCevap* cevap );
        std::optional<Dilekce*> LoadDilekce( const std::string &oid );
        std::optional<DilekceCevap*> LoadDilekceCevap( const std::string &cevapOid );
#endif


    bool Update( Dilekce* dilekce );


    bool insertDilekce( const Dilekce* dilekce );



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
