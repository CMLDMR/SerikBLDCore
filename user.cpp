#include "user.h"

const std::string SerikBLDCore::User::Collection{"Personel"};
const std::string SerikBLDCore::User::Baskan{"Başkan"};
const std::string SerikBLDCore::User::BaskanYardimcisi{"Başkan Yardımcısı"};
const std::string SerikBLDCore::User::Mudur{"Müdür"};
const std::string SerikBLDCore::User::Sef{"Şef"};
const std::string SerikBLDCore::User::Personel{"Personel"};

SerikBLDCore::User::User() : Item (User::Collection) , DB()
{
}

SerikBLDCore::User::User(mongocxx::database *_db) : Item (User::Collection) , DB(_db)
{

}

SerikBLDCore::User::User(mongocxx::database *_db, bsoncxx::document::value _userValue) : Item(_userValue.view (),User::Collection) , DB(_db)
{
}

SerikBLDCore::User::User(User *_user) : Item(_user->view (),User::Collection) , DB(_user->db())
{
}

bool SerikBLDCore::User::Login(const std::string &_mTel, const std::string &_mPassword)
{
    this->append(this->KeyTel,_mTel);
    this->append(this->KeyPassword,_mPassword);


    try {
        auto val = this->findOneItem (*this);

        if( val )
        {
            this->setDocumentView (val.value ().view ());
            return true;
        }

    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
    }

    return false;
}

bsoncxx::document::value SerikBLDCore::User::Value() const
{
    return bsoncxx::document::value(this->view ());
}

std::string SerikBLDCore::User::PhotoFilePath()
{
    auto element = this->element (KeyFotoid);
    if( element )
    {
        auto url = this->downloadFile (element->get_oid ().value.to_string ().c_str ());
        return url;
    }else{
        return "";
    }
}

std::string SerikBLDCore::User::PhotoFilePathWeb()
{
    auto element = this->element (KeyFotoid);
    if( element )
    {
        auto url = this->downloadFileWeb (element->get_oid ().value.to_string ().c_str ());
        return url;
    }else{
        return "";
    }
}

std::string SerikBLDCore::User::AdSoyad()
{
    auto element = this->element (KeyAdSoyad);

    if( element )
    {
        return (element->get_utf8 ().value.to_string());
    }else{
        return (KeyAdSoyad + " Bilgisi Eksik");
    }
}

std::string SerikBLDCore::User::Statu()
{
    auto element = this->element (KeyStatu);

    if( element )
    {
        return  (element->get_utf8 ().value.to_string());
    }else{
        return (KeyStatu + " Bilgisi Eksik");
    }
}

std::string SerikBLDCore::User::Birimi()
{
    auto element = this->element (KeyBirimi);

    if( element )
    {
        return  (element->get_utf8 ().value.to_string());
    }else{
        return (KeyBirimi + " Bilgisi Eksik");
    }
}

std::string SerikBLDCore::User::Telefon() const
{
    auto element = this->element (KeyTel);

    if( element )
    {
        return  (element->get_utf8 ().value.to_string());
    }else{
        return ("");
    }
}

QString SerikBLDCore::User::UserOid() const
{
    auto element = this->element ("_id");
    if( element )
    {
        return  QString::fromStdString (element->get_oid ().value.to_string());
    }
    return ("Bilgisi Eksik");

}
