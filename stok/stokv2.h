#ifndef STOKV2_H
#define STOKV2_H

#include "item.h"


namespace SerikBLDCore{



namespace Stokv2 {


namespace Key {
static const std::string Collection{"Stokv2"};
static const std::string kategoriOid{"kategoriOid"};
static const std::string malzemeAdi{"malzemeAdi"};
static const std::string metric{"metric"};
static const std::string mudurluk{"mudurluk"};
static const std::string miktar{"miktar"};
static const std::string teslimOid{"teslimOid"};
static const std::string teslimAlimJulianDay{"teslimAlimJulianDay"};
static const std::string teslimEtJulianDay{"teslimEtJulianDay"};
static const std::string teslimEdilenPersonelOid{"teslimEdilenPersonelOid"};
static const std::string teslimEdilenPersonelAdSoyad{"teslimEdilenPersonelAdSoyad"};
static const std::string cikisAciklamasi{"cikisAciklamasi"};
static const std::string birimFiyati{"birimFiyati"};
static const std::string calismaOid{"calismaOid"}; // TODO:  Malzeme Çıkışı Çalışmalara Bağlanacak.
}


class Giris;
class Cikis;

class SERIKBLDCORE_EXPORT Stok : public SerikBLDCore::Item
{
public:
    explicit Stok();
//    Stok( const Stok &other );
//    Stok( Stok &&other );

//    Stok& operator=( const Stok& other );
//    Stok& operator=( Stok&& other );

    Stok& setBirimBirim( const double &fiyat);
    double getBirimFiyat() const;

    Stok& setMiktar( const double &miktar);
    double getMiktar() const;

    Stok& setKategoriOid( const std::string &kategoriOid );
    std::string getKategoriOid() const;

    Stok& setMalzemeAdi( const std::string &malzemeAdi );
    std::string getMalzemeAdi() const;

    Stok& setMudurluk( const std::string &mudurluk );
    std::string getMudurluk() const;

    Stok& setMetric( const std::string &metric );
    std::string getMetric() const;

    Stok& setTeslimOid( const std::string &teslimOid );
    std::string getTeslimOid() const;


    ///
    /// \brief toGiris : eğer Stok, Giris item ise return yapar yoksa boost::none
    /// \return
    ///
    boost::optional<Giris> toGiris();

    ///
    /// \brief toCikis : eğer Stok, Cikis item ise return yapar yoksa boost::none
    /// \return
    ///
    boost::optional<Cikis> toCikis();

};



class SERIKBLDCORE_EXPORT Giris : public Stok
{
public:
    explicit Giris();
    explicit Giris( const Stok& stok );
    Giris( const Giris &other );
    Giris( Giris &&other);

    Giris& operator=( const Giris &other );
    Giris& operator=( Giris &&other );

    Giris &setTeslimAlimJulianDay( const std::int64_t &julianDay );
    std::int64_t getTeslimAlimJulianDay() const;




};



class SERIKBLDCORE_EXPORT Cikis : public Stok
{
public:
    explicit Cikis();
    explicit Cikis( const Stok& stok );
    Cikis( const Cikis &other );
    Cikis( Cikis &&other);

    Cikis& operator=( const Cikis &other );
    Cikis& operator=( Cikis &&other );

    Cikis& setTeslimEtJulianDay( const std::int64_t& julianDay );
    std::int64_t getTeslimEtJulianDay() const;


    Cikis& setTeslimAlanPersonel( const std::string& personelOid , const std::string &personelAdSoyad );
    std::string getPersonelOid() const;
    std::string getPersonelAdSoyad() const;

    Cikis& setAciklama( const std::string& aciklama);
    std::string getAciklama() const;


};



namespace KeyKategori {
static const std::string Collection{"stokv2Kategori"};
static const std::string kategoriAdi{"kategoriAdi"};
static const std::string birim{"birim"};
static const std::string metric{"metric"};
}


class SERIKBLDCORE_EXPORT Kategori : public SerikBLDCore::Item
{
public:
    explicit Kategori();

    Kategori& setKategoriAdi( const std::string &kategoriAdi);
    std::string getKategoriAdi() const;


    Kategori& setBirim( const std::string &Birim );
    std::string getBirim() const;

    Kategori& setMetric( const std::string &metric );
    std::string getMetric() const;
};



}



}




#endif // STOKV2_H
