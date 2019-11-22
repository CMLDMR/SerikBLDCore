#ifndef TALEP_H
#define TALEP_H

#include "Config.h"
#include "item.h"
#include "SerikBLDCore_global.h"
#include "personel.h"

namespace SerikBLDCore {



///
/// \brief The TalepKey class: Talep Durumu , Talep Keyleri ve Kaynak Keylerini İçerir
///
class SERIKBLDCORE_EXPORT TalepKey
{
public:
    static const std::string Collection;
    static const std::string TCOID;
    static const std::string Mahalle;
    static const std::string Adres;
    static const std::string Konu;
    static const std::string SecStartOfDay;
    static const std::string JulianDay;
    static const std::string Birim;
    static const std::string Durum;
    static const std::string Kaynak;
    static const std::string GorevliPersonel;
    static const std::string Yil;
    static const std::string Ay;
    static const std::string FotoOid;
    static const std::string KisiGizle;


    class SERIKBLDCORE_EXPORT DurumKey
    {
    public:
        static const std::string DevamEdiyor;
        static const std::string Tamamlandi;
        static const std::string TeyitEdilmemis;
        static const std::string Beklemede;
        static const std::string RedEdildi;
    };

    class SERIKBLDCORE_EXPORT KaynakKey
    {
    public:
        static const std::string Sms;
        static const std::string Beyazmasa;
        static const std::string Telefon;
        static const std::string Web;
        static const std::string Mobil;
        static const std::string SosyalMedya;
    };

    struct DurumPipelineResult
    {
        int DevamEdiyor;
        int Tamamlandi;
        int RedEdildi;
        int Beklemede;
        int TeyitEdilmemis;
    };

    struct KaynakPipelineResult
    {
        int Sms;
        int Beyazmasa;
        int Telefon;
        int Web;
        int Mobil;
        int SosyalMedya;
    };



};


class SERIKBLDCORE_EXPORT Talep : public Item
{
public:
    Talep(Talep* other = nullptr );
    Talep( const Talep& other );
    Talep( Talep&& other );

    Talep& operator=( const Talep& other );
    Talep& operator=( Talep&& other );

    operator bool() const;

    Talep& setTCOID( const QString &tcoid );
    Talep& setMahalle( const QString &mahalle );
    Talep& setAddress( const QString &address );
    Talep& setKonu( const QString &konu );
    Talep& setSec( const int &mSecStartOfDay );
    Talep& setJulianDay( const int &julianDay );
    Talep& setDurum( const QString &durum );
    Talep& setKaynak( const QString &kaynak );
    Talep& setBirim( const QString &birim );
    Talep& AddGorevliPersonel(const Personel &personel );
    Talep& DeleteGorevliPersonel( const Personel &personel );
    Talep& setYil( const int& yil );
    Talep& setAy( const QString& ay );
    Talep& setFoto( const QString& fotooid );
    Talep& setKisiGizle( const bool& gizle );

    QString oid() const;
    QString tcOid() const;
    QString mahalle() const;
    QString adres() const;
    QString konu() const;
    QString saat() const;
    QString tarih() const;
    int julianDay() const;
    int mSecStartOfDay() const;
    QString durum() const;
    QString durumColor() const;
    QString kaynak() const;
    QString kaynakColor() const;
    QString birim() const;
    QVector<Personel> GorevliList() const;
    QString fotoOid() const;
    bool kisiGizli() const;


};


}







#endif // TALEPITEM_H
