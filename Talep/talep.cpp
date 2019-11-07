#include "talep.h"
#include "tc.h"
#include <QTime>
#include <QDate>

const std::string TalepKey::Collection{"Talep"};
const std::string TalepKey::TCOID{"TCOID"};
const std::string TalepKey::Mahalle{"Mahalle"};
const std::string TalepKey::Adres{"Adress"};
const std::string TalepKey::Konu{"Konu"};
const std::string TalepKey::SecStartOfDay{"SecStartOfDay"};
const std::string TalepKey::JulianDay{"julianday"};



Talep::Talep::Talep(Talep *other) : Item(TalepKey::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

void Talep::setTCOID(const QString &tcoid)
{
    this->append(TalepKey::TCOID,bsoncxx::types::b_dbpointer{TC::Collection,bsoncxx::oid{tcoid.toStdString ()}});
}

void Talep::setMahalle(const QString &mahalle)
{
    this->append(TalepKey::Mahalle,mahalle.toStdString ());
}

void Talep::setAddress(const QString &address)
{
    this->append(TalepKey::Adres,address.toStdString ());
}

void Talep::setKonu(const QString &konu)
{
    this->append(TalepKey::Konu,konu.toStdString ());
}

void Talep::setSec(const int &mSecStartOfDay)
{
    this->append(TalepKey::SecStartOfDay,mSecStartOfDay);
}

void Talep::setJulianDay(const int &julianDay)
{
    this->append(TalepKey::JulianDay,julianDay);
}

QString Talep::tcOid() const
{
    auto val = this->element (TalepKey::TCOID);
    if( val )
    {
        return QString::fromStdString (val->get_dbpointer ().value.to_string ());
    }
    return "";
}

QString Talep::mahalle() const
{
    auto val = this->element (TalepKey::Mahalle);
    if( val )
    {
        return QString::fromStdString (val->get_utf8 ().value.to_string());
    }
    return "";
}

QString Talep::adres() const
{
    auto val = this->element (TalepKey::Adres);
    if( val )
    {
        return QString::fromStdString (val->get_utf8 ().value.to_string());
    }
    return "";
}

QString Talep::konu() const
{
    auto val = this->element (TalepKey::Konu);
    if( val )
    {
        return QString::fromStdString (val->get_utf8 ().value.to_string());
    }
    return "";
}

QString Talep::saat() const
{
    auto val = this->element (TalepKey::SecStartOfDay);
    if( val )
    {
        return QTime::fromMSecsSinceStartOfDay (val->get_int32 ().value).toString ("hh:mm");
    }
    return "";
}

QString Talep::tarih() const
{
    auto val = this->element (TalepKey::JulianDay);
    if( val )
    {
        return QDate::fromJulianDay (val->get_int32 ().value).toString ("dd/MM/yyyy");
    }
    return "";
}

int Talep::julianDay() const
{
    auto val = this->element (TalepKey::JulianDay);
    if( val )
    {
        return  (val->get_int32 ().value);
    }
    return -1;
}

int Talep::mSecStartOfDay() const
{
    auto val = this->element (TalepKey::SecStartOfDay);
    if( val )
    {
        return  (val->get_int32 ().value);
    }
    return -1;
}
