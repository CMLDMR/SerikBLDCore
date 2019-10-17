#ifndef USER_H
#define USER_H

#include "item.h"
#include "db.h"

class SERIKBLDCORE_EXPORT User : public Item , public DB
{
    const std::string Collection{"Personel"};
    const std::string KeyTel = "telefon";
    const std::string KeyPassword = "password";
    const std::string KeyAdSoyad{"ad soyad"};
    const std::string KeyStatu{"Statü"};
    const std::string KeyBirimi{"Birimi"};
    const std::string KeyFotoid{"fotooid"};
public:
    User();

    bool Login( const std::string &_mTel , const std::string &_mPassword);

    std::string PhotoFilePath();
    std::string AdSoyad();
    std::string Statu();
    std::string Birimi();
};

#endif // USER_H
