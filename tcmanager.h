#ifndef TCMANAGER_H
#define TCMANAGER_H

#include "db.h"
#include "tc.h"



class SERIKBLDCORE_EXPORT TCManager : public DB
{
public:
    explicit TCManager();
    TCManager( DB* mDB );
    TCManager( mongocxx::database* _db );

    boost::optional<TC> Create_TC();
};

#endif // TCMANAGER_H
