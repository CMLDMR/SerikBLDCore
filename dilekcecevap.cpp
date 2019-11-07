#include "dilekcecevap.h"
#include <QDate>


const std::string DilekceCevap::Collection{"DilekceCevap"};


DilekceCevap::DilekceCevap(DilekceCevap *other) : Item (Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

DilekceCevap::DilekceCevap(const DilekceCevap &other) : Item (Collection)
{
    this->setDocumentView (other.view ());
}

DilekceCevap::DilekceCevap(DilekceCevap &&other) : Item (Collection)
{
    this->setDocumentView (other.view ());
}

DilekceCevap &DilekceCevap::operator=(const DilekceCevap &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

DilekceCevap &DilekceCevap::operator=(DilekceCevap &&other)
{
    this->setDocumentView (other.view ());
    return *this;}

void DilekceCevap::setDilekceOid(const QString &dilekceOid)
{
    this->append(KeyDilekceOid,bsoncxx::oid{dilekceOid.toStdString ()});
}

void DilekceCevap::setPersonelOid(const QString &personelOid)
{
    this->append(KeyPersonelOid,bsoncxx::oid{personelOid.toStdString ()});
}

void DilekceCevap::setPersonelName(const QString &personelName)
{
    this->append(KeyPersonelName,personelName.toStdString ());
}

void DilekceCevap::setSaat(const QString &saat)
{
    this->append(KeySaat,saat.toStdString ());
}

void DilekceCevap::setJulianDay(const int &julianDay)
{
    this->append(JulianDay,julianDay);
}

void DilekceCevap::setCevapOid(const QString &cevapOid)
{
    this->append(KeyCevapOid,bsoncxx::oid{cevapOid.toStdString ()});
}

void DilekceCevap::setCevapIcerik(const QString &cevapIcerik)
{
    this->append(KeyCevapIcerik,cevapIcerik.toStdString ());
}

void DilekceCevap::addEkOid(const QString &ekOid)
{
    this->pushArray(KeyEkler,bsoncxx::oid{ekOid.toStdString ()});
}

QString DilekceCevap::dilekceOid() const
{
    auto val = this->element (KeyDilekceOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

QString DilekceCevap::personelOid() const
{
    auto val = this->element (KeyPersonelOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

QString DilekceCevap::personelName() const
{
    auto val = this->element (KeyPersonelName);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }else{
        return "";
    }
}

QString DilekceCevap::saat() const
{
    auto val = this->element (KeySaat);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }else{
        return "";
    }
}

int DilekceCevap::julianDay() const
{
    auto val = this->element (JulianDay);
    if( val )
    {
        return val.value ().get_int32 ().value;
    }else{
        return -1;
    }
}

QString DilekceCevap::Tarih() const
{
    auto val = this->element (JulianDay);
    if( val )
    {
        return QDate::fromJulianDay (val.value ().get_int32 ().value).toString ("dd/MM/yyyy");
    }else{
        return "";
    }
}

QString DilekceCevap::cevapOid() const
{
    auto val = this->element (KeyCevapOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }else{
        return "";
    }
}

QString DilekceCevap::cevapIcerik() const
{
    auto val = this->element (KeyCevapIcerik);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }else{
        return "";
    }
}

QVector<QString> DilekceCevap::ekList() const
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
