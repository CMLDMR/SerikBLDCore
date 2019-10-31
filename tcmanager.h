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

    bool insertTC( TC* item );

    boost::optional<TC*> Load_byTCNO( const std::string &tcno );
    boost::optional<TC*> Load_byTEL( const std::string &tel );

    boost::optional<TC*> Load_byOID( const std::string &oid );
    boost::optional<TC*> Load_byOID( const bsoncxx::oid &oid );
};

#endif // TCMANAGER_H
