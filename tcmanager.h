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


#ifdef Q_CC_MSVC

    boost::optional<SerikBLDCore::TC> Create_TC();
    boost::optional<SerikBLDCore::TC*> Load_byTCNO( const std::string &tcno );
    boost::optional<SerikBLDCore::TC*> Load_byTEL( const std::string &tel );
    boost::optional<SerikBLDCore::TC*> Load_byOID( const std::string &oid );
    boost::optional<SerikBLDCore::TC*> Load_byOID( const bsoncxx::oid &oid );

#endif
#ifdef Q_CC_GNU

    std::optional<SerikBLDCore::TC> Create_TC();
    std::optional<SerikBLDCore::TC*> Load_byTCNO( const std::string &tcno );
    std::optional<SerikBLDCore::TC*> Load_byTEL( const std::string &tel );
    std::optional<SerikBLDCore::TC*> Load_byOID( const std::string &oid );
    std::optional<SerikBLDCore::TC*> Load_byOID( const bsoncxx::oid &oid );

#endif


    bool insertTC( SerikBLDCore::TC* item );

    bool updateTC( SerikBLDCore::TC* tcItem );


};


class SERIKBLDCORE_EXPORT TCManagerV2 : public ListItem<SerikBLDCore::TC>
{
public:
    explicit TCManagerV2( SerikBLDCore::DB* _db );


    virtual void onList(const QVector<TC> *mlist) override;

    virtual void errorOccured(const std::string &errorText) override;



#ifdef Q_CC_MSVC

    boost::optional<SerikBLDCore::TC*> Load_byTCNO( const std::string &tcno );
    boost::optional<SerikBLDCore::TC*> Load_byTEL( const std::string &tel );

    boost::optional<SerikBLDCore::TC*> Load_byOID( const std::string &oid );
    boost::optional<SerikBLDCore::TC*> Load_byOID( const bsoncxx::oid &oid );

#endif
#ifdef Q_CC_GNU

    std::optional<SerikBLDCore::TC> Create_TC();
    std::optional<SerikBLDCore::TC*> Load_byTCNO( const std::string &tcno );
    std::optional<SerikBLDCore::TC*> Load_byTEL( const std::string &tel );
    std::optional<SerikBLDCore::TC*> Load_byOID( const std::string &oid );
    std::optional<SerikBLDCore::TC*> Load_byOID( const bsoncxx::oid &oid );

#endif


};

}

#endif // TCMANAGER_H
