#ifndef CALISMAITEM_H
#define CALISMAITEM_H

#include <item.h>

#include "Config.h"
#include "item.h"
#include "SerikBLDCore_global.h"

namespace SerikBLDCore {

namespace Calisma {


namespace Key{
static const std::string Collection{"CalismalarV2"};
static const std::string ay{"ay"};
static const std::string yil{"yil"};
static const std::string julianDate{"julianDate"};
static const std::string epochTime{"epoch"};
static const std::string birim{"birim"};
static const std::string mahalle{"mahalle"};
static const std::string aciklama{"aciklama"};
static const std::string unitBirim{"unitBirim"};
static const std::string calismaAdi{"calismaAdi"};
static const std::string images{"images"};
static const std::string miktar{"miktar"};
static const std::string isTipi{"isTipi"};
static const std::string isKategorisi{"isKategorisi"};
}

namespace KeyItem{
static const std::string Collection{"CalismaItemV2"};
//static const std::string ay{"ay"};
//static const std::string yil{"yil"};
//static const std::string julianDate{"julianDate"};
static const std::string epochTime{"epoch"};
}


class SERIKBLDCORE_EXPORT Calisma : public SerikBLDCore::Item
{
public:
    explicit Calisma();


    Calisma& setCalimaAdi( const std::string& calismaAdi );
    Calisma& setBirim( const std::string& birim );
    Calisma& setAciklama( const std::string &aciklama );
    Calisma& setMahalle( const std::string &mahalle );
    Calisma& setJulianDay(const int64_t &julianDay );
    Calisma& setisBirimi( const std::string& isBirimi );
    Calisma& setMiktar( const double& miktar );
    Calisma& addPhoto( const bsoncxx::oid& imgOid );
    Calisma& setIsTipi( const std::string& isTipi );
    Calisma& setIsKategorisi( const std::string& isKategorisi );


    std::string CalismaAdi() const;
    std::string Mahalle() const;
    std::string IsTipii() const;
    std::string IsBirim() const;
    std::string tarihText() const;
    std::int64_t julianDay() const;
    std::vector<bsoncxx::oid> imgOidList() const;
    std::string Aciklama() const;
    double Miktar() const;
    std::string isKategorisi() const;


    void errorOccured(const std::string &errorText) override;
};

namespace KategoriKey{
    static const std::string Collection{"CalismalarV2Kategori"};
    static const std::string kategoriAdi{"kategoriAdi"};
    static const std::string kategoriMudurluk{"mudurluk"};
    static const std::string kategoriBirim{"birim"};
}

class SERIKBLDCORE_EXPORT Kategori : public SerikBLDCore::Item
{
public:
    explicit Kategori();

    Kategori& setKategoriAdi( const std::string &kategoriName );
    std::string getKategoriAdi() const;

    Kategori& setKategoriMudurluk( const std::string &mudurluk);
    std::string getKategoriMudurluk() const;

    Kategori& setKategoriBirim( const std::string &birim);
    std::string getKategoriBirimi() const;
};



}








} // namespace Calisma




#endif // CALISMAITEM_H
