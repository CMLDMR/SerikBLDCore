#include "bilgiedinmeitem.h"
#include <QDateTime>


const std::string SerikBLDCore::BilgiEdinmeItem::Collection{"BilgiEdinme"};


SerikBLDCore::BilgiEdinmeItem::BilgiEdinmeItem(SerikBLDCore::BilgiEdinmeItem *other) : SerikBLDCore::Item (Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }else{

    }
}

SerikBLDCore::BilgiEdinmeItem::BilgiEdinmeItem(const SerikBLDCore::BilgiEdinmeItem &other): SerikBLDCore::Item (Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::BilgiEdinmeItem::BilgiEdinmeItem(SerikBLDCore::BilgiEdinmeItem &&other): SerikBLDCore::Item (Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::operator=(const SerikBLDCore::BilgiEdinmeItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::operator=(SerikBLDCore::BilgiEdinmeItem &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::setGeriDonus(const bool &geriDonus)
{
    this->append(BilgiEdinme::Key::GeriDonus,geriDonus);
    return *this;
}

bool SerikBLDCore::BilgiEdinmeItem::geriDonus() const
{
    auto val = this->element (BilgiEdinme::Key::GeriDonus);
    if( val )
    {
        return val.value ().get_bool ().value;
    }
    return false;
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::setJulianDay(const int &julianDay)
{
    this->append(BilgiEdinme::Key::JulianDay,julianDay);
    return *this;
}

int SerikBLDCore::BilgiEdinmeItem::julianDay() const
{
    auto val = this->element (BilgiEdinme::Key::JulianDay);
    if( val )
    {
        return val.value ().get_int32 ().value;
    }
    return 0;
}

QString SerikBLDCore::BilgiEdinmeItem::tarih() const
{
    auto _oid = this->oid ();
    if( _oid )
    {
        return QDateTime::fromTime_t (_oid.value ().get_time_t ()).date ().toString ("dd/MM/yyyy");
    }else{
        return "01/01/1970";
    }
}

QString SerikBLDCore::BilgiEdinmeItem::saat() const
{
    auto _oid = this->oid ();
    if( _oid )
    {
        return QDateTime::fromTime_t (_oid.value ().get_time_t ()).time ().toString ("hh:mm");
    }else{
        return "00:00";
    }
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::setTCoid(const QString &tcoid)
{
    this->append(BilgiEdinme::Key::TCOid,bsoncxx::oid{tcoid.toStdString ()});
    return *this;
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::setTCoid(const bsoncxx::oid &tcoid)
{
    this->append(BilgiEdinme::Key::TCOid,tcoid);
    return *this;
}

QString SerikBLDCore::BilgiEdinmeItem::tcOid() const
{
    auto val = this->element (BilgiEdinme::Key::TCOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::setKonu(const QString &konu)
{
    this->append(BilgiEdinme::Key::Konu,konu.toStdString ());
    return *this;
}

QString SerikBLDCore::BilgiEdinmeItem::konu() const
{
    auto val = this->element (BilgiEdinme::Key::Konu);
    if( val )
    {
#ifdef Q_CC_MSVC
    return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif

#ifdef Q_CC_GNU
    return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }
    return "";
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::setMesaj(const QString &mesaj)
{
    this->append(BilgiEdinme::Key::Mesaj,mesaj.toStdString ());
    return *this;
}

QString SerikBLDCore::BilgiEdinmeItem::mesaj() const
{
    auto val = this->element (BilgiEdinme::Key::Mesaj);
    if( val )
    {
#ifdef Q_CC_MSVC
    return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif

#ifdef Q_CC_GNU
    return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }
    return "";
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::setBirim(const QString &birim)
{
    this->append(BilgiEdinme::Key::Birim,birim.toStdString ());
    return *this;
}

QString SerikBLDCore::BilgiEdinmeItem::birim() const
{
    auto val = this->element (BilgiEdinme::Key::Birim);
    if( val )
    {
#ifdef Q_CC_MSVC
    return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif

#ifdef Q_CC_GNU
    return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }
    return "";
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::setCevap(const QString &cevapOid)
{
    this->append(BilgiEdinme::Key::CevapOid,bsoncxx::oid{cevapOid.toStdString ()});
    return *this;
}

SerikBLDCore::BilgiEdinmeItem &SerikBLDCore::BilgiEdinmeItem::setCevap(const bsoncxx::oid &cevapOid)
{
    this->append(BilgiEdinme::Key::CevapOid,cevapOid);
    return *this;
}

QString SerikBLDCore::BilgiEdinmeItem::cevapOid() const
{
    auto val = this->element (BilgiEdinme::Key::CevapOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

bool SerikBLDCore::BilgiEdinmeItem::cevaplandi() const
{
    auto val = this->element (BilgiEdinme::Key::CevapOid);
    if( val )
    {
        return true;
    }else{
        return false;
    }
}
