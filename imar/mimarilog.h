#ifndef MIMARILOG_H
#define MIMARILOG_H

#include "item.h"
#include "listitem.h"


namespace SerikBLDCore {

namespace Imar {

class DuzeltmeLog;
class AciklamaLog;
class DosyaLog;
class IslemLog;

class SERIKBLDCORE_EXPORT MimariLog : public SerikBLDCore::Item
{
public:
    static const std::string Collection;
    static const std::string keyprojeOid;
    static const std::string keyType;
    static const std::string keyAciklama;
    static const std::string keyDosyaOid;
    static const std::string keyEkleyen;
    static const std::string keyJulianDay;
    static const std::string keyMSecEpoch;
    static const std::string keyDuzeltildi;
public:
    explicit MimariLog();
    explicit MimariLog( const bsoncxx::oid& projeOid );

    enum class Type{
        Aciklama = 0,
        Duzeltme,
        Dosya,
        Log,
        bilinmeyen = 999
    };

    MimariLog& setProjeOid( const bsoncxx::oid& projeOid );
    MimariLog& setJulianDay( const std::int64_t& julianDay );
    MimariLog& setSecEpoch( const std::int64_t& mSecEpoch );
    MimariLog& setEkleyen( const std::string& adSoyad );
    MimariLog& setType( const SerikBLDCore::Imar::MimariLog::Type type );
    MimariLog& setCurrentDateTime();


    std::string projeOid() const;
    std::int64_t julianDay() const;
    std::int64_t mSecEpoch() const;
    std::string ekleyen() const;
    Type LogType() const;

    DuzeltmeLog toDuzeltmeLog();
    AciklamaLog toAciklamaLog();
    DosyaLog    toDosyaLog();
    IslemLog    toIslemLog();


};


class SERIKBLDCORE_EXPORT DuzeltmeLog : public MimariLog
{
public:
    DuzeltmeLog();
    DuzeltmeLog& setDuzeltme( const std::string& duzeltme );
    DuzeltmeLog& setDuzeltildi( const bool& duzeltildi );

    std::string duzeltme() const ;
    bool duzeltildi() const;
};

class SERIKBLDCORE_EXPORT AciklamaLog : public MimariLog
{
public:
    AciklamaLog();
    AciklamaLog& setAciklama( const std::string& aciklama );

    std::string aciklama() const;
};


class SERIKBLDCORE_EXPORT DosyaLog : public MimariLog
{
public:
    DosyaLog();
    DosyaLog& setFileOid( const bsoncxx::oid& fileOid );
    DosyaLog& setFileName( const std::string& fileName );

    std::string fileOid() const;
    std::string fileName() const;
};

class SERIKBLDCORE_EXPORT IslemLog : public MimariLog
{
public:
    IslemLog();
    IslemLog& setLog( const std::string& fileOid );

    std::string log() const;
};



class SERIKBLDCORE_EXPORT MimariLogManager : public SerikBLDCore::ListItem<MimariLog>
{
public:
    explicit MimariLogManager( DB* _db );

    void onList(const QVector<MimariLog> *mlist) override;

    void errorOccured(const std::string &errorText) override;
};

}

}



#endif // MIMARILOG_H
