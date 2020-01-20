#ifndef STOK_H
#define STOK_H

#include "item.h"


//TODO: Stok Modulu Tüm Birimlerin Kullanabileceği Şekilde Yapılacaktır.

namespace SerikBLDCore {


namespace Stok {


namespace StokKey {
static const std::string Collection{"Stok"};
static const std::string mudurluk{"mudurluk"};
static const std::string kategori{"kategori"};
static const std::string adi{"adi"};
static const std::string kodu{"kodu"};
static const std::string miktar{"miktar"};
}
class SERIKBLDCORE_EXPORT Stok : private SerikBLDCore::Item
{
public:
    explicit Stok( const std::string& mudurluk );
    Stok( const Stok& other );
    Stok( Stok&& other );
    Stok& operator=( const Stok& other );
    Stok& operator=( Stok&& other );

    Stok& setKategori( const bsoncxx::oid& kategoriOid );
    Stok& setAdi( const std::string& adi );
    Stok& setKodu( const bsoncxx::oid& kodOid );
    Stok& setMiktar( const std::int64_t& miktar );


    boost::optional<bsoncxx::oid> kategori() const;
    std::string adi() const;
    boost::optional<bsoncxx::oid> kodu() const;
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

    std::string adi() const;
    std::string birim() const;
};

}





}



#endif // STOK_H
