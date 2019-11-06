#include "talep.h"

#include "tc.h"

const std::string Talep::Collection{"Talep"};
const std::string Talep::KeyTCOID{"TCOID"};
const std::string Talep::KeyMahalle{"Mahalle"};
const std::string Talep::KeyAdres{"Adress"};
const std::string Talep::KeyKonu{"Konu"};
const std::string Talep::KeySecStartOfDay{"SecStartOfDay"};
const std::string Talep::KeyJulianDay{"julianday"};



Talep::Talep::Talep(Talep *other) : Item(Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

void Talep::setTCOID(const QString &tcoid)
{
    this->append(KeyTCOID,bsoncxx::types::b_dbpointer{TC::Collection,bsoncxx::oid{tcoid.toStdString ()}});
}

void Talep::setMahalle(const QString &mahalle)
{
    this->append(KeyMahalle,mahalle.toStdString ());
}

void Talep::setAddress(const QString &address)
{
    this->append(KeyAdres,address.toStdString ());
}

void Talep::setKonu(const QString &konu)
{
    this->append(KeyKonu,konu.toStdString ());
}

void Talep::setSec(const int &mSecStartOfDay)
{
    this->append(KeySecStartOfDay,mSecStartOfDay);
}

void Talep::setJulianDay(const int &julianDay)
{
    this->append(KeyJulianDay,julianDay);
}

QString Talep::tcOid() const
{
    auto val = this->element (KeyTCOID);
    if( val )
    {
        return QString::fromStdString (val->get_dbpointer ().value.to_string ());
    }
    return "";
}

QString Talep::mahalle() const
{
    auto val = this->element (KeyMahalle);
    if( val )
    {
        return QString::fromStdString (val->get_utf8 ().value.to_string());
    }
    return "";
}
