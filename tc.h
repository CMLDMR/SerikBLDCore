#ifndef TC_H
#define TC_H

#include <QtGlobal>
#include "item.h"
#include "db.h"
#include <QString>
#include "SerikBLDCore_global.h"

class SERIKBLDCORE_EXPORT TC : public Item /*, public DB*/
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

    void setTCNO( const QString &tcno );
    void setAdSoyad( const QString &adsoyad );
    void setCepTelefonu( const QString &cepTelefonu );
    void setMahalle( const QString &mahalle );
    void setTamAdress( const QString &adres );
    void setPassword( const QString &password = QString("") );
    void setNormalTelefon( const QString &normalTelefon );
    void setCalismaSMS( const bool &smsgitsin = false );

    QString TCNO();
    QString AdSoyad();
    QString CepTelefonu();
    QString Mahalle();
    QString TamAdres();
    QString Password();
    QString NormalTelefon();
    bool    CalismaSMS();

//    bool LoadTC();
};

#endif // TC_H
