#include "tc.h"
#include <QRandomGenerator>

const std::string SerikBLDCore::TC::Collection = "TC";
const std::string SerikBLDCore::TC::KeyTC{"TCNO"};
const std::string SerikBLDCore::TC::KeyAdSoyad{"İsimSoyisim"};
const std::string SerikBLDCore::TC::KeyCepTelefonu{"Cep Telefonu"};
const std::string SerikBLDCore::TC::KeyNormalTelefon{"Normal Telefonu"};
const std::string SerikBLDCore::TC::KeyMahalle{"Mahalle"};
const std::string SerikBLDCore::TC::KeyAdres{"Tam Adres"};
const std::string SerikBLDCore::TC::KeyPassword{"password"};
const std::string SerikBLDCore::TC::KeyCalismaSMS{"CalismaSMS"};
const std::string SerikBLDCore::TC::KeyOid{"_id"};

SerikBLDCore::TC::TC(TC *other) : Item(TC::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

SerikBLDCore::TC::TC(bsoncxx::document::value *mValue) : Item(TC::Collection)
{
    if( mValue )
    {
        this->setDocumentView (mValue->view ());
    }
}

SerikBLDCore::TC::TC(const TC &other) : Item(TC::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::TC::TC(TC &&other) : Item(TC::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::TC &SerikBLDCore::TC::operator=(const bsoncxx::document::value &value)
{
    this->setDocumentView (value.view ());
    return *this;
}

SerikBLDCore::TC &SerikBLDCore::TC::operator=(bsoncxx::document::value *value)
{
    this->setDocumentView (value->view ());
    return *this;
}



SerikBLDCore::TC &SerikBLDCore::TC::operator=(const bsoncxx::document::view &view)
{
    setDocumentView (view);
    return *this;
}

SerikBLDCore::TC &SerikBLDCore::TC::operator=(const SerikBLDCore::TC &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::TC &SerikBLDCore::TC::operator=(SerikBLDCore::TC &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::TC &SerikBLDCore::TC::setTCNO(const QString &tcno)
{
    this->append(KeyTC,tcno.toStdString ());
    return *this;
}

SerikBLDCore::TC& SerikBLDCore::TC::setAdSoyad(const QString &adsoyad)
{
    this->append(KeyAdSoyad,adsoyad.toStdString ());
    return *this;
}

SerikBLDCore::TC& SerikBLDCore::TC::setCepTelefonu(const QString &cepTelefonu)
{
    this->append(KeyCepTelefonu,cepTelefonu.toStdString ());
    return *this;
}

SerikBLDCore::TC& SerikBLDCore::TC::setMahalle(const QString &mahalle)
{
    this->append(KeyMahalle,mahalle.toStdString ());
    return *this;
}

SerikBLDCore::TC& SerikBLDCore::TC::setTamAdress(const QString &adres)
{
    this->append(KeyAdres,adres.toStdString ());
    return *this;
}

SerikBLDCore::TC& SerikBLDCore::TC::setPassword(const QString &password)
{
    if( password == "" )
    {
        auto _password = QString::number (1234+(QRandomGenerator::global ()->generate ()%10000));
        this->append(KeyPassword,_password.toStdString ());
    }else{
        this->append(KeyPassword,password.toStdString ());
    }
    return *this;
}

SerikBLDCore::TC& SerikBLDCore::TC::setNormalTelefon(const QString &normalTelefon)
{
    this->append(KeyNormalTelefon,normalTelefon.toStdString ());
    return *this;
}

SerikBLDCore::TC& SerikBLDCore::TC::setCalismaSMS(const bool &smsgitsin)
{
    this->append(KeyCalismaSMS,smsgitsin);
    return *this;
}

QString SerikBLDCore::TC::TCNO()
{
    auto value = this->element (KeyTC);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::AdSoyad()
{
    auto value = this->element (KeyAdSoyad);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::CepTelefonu()
{
    auto value = this->element (KeyCepTelefonu);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::Mahalle()
{
    auto value = this->element (KeyMahalle);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::TamAdres()
{
    auto value = this->element (KeyAdres);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::Password()
{
    auto value = this->element (KeyPassword);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::NormalTelefon()
{
    auto value = this->element (KeyNormalTelefon);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

bool SerikBLDCore::TC::CalismaSMS()
{
    auto value = this->element (KeyCalismaSMS);
    if( value )
    {
        return value->get_bool ().value;
    }else{
        return false;
    }
}

