#ifndef TALEPMANAGER_H
#define TALEPMANAGER_H

#include "talep.h"
#include "talepsubitem.h"
#include "db.h"
#include "Config.h"

namespace SerikBLDCore {

class SERIKBLDCORE_EXPORT TalepManager : public DB
{
public:
    TalepManager();
    TalepManager(DB* mDB);
    TalepManager( mongocxx::database* _db );

    bool insertTalep( const Talep* item );

    std::string insertTalep( const Talep& item );

    bool updateTalep( const Talep* item );

    QVector<Talep> findTalep( const Talep &filter , int limit = 20 , int skip = 0);

    Talep findOneTalep( const Talep &filter );

    bool insertTalepSubItem( const TalepSubItem* item );

    QVector<TalepSubItem> findTalepSubItem( const QString &talepOid );

    ///
    /// \brief Birime Ait Talep/Şikayetle İlgili İstatistik Bilgileri
    /// Geri Döndürür.<BR>Örnek Kode<BR> <BLOCKQUOTE><CODE>auto container = this->Header ()->addWidget (cpp14::make_unique<WContainerWidget>());<BR>
    /// container->addStyleClass (Bootstrap::Grid::col_full_12);<BR>
    /// container->setMargin (15,Side::Top|Side::Bottom);<BR>
    /// auto toolbarWidget = container->addWidget (cpp14::make_unique<WToolBar>()); </BLOCKQUOTE></CODE><BR>
    /// \param birim
    /// \return
    ///
    TalepKey::DurumPipelineResult durumPipeLine(const QString &birim );

    TalepKey::KaynakPipelineResult kaynakPipeLine( const QString &birim );

};


}




#endif // TALEPMANAGER_H
