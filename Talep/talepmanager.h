#ifndef TALEPMANAGER_H
#define TALEPMANAGER_H

#include "talep.h"
#include "talepsubitem.h"
#include "db.h"
#include "Config.h"


class SERIKBLDCORE_EXPORT TalepManager : public DB
{
public:
    TalepManager();
    TalepManager(DB* mDB);
    TalepManager( mongocxx::database* _db );

    bool insertTalep( const Talep* item );

    bool updateTalep( const Talep* item );

    QVector<Talep> findTalep( const Talep &filter , int limit = 20 , int skip = 0);

    Talep findOneTalep( const Talep &filter );

    bool insertTalepSubItem( const TalepSubItem* item );

    QVector<TalepSubItem> findTalepSubItem( const QString &talepOid );

    TalepKey::DurumPipelineResult durumPipeLine(const QString &birim );

    TalepKey::KaynakPipelineResult kaynakPipeLine( const QString &birim );


};




#endif // TALEPMANAGER_H
