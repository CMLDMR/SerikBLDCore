#ifndef TALEPMANAGER_H
#define TALEPMANAGER_H

#include "talep.h"
#include "db.h"
#include "Config.h"


class SERIKBLDCORE_EXPORT TalepManager : public DB
{
public:
    TalepManager();
    TalepManager(DB* mDB);
    TalepManager( mongocxx::database* _db );

    bool insertTalep( const Talep* item );

    QVector<Talep> findTalep( const Talep &filter , int limit = 20 , int skip = 0);


};




#endif // TALEPMANAGER_H
