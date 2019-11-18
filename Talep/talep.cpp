#include "talep.h"
#include "tc.h"
#include <QTime>
#include <QDate>

const std::string SerikBLDCore::TalepKey::Collection{"Talep"};
const std::string SerikBLDCore::TalepKey::TCOID{"TCOID"};
const std::string SerikBLDCore::TalepKey::Mahalle{"Mahalle"};
const std::string SerikBLDCore::TalepKey::Adres{"Adress"};
const std::string SerikBLDCore::TalepKey::Konu{"Konu"};
const std::string SerikBLDCore::TalepKey::SecStartOfDay{"SecStartOfDay"};
const std::string SerikBLDCore::TalepKey::JulianDay{"julianday"};
const std::string SerikBLDCore::TalepKey::Durum{"Durum"};
const std::string SerikBLDCore::TalepKey::Kaynak{"Kaynak"};
const std::string SerikBLDCore::TalepKey::Birim{"Birim"};
const std::string SerikBLDCore::TalepKey::GorevliPersonel{"GorevliPersonel"};
const std::string SerikBLDCore::TalepKey::Yil{"Yıl"};
const std::string SerikBLDCore::TalepKey::Ay{"Ay"};



const std::string SerikBLDCore::TalepKey::DurumKey::DevamEdiyor{"DevamEdiyor"};
const std::string SerikBLDCore::TalepKey::DurumKey::Tamamlandi{"Tamamlandi"};
const std::string SerikBLDCore::TalepKey::DurumKey::TeyitEdilmemis{"TeyitEdilmemis"};
const std::string SerikBLDCore::TalepKey::DurumKey::Beklemede{"Beklemede"};
const std::string SerikBLDCore::TalepKey::DurumKey::RedEdildi{"RedEdildi"};

const std::string SerikBLDCore::TalepKey::KaynakKey::Sms{"SMS"};
const std::string SerikBLDCore::TalepKey::KaynakKey::Beyazmasa{"BEYAZMASA"};
const std::string SerikBLDCore::TalepKey::KaynakKey::Telefon{"TELEFON"};
const std::string SerikBLDCore::TalepKey::KaynakKey::Web{"WEB"};
const std::string SerikBLDCore::TalepKey::KaynakKey::Mobil{"MOBIL"};
const std::string SerikBLDCore::TalepKey::KaynakKey::SosyalMedya{"SOSYALMEDYA"};


SerikBLDCore::Talep::Talep::Talep(Talep *other) : Item(TalepKey::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

SerikBLDCore::Talep::Talep(const Talep &other) : Item(TalepKey::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Talep::Talep(Talep &&other) : Item(TalepKey::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Talep &SerikBLDCore::Talep::operator=(const Talep &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Talep &SerikBLDCore::Talep::operator=(Talep &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Talep::operator bool() const
{
    return !this->view ().empty ();
}

void SerikBLDCore::Talep::setTCOID(const QString &tcoid)
{
    this->append(TalepKey::TCOID,bsoncxx::oid{tcoid.toStdString ()});
}

void SerikBLDCore::Talep::setMahalle(const QString &mahalle)
{
    this->append(TalepKey::Mahalle,mahalle.toStdString ());
}

void SerikBLDCore::Talep::setAddress(const QString &address)
{
    this->append(TalepKey::Adres,address.toStdString ());
}

void SerikBLDCore::Talep::setKonu(const QString &konu)
{
    this->append(TalepKey::Konu,konu.toStdString ());
}

void SerikBLDCore::Talep::setSec(const int &mSecStartOfDay)
{
    this->append(TalepKey::SecStartOfDay,mSecStartOfDay);
}

void SerikBLDCore::Talep::setJulianDay(const int &julianDay)
{
    this->append(TalepKey::JulianDay,julianDay);
}

SerikBLDCore::Talep &SerikBLDCore::Talep::setDurum(const QString &durum)
{
    this->append(TalepKey::Durum,durum.toStdString ());
    return *this;
}

SerikBLDCore::Talep &SerikBLDCore::Talep::setKaynak(const QString &kaynak)
{
    this->append(TalepKey::Kaynak,kaynak.toStdString ());
    return *this;
}

SerikBLDCore::Talep &SerikBLDCore::Talep::setBirim(const QString &birim)
{
    this->append(TalepKey::Birim,birim.toStdString ());
    return *this;
}

SerikBLDCore::Talep &SerikBLDCore::Talep::AddGorevliPersonel(const Personel &personel)
{
    this->pushArray(TalepKey::GorevliPersonel,bsoncxx::document::value(personel.view ()));
    return *this;
}

SerikBLDCore::Talep &SerikBLDCore::Talep::DeleteGorevliPersonel(const Personel &personel)
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

SerikBLDCore::Talep &SerikBLDCore::Talep::setYil(const int &yil)
{
    this->append(TalepKey::Yil,yil);
    return *this;
}

SerikBLDCore::Talep &SerikBLDCore::Talep::setAy(const QString &ay)
{
    this->append(TalepKey::Ay,ay.toStdString ());
    return *this;
}

QString SerikBLDCore::Talep::oid() const
{
    auto val = this->element ("_id");
    if( val )
    {
        return QString::fromStdString (val->get_oid ().value.to_string ());
    }
    return "";
}

QString SerikBLDCore::Talep::tcOid() const
{
    auto val = this->element (TalepKey::TCOID);
    if( val )
    {
        return QString::fromStdString (val->get_oid ().value.to_string ());
    }
    return "";
}

QString SerikBLDCore::Talep::mahalle() const
{
    auto val = this->element (TalepKey::Mahalle);
    if( val )
    {
        return QString::fromStdString (val->get_utf8 ().value.to_string());
    }
    return "";
}

QString SerikBLDCore::Talep::adres() const
{
    auto val = this->element (TalepKey::Adres);
    if( val )
    {
        return QString::fromStdString (val->get_utf8 ().value.to_string());
    }
    return "";
}

QString SerikBLDCore::Talep::konu() const
{
    auto val = this->element (TalepKey::Konu);
    if( val )
    {
        return QString::fromStdString (val->get_utf8 ().value.to_string());
    }
    return "";
}

QString SerikBLDCore::Talep::saat() const
{
    auto val = this->element (TalepKey::SecStartOfDay);
    if( val )
    {
        return QTime::fromMSecsSinceStartOfDay (val->get_int32 ().value).toString ("hh:mm");
    }
    return "";
}

QString SerikBLDCore::Talep::tarih() const
{
    auto val = this->element (TalepKey::JulianDay);
    if( val )
    {
        return QDate::fromJulianDay (val->get_int32 ().value).toString ("dd/MM/yyyy");
    }
    return "";
}

int SerikBLDCore::Talep::julianDay() const
{
    auto val = this->element (TalepKey::JulianDay);
    if( val )
    {
        return  (val->get_int32 ().value);
    }
    return -1;
}

int SerikBLDCore::Talep::mSecStartOfDay() const
{
    auto val = this->element (TalepKey::SecStartOfDay);
    if( val )
    {
        return  (val->get_int32 ().value);
    }
    return -1;
}

QString SerikBLDCore::Talep::durum() const
{
    auto val = this->element (TalepKey::Durum);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

QString SerikBLDCore::Talep::durumColor() const
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

QString SerikBLDCore::Talep::kaynak() const
{
    auto val = this->element (TalepKey::Kaynak);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";}

QString SerikBLDCore::Talep::kaynakColor() const
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

QString SerikBLDCore::Talep::birim() const
{
    auto val = this->element (TalepKey::Birim);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

QVector<SerikBLDCore::Personel> SerikBLDCore::Talep::GorevliList() const
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
