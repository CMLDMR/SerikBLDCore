#include "talepsubitem.h"
#include "user.h"
#include <QDateTime>

const std::string SerikBLDCore::TalepSubItem::Collection{"TalepSubItem"};
const std::string SerikBLDCore::TalepSubItem::Type{"Tip"};
const std::string SerikBLDCore::TalepSubItem::TalepOid{"talepOid"};
const std::string SerikBLDCore::TalepSubItem::Aciklama{"Açıklama"};
const std::string SerikBLDCore::TalepSubItem::Fotograf{"Fotograf"};
const std::string SerikBLDCore::TalepSubItem::Pdf{"pdf"};
const std::string SerikBLDCore::TalepSubItem::Konum{"Konum"};
const std::string SerikBLDCore::TalepSubItem::Video{"Video"};
const std::string SerikBLDCore::TalepSubItem::Sms{"Sms"};
const std::string SerikBLDCore::TalepSubItem::Log{"Log"};
const std::string SerikBLDCore::TalepSubItem::PersonelName{"PersonelName"};
const std::string SerikBLDCore::TalepSubItem::PersonelOid{"PersonelOid"};
const std::string SerikBLDCore::TalepSubItem::TCName{"tcName"};
const std::string SerikBLDCore::TalepSubItem::TCOid{"tcOid"};
const std::string SerikBLDCore::TalepSubItem::UType{"UserType"};

SerikBLDCore::TalepSubItem::TalepSubItem() : Item (Collection)
{

}

