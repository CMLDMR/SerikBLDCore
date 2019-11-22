#ifndef TC_H
#define TC_H

#include <QtGlobal>
#include "item.h"
#include "db.h"
#include <QString>
#include "SerikBLDCore_global.h"

//SRKBLDCore__

namespace SerikBLDCore {

class SERIKBLDCORE_EXPORT TC : public Item
{
public:
    static const std::string Collection;
    static const std::string KeyTC;
    static const std::string KeyAdSoyad;
    static const std::string KeyCepTelefonu;
    static const std::string KeyNormalTelefon;
    static const std::string KeyMahalle;
    static const std::string KeyAdres;
    static const std::string KeyPassword;
    static const std::string KeyCalismaSMS;
    static const std::string KeyOid;

public:
    TC(TC* other = nullptr );
    TC( bsoncxx::document::value* mValue );
    TC( const TC &other );
    TC( TC &&other);

    TC& operator=(const bsoncxx::document::value &value);
    TC& operator=( bsoncxx::document::value *value );
    TC& operator=( const bsoncxx::document::view &view );



    TC& operator=( const TC& other );
    TC& operator=( TC&& other );


    TC& setTCNO( const QString &tcno );
    TC& setAdSoyad( const QString &adsoyad );
    TC& setCepTelefonu( const QString &cepTelefonu );
    TC& setMahalle( const QString &mahalle );
    TC& setTamAdress( const QString &adres );
    TC& setPassword( const QString &password = QString("") );
    TC& setNormalTelefon( const QString &normalTelefon );
    TC& setCalismaSMS( const bool &smsgitsin = false );

    QString TCNO() const;
    QString AdSoyad() const;
    QString CepTelefonu() const;
    QString Mahalle() const;
    QString TamAdres() const;
    QString Password() const;
    QString NormalTelefon() const ;

    ///
    /// \brief Çalışmalarla ilgili Vatandaşa SMS Gidip Gitmeyeceğini Belirler
    /// \return Eğer Gönderilecekse <b>true</b> yoksa <b>false</b> Döndürür.
    ///
    bool    CalismaSMS() const;

};

}


#endif // TC_H
