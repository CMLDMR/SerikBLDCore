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
const std::string SerikBLDCore::TC::KeyFotoOid{"fotoOid"};

SerikBLDCore::TC::TC(TC *other) : Item(TC::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

SerikBLDCore::TC::TC(const SerikBLDCore::TC *other) : Item(TC::Collection)
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

SerikBLDCore::TC::TC(const std::string &newCollection)
    :Item(newCollection)
{

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

SerikBLDCore::TC &SerikBLDCore::TC::setFotoOid(const QString &oid)
{
    this->append(KeyFotoOid,bsoncxx::oid{oid.toStdString ()});
    return *this;
}

QString SerikBLDCore::TC::TCNO()const
{
    auto value = this->element (KeyTC);
    if( value )
    {
#ifndef CPP17
        return QString::fromStdString (value->get_string ().value.to_string());
#endif
#ifdef CPP17
        return QString::fromStdString (value->view().get_string ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::AdSoyad()const
{
    auto value = this->element (KeyAdSoyad);
    if( value )
    {
#ifndef CPP17
        return QString::fromStdString (value->get_string ().value.to_string());
#endif
#ifdef CPP17
        return QString::fromStdString (value->view().get_string ().value.data ());
#endif

    }else{
        return "";
    }
}

QString SerikBLDCore::TC::CepTelefonu()const
{
    auto value = this->element (KeyCepTelefonu);
    if( value )
    {
#ifndef CPP17
        return QString::fromStdString (value->get_string ().value.to_string());
#endif
#ifdef CPP17
        return QString::fromStdString (value->view().get_string ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::Mahalle()const
{
    auto value = this->element (KeyMahalle);
    if( value )
    {
#ifndef CPP17
        return QString::fromStdString (value->get_string ().value.to_string());
#endif
#ifdef CPP17
        return QString::fromStdString (value->view().get_string ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::TamAdres()const
{
    auto value = this->element (KeyAdres);
    if( value )
    {
#ifndef CPP17
        return QString::fromStdString (value->view().get_string ().value.to_string());
#endif
#ifdef CPP17
        return QString::fromStdString (value->view().get_string ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::Password()const
{
    auto value = this->element (KeyPassword);
    if( value )
    {
#ifndef CPP17
        return QString::fromStdString (value->get_string ().value.to_string());
#endif
#ifdef CPP17
        return QString::fromStdString (value->view().get_string ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::NormalTelefon()const
{
    auto value = this->element (KeyNormalTelefon);
    if( value )
    {
#ifndef CPP17
        return QString::fromStdString (value->get_string ().value.to_string());
#endif
#ifdef CPP17
        return QString::fromStdString (value->view().get_string ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::TC::FotoOid() const
{
    auto val = this->element (KeyFotoOid);
    if( val )
    {
        return QString::fromStdString (val->view().get_oid ().value.to_string ());
    }
    return "";
}

bool SerikBLDCore::TC::CalismaSMS()const
{
    auto value = this->element (KeyCalismaSMS);
    if( value )
    {
        return value->view().get_bool ().value;
    }else{
        return false;
    }
}

