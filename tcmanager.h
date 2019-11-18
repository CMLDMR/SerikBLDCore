#ifndef TCMANAGER_H
#define TCMANAGER_H

#include "db.h"
#include "tc.h"

namespace SerikBLDCore {

class SERIKBLDCORE_EXPORT TCManager : public DB
{
public:
    explicit TCManager();

    TCManager( DB* mDB );
    TCManager( mongocxx::database* _db );


    boost::optional<SerikBLDCore::TC> Create_TC();

    bool insertTC( SerikBLDCore::TC* item );

    boost::optional<SerikBLDCore::TC*> Load_byTCNO( const std::string &tcno );
    boost::optional<SerikBLDCore::TC*> Load_byTEL( const std::string &tel );

    boost::optional<SerikBLDCore::TC*> Load_byOID( const std::string &oid );
    boost::optional<SerikBLDCore::TC*> Load_byOID( const bsoncxx::oid &oid );
};

}

#endif // TCMANAGER_H
