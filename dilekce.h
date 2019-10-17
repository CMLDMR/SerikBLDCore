#ifndef DILEKCE_H
#define DILEKCE_H

#include <QtGlobal>
#include "item.h"
#include "db.h"
#include <QString>
#include "SerikBLDCore_global.h"



class SERIKBLDCORE_EXPORT Dilekce : public Item , public DB
{
    static const std::string Collection;
    const std::string KeySayi{"Sayı"};
    const std::string KeyKonu{"Konu"};
    const std::string KeyTCOid{"TCOid"};
    const std::string KeyBirim{"Birim"};
    const std::string KeyIcerikTipi{"IcerikTipi"};
    const std::string KeyIcerik{"Icerik"};
    const std::string KeyDilekceOid{"dilekceOid"};
    const std::string KeyEkler{"Ekler"};
    const std::string KeyTarihJulian{"TarihJulian"};
    const std::string KeySaat{"Saat"};
public:
    explicit Dilekce(Dilekce* other = nullptr);


    static boost::optional<Dilekce*> Create_Dilekce();

    void SetSayi( const int &sayi );
    void SetKonu( const QString &konu);
    void SetTCOid( const QString &oid);
    void SetBirim( const QString &birim);
    void SetIcerikTipi(const QString &icerikTipi);
    void SetIcerik( const QString &icerik);
    void SetDilekceOid( const QString &dilekceOid);
    void AddEkOid( const QString &ekOid );
    void SetTarih( const int &julianDay );
    void SetSaat( const int &mSecsFromBeginDay );

    int sayi();


    bool Update();

private:

};

#endif // DILEKCE_H
