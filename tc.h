#ifndef TC_H
#define TC_H

#include <QtGlobal>
#include "item.h"
#include "db.h"
#include <QString>
#include "SerikBLDCore_global.h"

class SERIKBLDCORE_EXPORT TC : public Item , public DB
{
    static const std::string Collection;
    const std::string KeyTC{"TCNO"};
    const std::string KeyAdSoyad{"İsimSoyisim"};
    const std::string KeyCepTelefonu{"Cep Telefonu"};
    const std::string KeyNormalTelefon{"Normal Telefonu"};
    const std::string KeyMahalle{"Mahalle"};
    const std::string KeyAdres{"Tam Adres"};
    const std::string KeyPassword{"password"};
    const std::string KeyCalismaSMS{"CalismaSMS"};
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
};

#endif // TC_H
