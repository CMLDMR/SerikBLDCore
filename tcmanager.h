#ifndef TCMANAGER_H
#define TCMANAGER_H

#include "db.h"
#include "tc.h"
#include "listitem.h"
namespace SerikBLDCore {

class SERIKBLDCORE_EXPORT TCManager : public DB
{
public:
    explicit TCManager();

    explicit TCManager( DB* mDB );
    explicit TCManager( mongocxx::database* _db );


    boost::optional<SerikBLDCore::TC> Create_TC();

    bool insertTC( SerikBLDCore::TC* item );

    bool updateTC( SerikBLDCore::TC* tcItem );

    boost::optional<SerikBLDCore::TC*> Load_byTCNO( const std::string &tcno );
    boost::optional<SerikBLDCore::TC*> Load_byTEL( const std::string &tel );

    boost::optional<SerikBLDCore::TC*> Load_byOID( const std::string &oid );
    boost::optional<SerikBLDCore::TC*> Load_byOID( const bsoncxx::oid &oid );
};


class SERIKBLDCORE_EXPORT TCManagerV2 : public ListItem<SerikBLDCore::TC>
{
public:
    explicit TCManagerV2( SerikBLDCore::DB* _db );


    virtual void onList(const QVector<TC> *mlist) override;

    virtual void errorOccured(const std::string &errorText) override;

};

}

#endif // TCMANAGER_H
