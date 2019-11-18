#ifndef PERSONEL_H
#define PERSONEL_H


#include "item.h"
#include "SerikBLDCore_global.h"

namespace SerikBLDCore {

class SERIKBLDCORE_EXPORT Personel : public Item
{
    static const std::string Collection;
    const std::string KeyAdSoyad{"ad soyad"};
    const std::string KeyBuroPersonel{"Büro Personeli"};
    const std::string KeyTelefon{"telefon"};
    const std::string KeyStatu{"Statü"};
    const std::string KeyBirimi{"Birimi"};
    const std::string KeyFotoOid{"fotooid"};
    const std::string KeyPassword{"password"};
    const std::string KeyTCNO{"tcno"};
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




    void setAdSoyad( const QString &adsoyad );
    void setBuroPersoneli( const bool &buro = true );
    void setFotoOid( const QString &fotoOid );
    void setBirim( const QString &birim );
};

}



#endif // PERSONEL_H
