#ifndef MECLISUYESI_H
#define MECLISUYESI_H

#include "tc.h"


namespace SerikBLDCore {


namespace Meclis {


namespace UyeKey {
static const std::string Collection{"MeclisUyeler"};
static const std::string tcOid{"tcOid"};
static const std::string partiAdi{"partiAdi"};
static const std::string komisyonAdi{"komisyonAdi"};
static const std::string donemAdi{"donemAdi"};
}



class SERIKBLDCORE_EXPORT MeclisUyesi : public SerikBLDCore::Item
{
public:
    explicit MeclisUyesi();
    MeclisUyesi( const MeclisUyesi& other );
    MeclisUyesi( MeclisUyesi&& other );

    MeclisUyesi& operator=( const MeclisUyesi& other );
    MeclisUyesi& operator=( MeclisUyesi&& other );

    MeclisUyesi& setTCOid( const std::string& tcOid );
    MeclisUyesi& setTCOid( const bsoncxx::oid& tcOid );
    MeclisUyesi& setPartiAdi( const std::string& partiAdi );
    MeclisUyesi& addKomisyonAdi( const std::string& komisyonOid );
    MeclisUyesi& delKomisyonAdi( const std::string& komisyonAdi );
    MeclisUyesi& setDonemAdi( const std::string& donem );

    QString tcOid() const;
    QString partiAdi() const;
    QString donemAdi() const;
    QVector<QString> komisyonUyelikleri() const;
};


namespace DonemKey {
static const std::string Collection{"MeclisDonemi"};
static const std::string baslangicJulianDay{"baslangicJulianday"};
static const std::string bitisJulianDay{"bitisJulianday"};
static const std::string endJulianDate{"endJulianDate"};
static const std::string startJulianDate{"startJulianDate"};
}

class SERIKBLDCORE_EXPORT MeclisDonemi : public SerikBLDCore::Item
{
public:
    explicit MeclisDonemi();
    MeclisDonemi& setDonem(const int& baslangicYear , const int& bitisYear );
    QString donem() const;
    MeclisDonemi& setBaslangicDate( const std::int64_t &julianBaslangic );
    MeclisDonemi& setBitisDate( const std::int64_t &julianBitis );
};


namespace PartiKey {
static const std::string Collection{"Partiler"};
static const std::string parti{"parti"};
inline constexpr std::string sira{"sira"};
}

class SERIKBLDCORE_EXPORT PartiItem : public SerikBLDCore::Item
{
public:
    explicit PartiItem();

    PartiItem& setParti( const std::string& parti );

    QString parti() const;

    PartiItem& setSira( const std::int32_t &sira );

    std::int32_t Sira() const;
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
