#include "user.h"

const std::string User::Collection{"Personel"};

User::User() : Item (User::Collection) , DB()
{

}

bool User::Login(const std::string &_mTel, const std::string &_mPassword)
{
    this->append(this->KeyTel,_mTel);
    this->append(this->KeyPassword,_mPassword);

    try {
        auto val = this->db ()->collection (Collection).find_one (this->view ());

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

std::string User::PhotoFilePath()
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

std::string User::AdSoyad()
{
    auto element = this->element (KeyAdSoyad);

    if( element )
    {
        return (element->get_utf8 ().value.to_string());
    }else{
        return (KeyAdSoyad + " Bilgisi Eksik");
    }
}

std::string User::Statu()
{
    auto element = this->element (KeyStatu);

    if( element )
    {
        return  (element->get_utf8 ().value.to_string());
    }else{
        return (KeyStatu + " Bilgisi Eksik");
    }
}

std::string User::Birimi()
{
    auto element = this->element (KeyBirimi);

    if( element )
    {
        return  (element->get_utf8 ().value.to_string());
    }else{
        return (KeyBirimi + " Bilgisi Eksik");
    }
}
