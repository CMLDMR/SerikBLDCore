#include "dilekce.h"
#include <QDate>
#include <QTime>

const std::string Dilekce::Collection = "Dilekce";
const std::string Dilekce::KeySayi = "Sayı";
const std::string Dilekce::KeyKonu{"Konu"};
const std::string Dilekce::KeyTCOid{"TCOid"};
const std::string Dilekce::KeyBirim{"Birim"};
const std::string Dilekce::KeyIcerikTipi{"IcerikTipi"};
const std::string Dilekce::KeyIcerik{"Icerik"};
const std::string Dilekce::KeyDilekceOid{"dilekceOid"};
const std::string Dilekce::KeyEkler{"Ekler"};
const std::string Dilekce::KeyTarihJulian{"TarihJulian"};
const std::string Dilekce::KeySaat{"Saat"};
const std::string Dilekce::KeyBilgiBirimler{"BilgiBirimler"};
const std::string Dilekce::KeyOid{"_id"};


Dilekce::Dilekce(Dilekce *other) : Item(Dilekce::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

Dilekce::operator bool() const
{
    return !this->view ().empty ();
}




void Dilekce::SetSayi(const int &sayi)
{
    this->append(KeySayi,sayi);
}

void Dilekce::SetKonu(const QString &konu)
{
    this->append(KeyKonu,konu.toStdString ());
}

void Dilekce::SetTCOid(const QString &oid)
{
    this->append(KeyTCOid,bsoncxx::oid{oid.toStdString ()});
}

void Dilekce::SetBirim(const QString &birim)
{
    this->append(KeyBirim,birim.toStdString ());
}

void Dilekce::SetIcerikTipi(const QString &icerikTipi)
{
    this->append(KeyIcerikTipi,icerikTipi.toStdString ());
}

void Dilekce::SetIcerik(const QString &icerik)
{
    this->append(KeyIcerik,icerik.toStdString ());
}

void Dilekce::SetDilekceOid(const QString &dilekceOid)
{
    this->append(KeyDilekceOid,dilekceOid.toStdString ());
}

void Dilekce::AddEkOid(const QString &ekOid)
{
    //TODO: Array Eklenecek
    this->pushArray(KeyEkler,bsoncxx::oid{ekOid.toStdString ()});
}

void Dilekce::SetTarih(const int &julianDay)
{
    this->append(KeyTarihJulian,julianDay);
}

void Dilekce::SetSaat(const int &mSecsFromBeginDay)
{
    this->append(KeySaat,mSecsFromBeginDay);
}

void Dilekce::AddBilgiBirim(const QString &bilgiBirim)
{
    this->pushArray(KeyBilgiBirimler,bilgiBirim.toStdString ());
}

void Dilekce::SetOid(const QString &oid)
{
    this->append(KeyOid,bsoncxx::oid{oid.toStdString ()});

}

int Dilekce::sayi()
{
    auto sayi = this->element (KeySayi);
    if( sayi )
    {
        return sayi->get_int32 ().value;
    }else{
        return -1;
    }
}

QString Dilekce::konu()
{
    auto value = this->element (KeyKonu);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString Dilekce::tcoid()
{
    auto value = this->element (KeyTCOid);
    if( value )
    {
        return QString::fromStdString (value->get_oid ().value.to_string());
    }else{
        return "";
    }
}

QString Dilekce::birim()
{
    auto value = this->element (KeyBirim);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString Dilekce::icerikTipi()
{
    auto value = this->element (KeyIcerikTipi);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString Dilekce::icerik()
{
    auto value = this->element (KeyIcerik);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

int Dilekce::tarihJulian()
{
    auto value = this->element (KeyTarihJulian);
    if( value )
    {
        return  (value->get_int32 ().value);
    }else{
        return -1;
    }
}

QString Dilekce::tarihText()
{
    auto value = this->element (KeyTarihJulian);
    if( value )
    {
        return QDate::fromJulianDay (value->get_int32 ().value).toString ("dd/MM/yyyy");
    }else{
        return "Tarih Yok";
    }
}

int Dilekce::saatMSecStartofDay()
{
    auto value = this->element (KeySaat);
    if( value )
    {
        return  (value->get_int32 ().value);
    }else{
        return -1;
    }
}

QString Dilekce::saatText()
{
    auto value = this->element (KeySaat);
    if( value )
    {
        return  QTime::fromMSecsSinceStartOfDay ((value->get_int32 ().value)).toString ("hh:mm");
    }else{
        return "Saat Yok";
    }
}

