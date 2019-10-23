#ifndef TCMANAGER_H
#define TCMANAGER_H

#include "db.h"
#include "tc.h"



class SERIKBLDCORE_EXPORT TCManager : virtual public DB
{
public:
    explicit TCManager();
    TCManager( DB* mDB );
    TCManager( mongocxx::database* _db );

    boost::optional<TC> Create_TC();

    boost::optional<TC*> Load_byTCNO( const std::string &tcno );

    boost::optional<TC*> Load_byOID( const std::string &oid );
    boost::optional<TC*> Load_byOID( const bsoncxx::oid &oid );
};

#endif // TCMANAGER_H