SerikBLDCore::TalepSubItem::TalepSubItem(const TalepSubItem &other) : Item (Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::TalepSubItem::TalepSubItem(TalepSubItem &&other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::TalepSubItem &SerikBLDCore::TalepSubItem::operator=(const TalepSubItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::TalepSubItem &SerikBLDCore::TalepSubItem::operator=(TalepSubItem &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

void SerikBLDCore::TalepSubItem::setType(SerikBLDCore::TalepSubItem::ItemType type)
{
    this->append(Type,static_cast<int>(type));
}

SerikBLDCore::TalepSubItem::ItemType SerikBLDCore::TalepSubItem::type() const
{
    auto val = this->element (Type);
    if( val )
    {
        return static_cast<ItemType>(val.value ().get_int32 ().value);
    }
    return ItemType::none;
}

void SerikBLDCore::TalepSubItem::setTalepOid(const QString &talepOid)
{
    this->append(TalepOid,bsoncxx::oid{talepOid.toStdString ()});
}

QString SerikBLDCore::TalepSubItem::talepOid() const
{
    auto val = this->element (TalepOid);
    if( val )
    {
        return QString::fromStdString (val->get_oid ().value.to_string ());
    }
    return "";
}

void SerikBLDCore::TalepSubItem::setAciklama(const QString &aciklama)
{
    this->append(Aciklama,aciklama.toStdString ());
    this->setType (ItemType::Aciklama);
}

QString SerikBLDCore::TalepSubItem::aciklama() const
{
    auto val = this->element (Aciklama);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

void SerikBLDCore::TalepSubItem::setLog(const QString &log)
{
    this->append(Log,log.toStdString ());
    this->setType (ItemType::Log);
}

QString SerikBLDCore::TalepSubItem::log() const
{
    auto val = this->element (Log);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

void SerikBLDCore::TalepSubItem::setFotograf(const QString &fotoOid)
{
    this->append(Fotograf,bsoncxx::oid{fotoOid.toStdString ()});
    this->setType (ItemType::Fotograf);
}

QString SerikBLDCore::TalepSubItem::fotografOid() const
{
    auto val = this->element (Fotograf);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

void SerikBLDCore::TalepSubItem::setPdf(const QString &pdfOid)
{
    this->append(Pdf,bsoncxx::oid{pdfOid.toStdString ()});
    this->setType (ItemType::Pdf);
}

QString SerikBLDCore::TalepSubItem::pdfOid() const
{
    auto val = this->element (Pdf);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string());
    }
    return "";
}

void SerikBLDCore::TalepSubItem::setKonum(double x, double y)
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
    this->setType (ItemType::Konum);
}

double SerikBLDCore::TalepSubItem::xCoordinate() const
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

double SerikBLDCore::TalepSubItem::yCoordinate() const
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

void SerikBLDCore::TalepSubItem::setVideoOid(const QString &videoOid)
{
    this->append(Video,bsoncxx::oid{videoOid.toStdString ()});
    this->setType (ItemType::Video);
}

QString SerikBLDCore::TalepSubItem::videoOid() const
{
    auto val = this->element (Video);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

void SerikBLDCore::TalepSubItem::setSms(const QString &sms)
{
    this->append(Sms,sms.toStdString ());
    this->setType (ItemType::Sms);
}

QString SerikBLDCore::TalepSubItem::sms() const
{
    auto val = this->element (Sms);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

void SerikBLDCore::TalepSubItem::setPersonelName(const QString &personelName)
{
    this->append(PersonelName,personelName.toStdString ());
}

QString SerikBLDCore::TalepSubItem::personelName() const
{
    auto val = this->element (PersonelName);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

SerikBLDCore::TalepSubItem &SerikBLDCore::TalepSubItem::setPersonelOid(const QString &personelOid)
{
    this->setUserType (PersonelUser);
    this->append(PersonelOid,bsoncxx::oid{personelOid.toStdString ()});
    return *this;
}

QString SerikBLDCore::TalepSubItem::personelOid() const
{
    auto val = this->element (PersonelOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

SerikBLDCore::TalepSubItem &SerikBLDCore::TalepSubItem::setTCName(const QString &tcName)
{
    this->append(TCName,tcName.toStdString ());
    return *this;
}

QString SerikBLDCore::TalepSubItem::tcName() const
{
    auto val = this->element (TCName);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

SerikBLDCore::TalepSubItem &SerikBLDCore::TalepSubItem::setTCOid(const QString &tcOid)
{
    this->setUserType (TCUser);
    this->append(TCOid,bsoncxx::oid{tcOid.toStdString ()});
    return *this;
}

QString SerikBLDCore::TalepSubItem::tcOid() const
{
    auto val = this->element (TCOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string());
    }
    return "";
}

SerikBLDCore::TalepSubItem &SerikBLDCore::TalepSubItem::setUserType(const SerikBLDCore::TalepSubItem::UserType type)
{
    this->append(UType,bsoncxx::types::b_int32{static_cast<int>(type)});
    return *this;
}

SerikBLDCore::TalepSubItem::UserType SerikBLDCore::TalepSubItem::userType() const
{
    auto val = this->element (UType);
    if( val )
    {
        return static_cast<UserType>(val.value ().get_int32 ().value);
    }
    return NoUser;
}

QString SerikBLDCore::TalepSubItem::tarih() const
{
    auto val = this->oid ();
    if( val )
    {
        return QDateTime::fromTime_t (val.value ().get_time_t ()).date ().toString ("dd/MM/yyyy");
    }
    return "";
}

int SerikBLDCore::TalepSubItem::julianDay() const
{
    auto val = this->oid ();
    if( val )
    {
        return QDateTime::fromTime_t (val.value ().get_time_t ()).date ().toJulianDay ();
    }
    return 0;
}

QString SerikBLDCore::TalepSubItem::saat() const
{
    auto val = this->oid ();
    if( val )
    {
        return QDateTime::fromTime_t (val.value ().get_time_t ()).time ().toString ("hh:mm");
    }
    return "";
}

QString SerikBLDCore::TalepSubItem::typeColor() const
{
    switch (this->type ()) {
    case ItemType::Aciklama:
        return "dimgray";
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
    case ItemType::Log:
        return "cornflowerblue";
        break;
    default:
        break;
    }
}

QString SerikBLDCore::TalepSubItem::typeStr() const
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
    case ItemType::Log:
        return "Log";
        break;
    default:
        return "";
        break;
    }
}

QJsonObject SerikBLDCore::TalepSubItem::toJson() const
{
    return QJsonDocument::fromJson (bsoncxx::to_json (this->view ()).c_str ()).object ();
}
