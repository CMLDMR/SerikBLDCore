#ifndef MECLISITEM_H
#define MECLISITEM_H

#include "item.h"

namespace SerikBLDCore {

namespace Meclis {











/**
 * Meclis Item Ait Keyler
 */
namespace Key {
static const std::string Collection{"MeclisV2"};
static const std::string ay{"ay"};
static const std::string yil{"yil"};
static const std::string julianDate{"julianDate"};
static const std::string yayinda{"yayinda"};
static const std::string gundem{"gundem"};
static const std::string saat{"saat"};
}


/**
 * @brief The MeclisItem class
 * Meclis Kararları ve Canlı Yayın Kayıtlarının Tutulduğu
 */
class SERIKBLDCORE_EXPORT MeclisItem : public Item
{
public:
    explicit MeclisItem();

    MeclisItem& setYil( const int& yil );
    MeclisItem& setAy( const QString& ay );
    MeclisItem& setJulianDay( const int& julianDay );
    MeclisItem& setYayinda( const bool& yayinda );
    MeclisItem& setGundem( const QString& gundem );
    MeclisItem& setSaat( const long& secFromStartOfDay );

    QString gundem() const;
    QString ay() const;
    int32_t yil() const;
    int64_t julianDay() const;
    bool yayinda() const;
    long saat() const;
};












/**
 *Kararlara Ait Keyler
 */
namespace KararKey {
static const std::string Collection{"MeclisKararlari"};
static const std::string MeclisOid{"MeclisOid"};
static const std::string KararOid{"KararOid"};
static const std::string Sayi{"Sayi"};
}

/**
 * @brief The KararItem class Kararların Tutulduğu item
 */
class SERIKBLDCORE_EXPORT KararItem : public Item
{
public:
    explicit KararItem();
    explicit KararItem( const std::string& meclisOid );

    KararItem& setMeclisOid( const std::string& meclisOid );
    KararItem& setKararOid( const std::string& kararOid );
    KararItem& setSayi( const std::int32_t& sayi );

    std::int32_t sayi() const;
    std::string kararOid() const;
    std::string meclisOid() const;



};














/**
 *Linke Ait Keyler
 */
namespace LinkKey {
static const std::string Collection{"MeclisYouTubeLinks"};
static const std::string MeclisOid{"MeclisOid"};
static const std::string VideoID{"videoID"};

}


/**
 * @brief The YouTubeLink class : Meclis Canlı Yayınlarının Tutulduğu Item
 */
class SERIKBLDCORE_EXPORT YouTubeLink : public Item
{
public:
    explicit YouTubeLink();

    YouTubeLink& setVideoID( const std::string& videoid );
    YouTubeLink& setMeclisOid( const std::string& meclisoid );

    std::string videoid() const;
    std::string videoUrl() const;
    std::string videothump0() const;
    std::string videothump1() const;
    std::string videothump2() const;
    std::string videothump3() const;

    std::string meclisoid() const;
};




namespace RaporKey {
static const std::string Collection{"MeclisRaporlar"};
static const std::string meclisOid{"meclisOid"};
static const std::string raporAdi{"raporadi"};
static const std::string raporOid{"raporOid"};
static const std::string kimden{"kimden"};
}


class SERIKBLDCORE_EXPORT RaporItem : public Item
{
public:
    explicit RaporItem();

    RaporItem& setMeclisOid( const std::string &meclisOid );
    RaporItem& setMeclisOid( const bsoncxx::oid &meclisOid );
    RaporItem& setRaporAdi( const std::string& raporAdi );
    RaporItem& setRaporOid( const std::string& raporOid );
    RaporItem& setRaporOid( const bsoncxx::oid& raporOid );
    RaporItem& setKimden( const std::string& kimden );

    QString meclisOid() const;
    QString raporAdi() const;
    QString raporOid() const;
    QString kimden() const;
};


namespace TeklifKey {
static const std::string Collection{"MeclisTeklifler"};
static const std::string meclisOid{"meclisOid"};
static const std::string teklifAdi{"teklifadi"};
static const std::string teklifOid{"teklifOid"};
static const std::string kimden{"kimden"};
}


class SERIKBLDCORE_EXPORT TeklifItem : public Item
{
public:
    explicit TeklifItem();

    TeklifItem& setMeclisOid( const std::string &meclisOid );
    TeklifItem& setMeclisOid( const bsoncxx::oid &meclisOid );
    TeklifItem& setTeklifAdi( const std::string& teklifAdi );
    TeklifItem& setTeklifOid( const std::string& teklifOid );
    TeklifItem& setTeklifOid( const bsoncxx::oid& teklifOid );
    TeklifItem& setKimden( const std::string& kimden );

    QString meclisOid() const;
    QString teklifAdi() const;
    QString teklifOid() const;
    QString kimden() const;
};



}





}


#endif // MECLISITEM_H
