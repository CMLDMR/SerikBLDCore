#include "talepsubitem.h"
#include "user.h"
#include <QDateTime>

const std::string TalepSubItem::Collection{"TalepSubItem"};
const std::string TalepSubItem::Type{"Tip"};
const std::string TalepSubItem::TalepOid{"talepOid"};
const std::string TalepSubItem::Aciklama{"Açıklama"};
const std::string TalepSubItem::Fotograf{"Fotograf"};
const std::string TalepSubItem::Pdf{"pdf"};
const std::string TalepSubItem::Konum{"Konum"};
const std::string TalepSubItem::Video{"Video"};
const std::string TalepSubItem::Sms{"Sms"};
const std::string TalepSubItem::PersonelName{"PersonelName"};
const std::string TalepSubItem::PersonelOid{"PersonelOid"};

TalepSubItem::TalepSubItem() : Item (Collection)
{
}

TalepSubItem::TalepSubItem(const TalepSubItem &other) : Item (Collection)
{
    this->setDocumentView (other.view ());
}

TalepSubItem::TalepSubItem(TalepSubItem &&other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

TalepSubItem &TalepSubItem::operator=(const TalepSubItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

TalepSubItem &TalepSubItem::operator=(TalepSubItem &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

void TalepSubItem::setType(TalepSubItem::ItemType type)
{
    this->append(Type,static_cast<int>(type));
}

TalepSubItem::ItemType TalepSubItem::type() const
{
    auto val = this->element (Type);
    if( val )
    {
        return static_cast<ItemType>(val.value ().get_int32 ().value);
    }
    return ItemType::none;
}

void TalepSubItem::setTalepOid(const QString &talepOid)
{
    this->append(TalepOid,bsoncxx::types::b_dbpointer{TalepKey::Collection,bsoncxx::oid{talepOid.toStdString ()}});
}

QString TalepSubItem::talepOid() const
{
    auto val = this->element (TalepOid);
    if( val )
    {
        return QString::fromStdString (val->get_dbpointer ().value.to_string ());
    }
    return "";
}

void TalepSubItem::setAciklama(const QString &aciklama)
{
    this->append(Aciklama,aciklama.toStdString ());
}

QString TalepSubItem::aciklama() const
{
    auto val = this->element (Aciklama);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

void TalepSubItem::setFotograf(const QString &fotoOid)
{
    this->append(Fotograf,bsoncxx::oid{fotoOid.toStdString ()});
}

QString TalepSubItem::fotografOid() const
{
    auto val = this->element (Fotograf);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

void TalepSubItem::setPdf(const QString &pdfOid)
{
    this->append(Pdf,bsoncxx::oid{pdfOid.toStdString ()});
}

QString TalepSubItem::pdfOid() const
{
    auto val = this->element (Pdf);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string());
    }
    return "";
}

void TalepSubItem::setKonum(double x, double y)
{
    auto doc = document{};

    try {
        doc.append (kvp("x",x));
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
    }

    try {
        doc.append (kvp("y",y));
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
    }

    this->append(Konum,doc);
}

double TalepSubItem::xCoordinate() const
{
    auto val = this->element (Konum);
    if( val )
    {
        try {
            return val.value ().get_document ().value["x"].get_double ().value;
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            return 0;
        }
    }
    return 0;
}

double TalepSubItem::yCoordinate() const
{
    auto val = this->element (Konum);
    if( val )
    {
        try {
            return val.value ().get_document ().value["y"].get_double ().value;
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            return 0;
        }
    }
    return 0;
}

void TalepSubItem::setVideoOid(const QString &videoOid)
{
    this->append(Video,bsoncxx::oid{videoOid.toStdString ()});
}

QString TalepSubItem::videoOid() const
{
    auto val = this->element (Video);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

void TalepSubItem::setSms(const QString &sms)
{
    this->append(Sms,sms.toStdString ());
}

QString TalepSubItem::sms() const
{
    auto val = this->element (Sms);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

void TalepSubItem::setPersonelName(const QString &personelName)
{
    this->append(PersonelName,personelName.toStdString ());
}

QString TalepSubItem::personelName() const
{
    auto val = this->element (PersonelName);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

void TalepSubItem::setPersonelOid(const QString &personelOid)
{
    this->append(PersonelOid,bsoncxx::types::b_dbpointer{User::Collection,bsoncxx::oid{personelOid.toStdString ()}});
}

QString TalepSubItem::personelOid() const
{
    auto val = this->element (PersonelOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_dbpointer ().value.to_string ());
    }
    return "";
}

QString TalepSubItem::tarih() const
{
    auto val = this->oid ();
    if( val )
    {
        return QDateTime::fromTime_t (val.value ().get_time_t ()).date ().toString ("dd/MM/yyyy");
    }
    return "";
}

int TalepSubItem::julianDay() const
{
    auto val = this->oid ();
    if( val )
    {
        return QDateTime::fromTime_t (val.value ().get_time_t ()).date ().toJulianDay ();
    }
    return 0;
}

QString TalepSubItem::saat() const
{
    auto val = this->oid ();
    if( val )
    {
        return QDateTime::fromTime_t (val.value ().get_time_t ()).time ().toString ("hh:mm");
    }
    return "";
}

QString TalepSubItem::typeColor() const
{
    switch (this->type ()) {
    case ItemType::Aciklama:
        return "lightgray";
        break;
    case ItemType::Fotograf:
        return "orange";
        break;
    case ItemType::Pdf:
        return "steelblue";
        break;
    case ItemType::Sms:
        return "crimson";
        break;
    default:
        break;
    }
}

QString TalepSubItem::typeStr() const
{
    switch (this->type ()) {
    case ItemType::Aciklama:
        return "Aciklama";
        break;
    case ItemType::Fotograf:
        return "Fotograf";
        break;
    case ItemType::Pdf:
        return "Pdf";
        break;
    case ItemType::Sms:
        return "Sms";
        break;
    default:
        break;
    }
}

QJsonObject TalepSubItem::toJson() const
{
    return QJsonDocument::fromJson (bsoncxx::to_json (this->view ()).c_str ()).object ();
}
