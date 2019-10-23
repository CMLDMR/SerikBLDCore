#include "tc.h"
#include <QRandomGenerator>

const std::string TC::Collection = "TC";
const std::string TC::KeyTC{"TCNO"};
const std::string TC::KeyAdSoyad{"İsimSoyisim"};
const std::string TC::KeyCepTelefonu{"Cep Telefonu"};
const std::string TC::KeyNormalTelefon{"Normal Telefonu"};
const std::string TC::KeyMahalle{"Mahalle"};
const std::string TC::KeyAdres{"Tam Adres"};
const std::string TC::KeyPassword{"password"};
const std::string TC::KeyCalismaSMS{"CalismaSMS"};
const std::string TC::KeyOid{"_id"};

TC::TC(TC *other) : Item(TC::Collection) /*, DB()*/
{

    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

TC::TC(const TC &other) : Item(TC::Collection)
{
    this->setDocumentView (other.view ());
}

TC::TC(const TC &&other) : Item(TC::Collection)
{
    this->setDocumentView (other.view ());
}

TC *TC::operator=(const bsoncxx::document::value &value)
{
    this->setDocumentView (value.view ());
    return this;
}

void TC::setTCNO(const QString &tcno)
{
    this->append(KeyTC,tcno.toStdString ());
}

void TC::setAdSoyad(const QString &adsoyad)
{
    this->append(KeyAdSoyad,adsoyad.toStdString ());
}

void TC::setCepTelefonu(const QString &cepTelefonu)
{
    this->append(KeyCepTelefonu,cepTelefonu.toStdString ());

}

void TC::setMahalle(const QString &mahalle)
{
    this->append(KeyMahalle,mahalle.toStdString ());

}

void TC::setTamAdress(const QString &adres)
{
    this->append(KeyAdres,adres.toStdString ());

}

void TC::setPassword(const QString &password)
{
    if( password == "" )
    {
        auto _password = QString::number (1234+(QRandomGenerator::global ()->generate ()%10000));
        this->append(KeyPassword,_password.toStdString ());
    }else{
        this->append(KeyPassword,password.toStdString ());
    }

}

void TC::setNormalTelefon(const QString &normalTelefon)
{
    this->append(KeyNormalTelefon,normalTelefon.toStdString ());
}

void TC::setCalismaSMS(const bool &smsgitsin)
{
    this->append(KeyCalismaSMS,smsgitsin);

}

QString TC::TCNO()
{
    auto value = this->element (KeyTC);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString TC::AdSoyad()
{
    auto value = this->element (KeyAdSoyad);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString TC::CepTelefonu()
{
    auto value = this->element (KeyCepTelefonu);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString TC::Mahalle()
{
    auto value = this->element (KeyMahalle);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString TC::TamAdres()
{
    auto value = this->element (KeyAdres);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString TC::Password()
{
    auto value = this->element (KeyPassword);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString TC::NormalTelefon()
{
    auto value = this->element (KeyNormalTelefon);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

bool TC::CalismaSMS()
{
    auto value = this->element (KeyCalismaSMS);
    if( value )
    {
        return value->get_bool ().value;
    }else{
        return false;
    }
}

//bool TC::LoadTC()
//{
//    auto val = this->findOneItem (*this);

//    if( val )
//    {
//        this->setDocumentView (val.value ().view ());
//        return true;
//    }

//    return false;


//}
