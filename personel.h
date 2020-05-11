#ifndef PERSONEL_H
#define PERSONEL_H


#include "item.h"
#include "SerikBLDCore_global.h"

namespace SerikBLDCore {

namespace IK {


namespace Statu {
static const std::string Baskan{"Başkan"};;
static const std::string BaskanYardimcisi{"Başkan Yardımcısı"};;
static const std::string Mudur{"Müdür"};;
static const std::string Sef{"Şef"};;
static const std::string Personel{"Personel"};;
}


class SERIKBLDCORE_EXPORT Personel : public Item
{
public:
    static const std::string CollectionHold;
    static const std::string Collection;
    static const std::string KeyAdSoyad;
    static const std::string KeyBuroPersonel;
    static const std::string KeyTelefon;
    static const std::string KeyStatu;
    static const std::string KeyBirimi;
    static const std::string KeyFotoOid;
    static const std::string KeyPassword;
    static const std::string KeyTCNO;
    static const std::string KeyMudurlukler;
    static const std::string KeyAltBirim;

public:
    explicit Personel();
    Personel( const Personel &other );
    Personel( Personel &&other );

    Personel& operator=(const Personel &other);
    Personel& operator=( Personel &&other);

    QString AdSoyad() const;
    bool BuroPersoneli() const;
    QString FotoOid() const;
    QString Birim() const;
    QString statu() const;
    QString telefon() const;
    QString sifre() const;
    QVector<bsoncxx::oid> mudurlukList() const;
    QVector<bsoncxx::oid> altBirimOidList() const;
    bool altBirimContains( const bsoncxx::oid& altBirimOid ) const;



    Personel& setAdSoyad( const QString &adsoyad );
    Personel& setBuroPersoneli( const bool &buro = true );
    Personel& setFotoOid( const QString &fotoOid );
    Personel& setBirim( const QString &birim );
    Personel& setStatu( const QString &statu );
    Personel& setTelefon( const QString &telefon );
    Personel& setSifre( const QString &sifre );
    Personel& addMudurluk( const QString &mudurlukOid );
    Personel& deleteMudurluk( const QString &mudurlukOid );
    Personel& addAltBirim( const QString &altBirimOid );




    bool static checkTelefonFormat( const QString& numara );


    virtual void errorOccured(const std::string &errorText) override;
};





namespace BirimKey {

static const std::string Collection{"Müdürlükler"};
static const std::string birim{"Birim"};

}


class SERIKBLDCORE_EXPORT BirimItem : public Item
{
public:
    explicit BirimItem();
    BirimItem( const BirimItem& other );
    BirimItem( BirimItem&& other );

    BirimItem& operator=( const BirimItem& other );
    BirimItem& operator=( BirimItem& other );

    BirimItem& setBirimAdi( const QString& birimAdi );

    QString birimAdi() const;

};


namespace AltBirimKey {
static const std::string Collection{"AltBirimler"};
static const std::string altBirimAdi{"adi"};
static const std::string birimOid{"birimOid"};
}


class SERIKBLDCORE_EXPORT AltBirimItem : public Item
{
public:
    explicit AltBirimItem();

    AltBirimItem& setName( const QString& birimName );
    AltBirimItem& setBirimOid( const bsoncxx::oid& birimOid );

    QString name() const;
    std::string birimOid() const;
};

}
}



#endif // PERSONEL_H
