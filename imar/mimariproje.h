#ifndef MIMARIPROJE_H
#define MIMARIPROJE_H

#include "item.h"

namespace SerikBLDCore {


namespace Imar {


namespace MimariProje {


class SERIKBLDCORE_EXPORT MainProje : public SerikBLDCore::Item
{
public:
    static const std::string Collection;
    static const std::string keyFirmaOid;
    static const std::string keyBasvuruJulianDay;
    static const std::string keyAda;
    static const std::string keyParsel;
    static const std::string keyAdi;
    static const std::string keyMahalle;
    static const std::string keyOnay;
    static const std::string keyOnaylamaTarihi;




public:
    explicit MainProje();
    explicit MainProje( const bsoncxx::oid& firmaOid , const std::int64_t& basvuruJulianday );

    MainProje& setAdi( const std::string& adi );
    MainProje& setAda( const int& adaNo );
    MainProje& setParsel( const int& parselNo );
    MainProje& setMahalle( const std::string& mahalle );
    MainProje& setFirmaOid( const bsoncxx::oid& firmaOid );
    MainProje& setBasvuruJulianDay( const std::int64_t& basvuruJulianDay );
    MainProje& setOnay( const bool& onay );


    std::string adi() const;
    std::string firmaOid() const;
    std::int64_t basvuruJulianDay() const;
    std::int64_t ada() const;
    std::int64_t parsel() const;
    std::string mahalle() const;
    bool onay() const;
    std::int64_t onaylamaJulianDay() const;
};





class MimariProje;
class StatikProje;
class ElektrikProje;
class MechanicProje;
class RuhsatProje;
class IskeleProje;
class IskanProje;
class ZeminEtudu;
class AsansorProje;

class SERIKBLDCORE_EXPORT FileProject : public SerikBLDCore::Item
{
public:
    static const std::string keyFileOid;
    static const std::string keyOnay;
    static const std::string keyProjeAdi;

public:
    explicit FileProject();

    FileProject& setFileOid( const bsoncxx::oid& fileOid ) ;
    FileProject& setOnay( const bool& onay ) ;
    FileProject& setProjeAdi( const std::string& projeAdi );

    std::string fileOid() const;
    bool onay() const;
    std::string projeAdi() const;
};



class SERIKBLDCORE_EXPORT BaseProject : public SerikBLDCore::Item
{
public:
    static const std::string Collection;
    static const std::string keyMainProjeOid;
    static const std::string keyProje;
    static const std::string keyProjeOnay;
    static const std::string keyAssignPersonelOid;
    static const std::string keyAssignPersonelName;
    static const std::string keyProjectType;
    static const std::string keyProjeTitle;
    static const std::string keyOwnerOid;
    static const std::string keyOwnerAdSoyad;
    static const std::string keyOwnerTelefon;
public:
    explicit BaseProject();

    enum class ProjectType{
        Mimari = 0,
        Statik,
        Elektrik,
        Mekanik,
        Asansor,
        ZeminEtudu,
        Iskele,
        Ruhsat,
        Iskan,
        Bilinmiyor = 9999
    };

    BaseProject& setProjectType( SerikBLDCore::Imar::MimariProje::BaseProject::ProjectType type );
    BaseProject& setMainProjeOid( const bsoncxx::oid& mimariOid );
    BaseProject& setOnay( const bool& onay );
    BaseProject& assignPersonel(const bsoncxx::oid& personelOid , const std::string& personelName );
    bool deAssignPersonel( const bsoncxx::oid& personelOid );
    BaseProject& addProje( const FileProject& project );
    bool removeProje( const bsoncxx::oid& projectOid );
    BaseProject& setProjectOwner( const bsoncxx::oid& mtcOid , const std::string& adSoyad , const std::string& telefon );




    std::string title() const;
    std::string mainProjectOid() const;
    bool onay() const;
    std::string assignedPersonelOid() const;
    std::string assignedPersonelName() const;
    std::int64_t projeCount() const;
    boost::optional<FileProject> at( const int& index ) const;
    boost::optional<FileProject> at( const bsoncxx::oid& fileoid ) const;
    bool onaylanabilir() const;
    ProjectType type() const;
    std::string ownerOid() const;
    std::string ownerAdSoyad() const;
    std::string ownerTelefon() const;


    boost::optional<FileProject> operator[]( const int& index ) const;
    boost::optional<FileProject> operator[]( const bsoncxx::oid& fileoid ) const;

    MimariProje     toMimariProje();
    StatikProje     toStatikProje();
    ElektrikProje   toElectricProje();
    MechanicProje   toMechanicProjec();
    RuhsatProje     toRuhsat();
    IskeleProje     toIskele();
    IskanProje      toIskan();
    ZeminEtudu      toZeminEtudu();
    AsansorProje    toAsansor();


};




class SERIKBLDCORE_EXPORT MimariProje : public BaseProject
{
public:
    explicit MimariProje();

    std::string iconPath() const;
};






class SERIKBLDCORE_EXPORT StatikProje : public BaseProject
{
public:
    explicit StatikProje();

    std::string iconPath() const;
};

class SERIKBLDCORE_EXPORT ElektrikProje : public BaseProject
{
public:
    explicit ElektrikProje();

    std::string iconPath() const;
};

class SERIKBLDCORE_EXPORT MechanicProje : public BaseProject
{
public:
    explicit MechanicProje();

    std::string iconPath() const;
};

class SERIKBLDCORE_EXPORT RuhsatProje : public BaseProject
{
public:
    explicit RuhsatProje();

    std::string iconPath() const;
};

class SERIKBLDCORE_EXPORT IskeleProje : public BaseProject
{
public:
    explicit IskeleProje();

    std::string iconPath() const;
};

class SERIKBLDCORE_EXPORT IskanProje : public BaseProject
{
public:
    explicit IskanProje();

    std::string iconPath() const;
};

class SERIKBLDCORE_EXPORT ZeminEtudu : public BaseProject
{
public:
    explicit ZeminEtudu();

    std::string iconPath() const;
};

class SERIKBLDCORE_EXPORT AsansorProje : public BaseProject
{
public:
    explicit AsansorProje();

    std::string iconPath() const;
};


}



}



}




#endif // MIMARIPROJE_H
