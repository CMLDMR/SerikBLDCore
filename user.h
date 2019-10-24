#ifndef USER_H
#define USER_H

#include "item.h"
#include "db.h"

//#define WT_CLASS "4.1.0"
#ifdef WT_CLASS
#endif


class SERIKBLDCORE_EXPORT User : public Item , public DB
{
    static const std::string Collection;
    const std::string KeyTel = "telefon";
    const std::string KeyPassword = "password";
    const std::string KeyAdSoyad{"ad soyad"};
    const std::string KeyStatu{"Statü"};
    const std::string KeyBirimi{"Birimi"};
    const std::string KeyFotoid{"fotooid"};

public:
    static const std::string Baskan;
    static const std::string BaskanYardimcisi;
    static const std::string Mudur;
    static const std::string Sef;
    static const std::string Personel;

public:
    explicit User();


    User(mongocxx::database* _db );
    User(mongocxx::database* _db , bsoncxx::document::value _userValue );
    User( User* _user);


    bool Login( const std::string &_mTel , const std::string &_mPassword);


    bsoncxx::document::value Value() const;

    std::string PhotoFilePath();
    std::string AdSoyad();
    std::string Statu() const;
    std::string Birimi();

};

#endif // USER_H
