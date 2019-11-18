#include "dilekcecevap.h"
#include <QDate>


const std::string SerikBLDCore::DilekceCevap::Collection{"DilekceCevap"};


SerikBLDCore::DilekceCevap::DilekceCevap(DilekceCevap *other) : Item (Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

SerikBLDCore::DilekceCevap::DilekceCevap(const DilekceCevap &other) : Item (Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::DilekceCevap::DilekceCevap(DilekceCevap &&other) : Item (Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::DilekceCevap &SerikBLDCore::DilekceCevap::operator=(const DilekceCevap &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::DilekceCevap &SerikBLDCore::DilekceCevap::operator=(DilekceCevap &&other)
{
    this->setDocumentView (other.view ());
    return *this;}

void SerikBLDCore::DilekceCevap::setDilekceOid(const QString &dilekceOid)
{
    this->append(KeyDilekceOid,bsoncxx::oid{dilekceOid.toStdString ()});
}

void SerikBLDCore::DilekceCevap::setPersonelOid(const QString &personelOid)
{
    this->append(KeyPersonelOid,bsoncxx::oid{personelOid.toStdString ()});
}

void SerikBLDCore::DilekceCevap::setPersonelName(const QString &personelName)
{
    this->append(KeyPersonelName,personelName.toStdString ());
}

void SerikBLDCore::DilekceCevap::setSaat(const QString &saat)
{
    this->append(KeySaat,saat.toStdString ());
}

void SerikBLDCore::DilekceCevap::setJulianDay(const int &julianDay)
{
    this->append(JulianDay,julianDay);
}

void SerikBLDCore::DilekceCevap::setCevapOid(const QString &cevapOid)
{
    this->append(KeyCevapOid,bsoncxx::oid{cevapOid.toStdString ()});
}

void SerikBLDCore::DilekceCevap::setCevapIcerik(const QString &cevapIcerik)
{
    this->append(KeyCevapIcerik,cevapIcerik.toStdString ());
}

void SerikBLDCore::DilekceCevap::addEkOid(const QString &ekOid)
{
    this->pushArray(KeyEkler,bsoncxx::oid{ekOid.toStdString ()});
}

QString SerikBLDCore::DilekceCevap::dilekceOid() const
{
    auto val = this->element (KeyDilekceOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

QString SerikBLDCore::DilekceCevap::personelOid() const
{
    auto val = this->element (KeyPersonelOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

QString SerikBLDCore::DilekceCevap::personelName() const
{
    auto val = this->element (KeyPersonelName);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }else{
        return "";
    }
}

QString SerikBLDCore::DilekceCevap::saat() const
{
    auto val = this->element (KeySaat);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }else{
        return "";
    }
}

int SerikBLDCore::DilekceCevap::julianDay() const
{
    auto val = this->element (JulianDay);
    if( val )
    {
        return val.value ().get_int32 ().value;
    }else{
        return -1;
    }
}

QString SerikBLDCore::DilekceCevap::Tarih() const
{
    auto val = this->element (JulianDay);
    if( val )
    {
        return QDate::fromJulianDay (val.value ().get_int32 ().value).toString ("dd/MM/yyyy");
    }else{
        return "";
    }
}

QString SerikBLDCore::DilekceCevap::cevapOid() const
{
    auto val = this->element (KeyCevapOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

QString SerikBLDCore::DilekceCevap::cevapIcerik() const
{
    auto val = this->element (KeyCevapIcerik);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }else{
        return "";
    }
}

QVector<QString> SerikBLDCore::DilekceCevap::ekList() const
{
    QVector<QString> list;
    auto cursor = this->element (KeyEkler);
    if( cursor )
    {
        for( auto item : cursor.value ().get_array ().value )
        {
            list.push_back (item.get_oid ().value.to_string ().c_str ());
        }
    }
    return list;
}
