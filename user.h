#ifndef USER_H
#define USER_H

#include "item.h"
#include "personelmanager.h"

//#define WT_CLASS "4.1.0"
#ifdef WT_CLASS
#endif

namespace SerikBLDCore {

class SERIKBLDCORE_EXPORT User : public Item , public DB
{
public:
    static const std::string Collection;
    const std::string KeyTel = "telefon";
    const std::string KeyPassword = "password";
    const std::string KeyAdSoyad{"ad soyad"};
    const std::string KeyStatu{"Statü"};
    const std::string KeyBirimi{"Birimi"};
    const std::string KeyFotoid{"fotooid"};
    const std::string KeyMudurlukler{"Müdürlükler"};

    static const std::string Baskan;
    static const std::string BaskanYardimcisi;
    static const std::string Mudur;
    static const std::string Sef;
    static const std::string Personel;

public:
    explicit User();


    explicit User(mongocxx::database* _db );
    User(mongocxx::database* _db , bsoncxx::document::value _userValue );
    explicit User( User* _user);


    bool Login( const std::string &_mTel , const std::string &_mPassword);


    bsoncxx::document::value Value() const;

    std::string PhotoFilePath();
    std::string PhotoFilePathWeb();
    std::string AdSoyad();
    std::string Statu();
    std::string Birimi();
    std::string Telefon() const;
    QString UserOid() const;

    User& setWorkingBirim( const QString& birim );

    QVector<bsoncxx::oid> mudurlukList() const;

private:
    SerikBLDCore::BirimManager* mBirimManager;

};

}

#endif // USER_H
