#ifndef TALEPMANAGER_H
#define TALEPMANAGER_H

#include "talep.h"
#include "talepsubitem.h"
#include "db.h"
#include "Config.h"

namespace SerikBLDCore {

///
/// \brief The TalepManager class
/// Bu Sınıf Talep leri Yönetir. Talep ekler, günceller ve Talep leri listeler. Talep lere ait eventları da yönetir. Açıklama , SMS , Fotoğraf , PDF ekler.
/// Ayrıca Bu TalepSubItem ları CRUD yapar.
class SERIKBLDCORE_EXPORT TalepManager : public DB
{
public:
    TalepManager();
    TalepManager(DB* mDB);
    TalepManager( mongocxx::database* _db );

    ///
    /// \brief <b>item</b> talebi veri tabanına ekler.
    /// \param item
    /// \return Taleb Veritabanına eklendi ise <b>true</b> yoksa <b>false</b> döndürür.
    ///
    bool insertTalep( const Talep* item );


    ///
    /// \brief <b>item</b> talebi veri tabanına ekler.
    /// \param item
    /// \return talebin oid bilgisini geri döndürür.
    ///
    std::string insertTalep( const Talep& item );


    ///
    /// \brief <b>item</b> ile eşleşen talebi günceller.
    /// \param item
    /// \return Talep Güncellendi ise <b>true</b> yoksa <b>false</b> geri döndürür.
    ///
    bool updateTalep( const Talep* item );



    ///
    /// \brief <b>filter</b> ile eşleşen tüm talepleri listeler.
    /// \param filter
    /// \param limit
    /// \param skip
    /// \return
    ///
    QVector<Talep> findTalep( const Talep &filter , int limit = 20 , int skip = 0);



    ///
    /// \brief <b>filter</b> ile Eşleşen Mevcut Talebi Geri Döndürür.
    /// \param filter
    /// \return
    ///
    Talep findOneTalep( const Talep &filter );


    /**
     * @brief talepCount
     * @param filter
     * @return
     */
    std::int64_t talepCount( const Talep& filter = Talep() );




    ///
    /// \brief Mevcut Talebe Açıklama , Resim , SMS , Fotoğraf yada PDF ekler.
    /// \param item
    /// \return
    ///
    bool insertTalepSubItem( const TalepSubItem* item );


    ///
    /// \brief Talebe Ait Açıklama, Resim , SMS , Fotoğraf ve PDF eklentileri listeler
    /// \param talepOid
    /// \return
    ///
    QVector<TalepSubItem> findTalepSubItem( const QString &talepOid );




    ///
    /// \brief Birime Ait Talep/Şikayetle İlgili İstatistik Bilgileri
    /// \param birim
    /// \return
    ///
    TalepKey::DurumPipelineResult durumPipeLine(const QString &birim );


    ///
    /// \brief Birime Ait Talep/Şikayetle İlgili İstatistik Bilgileri
    /// \param filter
    /// \return
    ///
    TalepKey::DurumPipelineResult durumPipeLine( const Talep &filter );



    ///
    /// \brief Taleplerin Nerden Geldiğinin İstatistik Bilgilerini Verir.
    /// \param birim
    /// \return KaynakPipelineResult
    ///
    TalepKey::KaynakPipelineResult kaynakPipeLine( const QString &birim );





    ///
    /// \brief Taleplerin Nerden Geldiğinin İstatistik Bilgilerini Verir.
    /// \param filter
    /// \return
    ///
    TalepKey::KaynakPipelineResult kaynakPipeLine( const Talep &filter );

};


}




#endif // TALEPMANAGER_H
