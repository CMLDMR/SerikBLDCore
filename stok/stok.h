#ifndef STOK_H
#define STOK_H

#include "item.h"


//TODO: Stok Modulu Tüm Birimlerin Kullanabileceği Şekilde Yapılacaktır.

namespace SerikBLDCore {


namespace Stok {


namespace StokKey {
inline const std::string Collection{"StokGiris"};
inline const std::string CollectionCikis{"StokCikis"};
inline const std::string mudurluk{"mudurluk"};
inline const std::string kategori{"kategori"};
inline const std::string adi{"adi"};
inline const std::string kodu{"kodu"};
inline const std::string miktar{"miktar"};
inline const std::string giris{"giris"};
inline const std::string tcoid{"tcoid"};
inline const std::string teslimAlan{"teslimAlan"};
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

#ifndef CPP17
    boost::optional<bsoncxx::oid> kategori() const;
    boost::optional<bsoncxx::oid> kodu() const;
    boost::optional<bsoncxx::oid> tcoid() const;

#endif
#ifdef CPP17
    std::optional<bsoncxx::oid> kategori() const;
    std::optional<bsoncxx::oid> kodu() const;
    std::optional<bsoncxx::oid> tcoid() const;
#endif

    std::string adi() const;
    std::int64_t miktar() const;


};





namespace StokKategoriKey {
inline const std::string Collection{"stokyardimKat"};
inline const std::string kategoriName{"kategori"};
inline const std::string mudurluk{"mudurluk"};
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
inline const std::string Collection{"stokKod"};
inline const std::string adi{"adi"};
inline const std::string birimi{"birimi"};
inline const std::string kategoriOid{"kategoriOid"};
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



#ifndef CPP17
        boost::optional<bsoncxx::oid> kategoriOid() const;
#endif
#ifdef CPP17
        std::optional<bsoncxx::oid> kategoriOid() const;
#endif

};

}





}



#endif // STOK_H
