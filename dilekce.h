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
    const std::string KeyIcerik{"Icerik"};
    const std::string KeyTarihJulian{"TarihJulian"};
    const std::string KeySaat{"Saat"};
    const std::string KeyTCOid{"TCOid"};
    const std::string KeyBirim{"Birim"};
public:
    explicit Dilekce(DB* _db);

    static boost::optional<Dilekce*> Create_Dilekce(DB* _db);

    void SetSayi( const int &sayi );

    bool Update();
};

#endif // DILEKCE_H
