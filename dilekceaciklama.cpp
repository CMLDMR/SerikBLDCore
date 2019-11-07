#include "dilekceaciklama.h"
#include <QDate>

const std::string DilekceAciklama::Collection{"DilekceAciklama"};

DilekceAciklama::DilekceAciklama(DilekceAciklama *other) : Item (DilekceAciklama::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

DilekceAciklama::DilekceAciklama(const DilekceAciklama &other) : Item (DilekceAciklama::Collection)
{
    this->setDocumentView (other.view ());
}

DilekceAciklama::DilekceAciklama(DilekceAciklama &&other) : Item (DilekceAciklama::Collection)
{
    this->setDocumentView (other.view ());
}

DilekceAciklama &DilekceAciklama::operator=(const DilekceAciklama &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

DilekceAciklama &DilekceAciklama::operator=(DilekceAciklama &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

void DilekceAciklama::setDilekceOid(const std::string &dilekceOid)
{
    this->append( KeydilekceOid,bsoncxx::oid{dilekceOid});
}

void DilekceAciklama::setAciklama(const std::string &aciklama)
{
    this->append(Keyaciklama,aciklama);
}

void DilekceAciklama::setPersonelOid(const std::string &personelOid)
{
    this->append(KeypersonelOid,bsoncxx::oid{personelOid});
}

void DilekceAciklama::setPersonelName(const std::string &adSoyad)
{
    this->append(KeyPersonelName,adSoyad);
}

void DilekceAciklama::setGorunur(const bool &gorunur)
{
    this->append(KeyGorunur,gorunur);
}

void DilekceAciklama::setJulianDay(const int &julianDay)
{
    this->append(JulianDay,julianDay);
}

void DilekceAciklama::setSaat(const std::string &saat)
{
    this->append(KeySaat,saat);
}

QString DilekceAciklama::PersonelOid() const
{
    auto val = this->element (KeypersonelOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

QString DilekceAciklama::Aciklama() const
{
    auto val = this->element (Keyaciklama);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }else{
        return "";
    }
}

QString DilekceAciklama::DilekceOid() const
{
    auto val = this->element (KeydilekceOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

bool DilekceAciklama::Gorunur() const
{
    auto val = this->element (KeyGorunur);
    if( val )
    {
        return val.value ().get_bool ().value;
    }else{
        return false;
    }
}

QString DilekceAciklama::Tarih() const
{
    auto val = this->element (JulianDay);
    if( val )
    {
        return QDate::fromJulianDay (val.value ().get_int32 ().value).toString ("dd/MM/yyyy");
    }else{
        return "";
    }
}

QString DilekceAciklama::PersonelName() const
{
    auto val = this->element (KeyPersonelName);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }else{
        return "";
    }
}

QString DilekceAciklama::Saat() const
{
    auto val = this->element (KeySaat);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }else{
        return "";
    }}

DilekceAciklama::operator bool() const
{
    return !this->view ().empty ();
}
