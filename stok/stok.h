#ifndef STOK_H
#define STOK_H

#include "item.h"


//TODO: Stok Modulu Tüm Birimlerin Kullanabileceği Şekilde Yapılacaktır.

namespace SerikBLDCore {


namespace Stok {


namespace StokKey {
static const std::string Collection{"StokGiris"};
static const std::string CollectionCikis{"StokCikis"};
static const std::string mudurluk{"mudurluk"};
static const std::string kategori{"kategori"};
static const std::string adi{"adi"};
static const std::string kodu{"kodu"};
static const std::string miktar{"miktar"};
static const std::string giris{"giris"};
static const std::string tcoid{"tcoid"};
static const std::string teslimAlan{"teslimAlan"};
}
class SERIKBLDCORE_EXPORT Stok : public SerikBLDCore::Item
{
public:


    struct TeslimAlan {
        std::string teslimAlan;
        std::int64_t miktar;
        std::int64_t julianDay;
        std::int64_t mSecSinceStartOfDay;
        explicit TeslimAlan(){}
        explicit TeslimAlan( const bsoncxx::document::view &view );
        Item getItem() const;
    };

    enum class Giris : bool
    {
        giris = true,
        cikis = false
    };

    explicit Stok( SerikBLDCore::Stok::Stok::Giris giris = SerikBLDCore::Stok::Stok::Giris::giris,
                   const std::string& mudurluk = "none" );

    Stok( const Stok& other );
    Stok( Stok&& other );
    Stok& operator=( const Stok& other );
    Stok& operator=( Stok&& other );

    Stok& setKategori( const bsoncxx::oid& kategoriOid );
    Stok& setAdi( const std::string& adi );
    Stok& setKodu( const bsoncxx::oid& kodOid );
    Stok& setMiktar( const std::int64_t& miktar );
    Stok& setTcOid( const bsoncxx::oid& tcoid );
    Stok& setMudurluk( const std::string& mudurluk );

    Stok& addTeslimAlan( const TeslimAlan& alan );




    QVector<TeslimAlan> Teslimler() const;
    std::int64_t kalanMiktar() const;

#ifdef Q_CC_MSVC
    boost::optional<bsoncxx::oid> kategori() const;
    boost::optional<bsoncxx::oid> kodu() const;
    boost::optional<bsoncxx::oid> tcoid() const;

#endif
#ifdef Q_CC_GNU
    std::optional<bsoncxx::oid> kategori() const;
    std::optional<bsoncxx::oid> kodu() const;
    std::optional<bsoncxx::oid> tcoid() const;
#endif

    std::string adi() const;
    std::int64_t miktar() const;


};





namespace StokKategoriKey {
static const std::string Collection{"stokyardimKat"};
static const std::string kategoriName{"kategori"};
static const std::string mudurluk{"mudurluk"};
}
class SERIKBLDCORE_EXPORT StokKategori : public SerikBLDCore::Item
{
public:
    explicit StokKategori( const std::string& mudurluk = "none" );
    StokKategori& setKategoriName( const std::string& kategoriName );
    std::string kategoriName() const;
    std::string mudurlukName() const;
    virtual void errorOccured(const std::string &errorText) override;
};



namespace StokKodKey {
static const std::string Collection{"stokKod"};
static const std::string adi{"adi"};
static const std::string birimi{"birimi"};
static const std::string kategoriOid{"kategoriOid"};
}

class SERIKBLDCORE_EXPORT StokKodItem : public SerikBLDCore::Item
{
public:
    explicit StokKodItem();
    StokKodItem( const StokKodItem& other );
    StokKodItem( StokKodItem&& other );

    StokKodItem& operator=( const StokKodItem& other );
    StokKodItem& operator=( StokKodItem&& other );

    StokKodItem& setAdi( const std::string& adi );
    StokKodItem& setBirim( const std::string& birim );
    StokKodItem& setKategoriOid( const bsoncxx::oid& kategoriOid );

    std::string adi() const;
    std::string birim() const;



#ifdef Q_CC_MSVC
        boost::optional<bsoncxx::oid> kategoriOid() const;
#endif
#ifdef Q_CC_GNU
        std::optional<bsoncxx::oid> kategoriOid() const;
#endif

};

}





}



#endif // STOK_H
