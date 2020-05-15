#ifndef MIMARIPROJE_H
#define MIMARIPROJE_H

#include "item.h"

namespace SerikBLDCore {


namespace Imar {


namespace MimariProje {


class SERIKBLDCORE_EXPORT MimariProje : public SerikBLDCore::Item
{
public:
    static const std::string Collection;
    static const std::string keyFirmaOid;
    static const std::string keyBasvuruJulianDay;
    static const std::string keyAda;
    static const std::string keyParsel;
    static const std::string keyOnayli;
    static const std::string keyYetkiliPersonelOid;
    static const std::string keyAdi;
    static const std::string keyMahalle;
    static const std::string keyDWGOid;


public:
    explicit MimariProje();
    explicit MimariProje( const bsoncxx::oid& firmaOid , const std::int64_t& basvuruJulianday );

    MimariProje& setAdi( const std::string& adi );
    MimariProje& setAda( const int& adaNo );
    MimariProje& setParsel( const int& parselNo );
    MimariProje& setOnayli( const bool& onay , const bsoncxx::oid& personelOid );
    MimariProje& setYetkiliPersonelOid( const bsoncxx::oid& personelOid );
    MimariProje& setMahalle( const std::string& mahalle );
    MimariProje& setDWGFileOid( const bsoncxx::oid& fileOid );
    MimariProje& setFirmaOid( const bsoncxx::oid& firmaOid );
    MimariProje& setBasvuruJulianDay( const std::int64_t& basvuruJulianDay );

    std::string adi() const;
    std::string firmaOid() const;
    std::int64_t basvuruJulianDay() const;
    std::int64_t ada() const;
    std::int64_t parsel() const;
    bool onayli() const;
    std::string yetkiliPersonel() const;
    std::string mahalle() const;
    std::string dwgOid() const;
};


//class StatikProje : public SerikBLDCore::Item
//{
//public:
//    StatikProje();
//};

//class ElektrikProje : public SerikBLDCore::Item
//{
//public:
//    ElektrikProje();
//};

//class MekanikProje : public SerikBLDCore::Item
//{
//public:
//    MekanikProje();
//};

//class Ruhsat : public SerikBLDCore::Item
//{
//public:
//    Ruhsat();
//};


}



}



}




#endif // MIMARIPROJE_H
