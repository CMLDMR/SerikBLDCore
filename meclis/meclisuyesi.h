#ifndef MECLISUYESI_H
#define MECLISUYESI_H

#include "tc.h"


namespace SerikBLDCore {


namespace Meclis {


namespace UyeKey {
static const std::string Collection{"MeclisUyeler"};
static const std::string tcOid{"tcOid"};
static const std::string partiOid{"partiOid"};
static const std::string komisyonOid{"komisyonOid"};
}



class SERIKBLDCORE_EXPORT MeclisUyesi : public SerikBLDCore::TC
{
public:
    MeclisUyesi();
    MeclisUyesi& setTCOid( const std::string& tcOid );
    MeclisUyesi& setTCOid( const bsoncxx::oid& tcOid );
    MeclisUyesi& setPartiOid( const std::string& partiOid );
    MeclisUyesi& setPartiOid( const bsoncxx::oid& partiOid );
    MeclisUyesi& setKomisyonOid( const std::string& komisyonOid );
    MeclisUyesi& setKomisyonOid( const bsoncxx::oid& komisyonOid );
    QString tcOid() const;
    QString partiOid() const;
    QString komisyonOid() const;
};


namespace DonemKey {
static const std::string Collection{"MeclisDonemi"};
static const std::string donem{"donem"};
}

class SERIKBLDCORE_EXPORT MeclisDonemi : public SerikBLDCore::Item
{
public:
    explicit MeclisDonemi();

    MeclisDonemi& setDonem( const std::string& donem );

    QString donem() const;
};


namespace PartiKey {
static const std::string Collection{"Partiler"};
static const std::string parti{"parti"};
}

class SERIKBLDCORE_EXPORT PartiItem : public SerikBLDCore::Item
{
public:
    explicit PartiItem();

    PartiItem& setParti( const std::string& parti );

    QString parti() const;
};


namespace KomisyonKey {
static const std::string Collection{"Komisyonlar"};
static const std::string komisyon{"komisyon"};
}

class SERIKBLDCORE_EXPORT KomisyonItem : public SerikBLDCore::Item
{
public:
    explicit KomisyonItem();

    KomisyonItem& setKomisyonAdi( const std::string& komisyonAdi );

    QString komisyonAdi() const;
};




}



}




#endif // MECLISUYESI_H
