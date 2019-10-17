#ifndef DILEKCE_H
#define DILEKCE_H

#include <QtGlobal>
#include "item.h"
#include "db.h"

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
    explicit Dilekce();
    Dilekce(Dilekce* other);


    static boost::optional<Dilekce*> Create_Dilekce();

    void SetSayi( const int &sayi );
    void SetKonu( const std::string &konu);
    void SetTCOid( const std::string &oid);
    void SetBirim( const std::string &birim);
    void SetIcerikTipi( const std::string &icerikTipi);
    void SetIcerik( const std::string &icerik);
    void SetDilekceOid( const std::string &dilekceOid);
    void AddEkOid( const std::string &ekOid );
    void SetTarih( const int &julianDay );
    void SetSaat( const int &mSecsFromBeginDay );

    int sayi();

    bool Update();

private:

};

#endif // DILEKCE_H
