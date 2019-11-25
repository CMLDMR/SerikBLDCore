#include "bilgiedinmeitem.h"
#include <QDateTime>


const std::string SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::Collection{"BilgiEdinme"};


SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::BilgiEdinmeItem(SerikBLDCore::BilgiEdinme::BilgiEdinmeItem *other) : SerikBLDCore::Item (Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }else{

    }
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::BilgiEdinmeItem(const SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &other): SerikBLDCore::Item (Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::BilgiEdinmeItem(SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &&other): SerikBLDCore::Item (Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::operator=(const SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::operator=(SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::setGeriDonus(const bool &geriDonus)
{
    this->append(Key::GeriDonus,geriDonus);
    return *this;
}

bool SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::geriDonus() const
{
    auto val = this->element (Key::GeriDonus);
    if( val )
    {
        return val.value ().get_bool ().value;
    }
    return false;
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::setJulianDay(const int &julianDay)
{
    this->append(Key::JulianDay,julianDay);
    return *this;
}

int SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::julianDay() const
{
    auto val = this->element (Key::JulianDay);
    if( val )
    {
        return val.value ().get_int32 ().value;
    }
    return 0;
}

QString SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::tarih() const
{
    auto _oid = this->oid ();
    if( _oid )
    {
        return QDateTime::fromTime_t (_oid.value ().get_time_t ()).date ().toString ("dd/MM/yyyy");
    }else{
        return "01/01/1970";
    }
}

QString SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::saat() const
{
    auto _oid = this->oid ();
    if( _oid )
    {
        return QDateTime::fromTime_t (_oid.value ().get_time_t ()).time ().toString ("hh:mm");
    }else{
        return "00:00";
    }
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::setTCoid(const QString &tcoid)
{
    this->append(Key::TCOid,bsoncxx::oid{tcoid.toStdString ()});
    return *this;
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::setTCoid(const bsoncxx::oid &tcoid)
{
    this->append(Key::TCOid,tcoid);
    return *this;
}

QString SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::tcOid() const
{
    auto val = this->element (Key::TCOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::setKonu(const QString &konu)
{
    this->append(Key::Konu,konu.toStdString ());
    return *this;
}

QString SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::konu() const
{
    auto val = this->element (Key::Konu);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }
    return "";
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::setMesaj(const QString &mesaj)
{
    this->append(Key::Mesaj,mesaj.toStdString ());
    return *this;
}

QString SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::mesaj() const
{
    auto val = this->element (Key::Mesaj);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }
    return "";
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::setBirim(const QString &birim)
{
    this->append(Key::Birim,birim.toStdString ());
    return *this;
}

QString SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::birim() const
{
    auto val = this->element (Key::Birim);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }
    return "";
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::setCevap(const QString &cevapOid)
{
    this->append(Key::CevapOid,bsoncxx::oid{cevapOid.toStdString ()});
    return *this;
}

SerikBLDCore::BilgiEdinme::BilgiEdinmeItem &SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::setCevap(const bsoncxx::oid &cevapOid)
{
    this->append(Key::CevapOid,cevapOid);
    return *this;
}

QString SerikBLDCore::BilgiEdinme::BilgiEdinmeItem::cevapOid() const
{
    auto val = this->element (Key::CevapOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}
