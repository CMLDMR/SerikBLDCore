#include "dilekceaciklama.h"
#include <QDate>

const std::string SerikBLDCore::DilekceAciklama::Collection{"DilekceAciklama"};

SerikBLDCore::DilekceAciklama::DilekceAciklama(DilekceAciklama *other) : Item (DilekceAciklama::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

SerikBLDCore::DilekceAciklama::DilekceAciklama(const DilekceAciklama &other) : Item (DilekceAciklama::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::DilekceAciklama::DilekceAciklama(DilekceAciklama &&other) : Item (DilekceAciklama::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::DilekceAciklama &SerikBLDCore::DilekceAciklama::operator=(const DilekceAciklama &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::DilekceAciklama &SerikBLDCore::DilekceAciklama::operator=(DilekceAciklama &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

void SerikBLDCore::DilekceAciklama::setDilekceOid(const std::string &dilekceOid)
{
    this->append( KeydilekceOid,bsoncxx::oid{dilekceOid});
}

void SerikBLDCore::DilekceAciklama::setAciklama(const std::string &aciklama)
{
    this->append(Keyaciklama,aciklama);
}

void SerikBLDCore::DilekceAciklama::setPersonelOid(const std::string &personelOid)
{
    this->append(KeypersonelOid,bsoncxx::oid{personelOid});
}

void SerikBLDCore::DilekceAciklama::setPersonelName(const std::string &adSoyad)
{
    this->append(KeyPersonelName,adSoyad);
}

void SerikBLDCore::DilekceAciklama::setGorunur(const bool &gorunur)
{
    this->append(KeyGorunur,gorunur);
}

void SerikBLDCore::DilekceAciklama::setJulianDay(const int &julianDay)
{
    this->append(JulianDay,julianDay);
}

void SerikBLDCore::DilekceAciklama::setSaat(const std::string &saat)
{
    this->append(KeySaat,saat);
}

QString SerikBLDCore::DilekceAciklama::PersonelOid() const
{
    auto val = this->element (KeypersonelOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

QString SerikBLDCore::DilekceAciklama::Aciklama() const
{
    auto val = this->element (Keyaciklama);
    if( val )
    {
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::DilekceAciklama::DilekceOid() const
{
    auto val = this->element (KeydilekceOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

bool SerikBLDCore::DilekceAciklama::Gorunur() const
{
    auto val = this->element (KeyGorunur);
    if( val )
    {
        return val.value ().get_bool ().value;
    }else{
        return false;
    }
}

QString SerikBLDCore::DilekceAciklama::Tarih() const
{
    auto val = this->element (JulianDay);
    if( val )
    {
        return QDate::fromJulianDay (val.value ().get_int32 ().value).toString ("dd/MM/yyyy");
    }else{
        return "";
    }
}

QString SerikBLDCore::DilekceAciklama::PersonelName() const
{
    auto val = this->element (KeyPersonelName);
    if( val )
    {
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::DilekceAciklama::Saat() const
{
    auto val = this->element (KeySaat);
    if( val )
    {
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }else{
        return "";
    }}

SerikBLDCore::DilekceAciklama::operator bool() const
{
    return !this->view ().empty ();
}
