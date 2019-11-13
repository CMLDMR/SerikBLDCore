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
const std::string TalepKey::Durum{"Durum"};
const std::string TalepKey::Kaynak{"Kaynak"};
const std::string TalepKey::Birim{"Birim"};
const std::string TalepKey::GorevliPersonel{"GorevliPersonel"};



const std::string TalepKey::DurumKey::DevamEdiyor{"DevamEdiyor"};
const std::string TalepKey::DurumKey::Tamamlandi{"Tamamlandi"};
const std::string TalepKey::DurumKey::TeyitEdilmemis{"TeyitEdilmemis"};
const std::string TalepKey::DurumKey::Beklemede{"Beklemede"};
const std::string TalepKey::DurumKey::RedEdildi{"RedEdildi"};

const std::string TalepKey::KaynakKey::Sms{"SMS"};
const std::string TalepKey::KaynakKey::Beyazmasa{"BEYAZMASA"};
const std::string TalepKey::KaynakKey::Telefon{"TELEFON"};
const std::string TalepKey::KaynakKey::Web{"WEB"};
const std::string TalepKey::KaynakKey::Mobil{"MOBIL"};
const std::string TalepKey::KaynakKey::SosyalMedya{"SOSYALMEDYA"};


Talep::Talep::Talep(Talep *other) : Item(TalepKey::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

Talep::Talep(const Talep &other) : Item(TalepKey::Collection)
{
    this->setDocumentView (other.view ());
}

Talep::Talep(Talep &&other) : Item(TalepKey::Collection)
{
    this->setDocumentView (other.view ());
}

Talep &Talep::operator=(const Talep &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

Talep &Talep::operator=(Talep &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

Talep::operator bool() const
{
    return !this->view ().empty ();
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

Talep &Talep::setDurum(const QString &durum)
{
    this->append(TalepKey::Durum,durum.toStdString ());
    return *this;
}

Talep &Talep::setKaynak(const QString &kaynak)
{
    this->append(TalepKey::Kaynak,kaynak.toStdString ());
    return *this;
}

Talep &Talep::setBirim(const QString &birim)
{
    this->append(TalepKey::Birim,birim.toStdString ());
    return *this;
}

Talep &Talep::AddGorevliPersonel(const Personel &personel)
{
    this->pushArray(TalepKey::GorevliPersonel,bsoncxx::document::value(personel.view ()));
}

Talep &Talep::DeleteGorevliPersonel(const Personel &personel)
{
    auto pList = this->GorevliList ();
    this->removeElement (TalepKey::GorevliPersonel);

    if( pList.count () == 1 )
    {
        this->append(TalepKey::GorevliPersonel,array{});
        return *this;
    }

    for( auto item : pList )
    {
        if( item.oid ().value ().to_string () != personel.oid ().value ().to_string () )
        {
            this->AddGorevliPersonel (item);
        }
    }
    return *this;
}

QString Talep::oid() const
{
    auto val = this->element ("_id");
    if( val )
    {
        return QString::fromStdString (val->get_oid ().value.to_string ());
    }
    return "";
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

QString Talep::durum() const
{
    auto val = this->element (TalepKey::Durum);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

QString Talep::durumColor() const
{
    auto durum_ = this->durum ();

    if( durum_ == "DevamEdiyor" )
    {
        return "LightSeaGreen";
    }else if (durum_ == "Tamamlandi") {
        return "DodgerBlue";
    }else if (durum_ == "TeyitEdilmemis") {
        return "PaleVioletRed";
    }else if (durum_ == "Beklemede") {
        return "GoldenRod";
    }else if (durum_ == "RedEdildi") {
        return "crimson";
    }

}

QString Talep::kaynak() const
{
    auto val = this->element (TalepKey::Kaynak);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";}

QString Talep::kaynakColor() const
{
    auto kaynak_ = this->kaynak ();

    if( kaynak_ == "SMS" )
    {
        return "MediumVioletRed";
    }else if (kaynak_ == "BEYAZMASA") {
        return "MintCream";
    }else if (kaynak_ == "TELEFON") {
        return "MediumTurquoise";
    }else if (kaynak_ == "WEB") {
        return "MediumOrchid";
    }else if (kaynak_ == "MOBIL") {
        return "LightSteelBlue";
    }else if (kaynak_ == "SOSYALMEDYA") {
        return "DarkSlateBlue";
    }
}

QString Talep::birim() const
{
    auto val = this->element (TalepKey::Birim);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

QVector<Personel> Talep::GorevliList() const
{
    QVector<Personel> list;

    auto _list = this->element (TalepKey::GorevliPersonel);

    if( _list )
    {
        auto __list = _list.value ().get_array ().value;
        for( auto item : __list )
        {
            Personel personelItem;
            personelItem.setDocumentView (item.get_document ().view ());
            list.push_back (std::move(personelItem));
        }
    }
    return list;
}
