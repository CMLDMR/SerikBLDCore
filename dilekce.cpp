#include "dilekce.h"
#include <QDate>
#include <QTime>

const std::string SerikBLDCore::Dilekce::Collection = "Dilekce";
const std::string SerikBLDCore::Dilekce::KeySayi = "Sayı";
const std::string SerikBLDCore::Dilekce::KeyKonu{"Konu"};
const std::string SerikBLDCore::Dilekce::KeyTCOid{"TCOid"};
const std::string SerikBLDCore::Dilekce::KeyBirim{"Birim"};
const std::string SerikBLDCore::Dilekce::KeyIcerikTipi{"IcerikTipi"};
const std::string SerikBLDCore::Dilekce::KeyIcerik{"Icerik"};
const std::string SerikBLDCore::Dilekce::KeyDilekceOid{"dilekceOid"};
const std::string SerikBLDCore::Dilekce::KeyEkler{"Ekler"};
const std::string SerikBLDCore::Dilekce::KeyTarihJulian{"TarihJulian"};
const std::string SerikBLDCore::Dilekce::KeySaat{"Saat"};
const std::string SerikBLDCore::Dilekce::KeyBilgiBirimler{"BilgiBirimler"};
const std::string SerikBLDCore::Dilekce::KeyOid{"_id"};
const std::string SerikBLDCore::Dilekce::KeyGorevliPersonel{"GorevliPersonel"};
const std::string SerikBLDCore::Dilekce::KeyDilekceDurum{"DilekceDurum"};
const std::string SerikBLDCore::Dilekce::KeyCevapOid{"CevapOid"};
const std::string SerikBLDCore::Dilekce::KeyYil{"Yıl"};
const std::string SerikBLDCore::Dilekce::KeyAy{"Ay"};



SerikBLDCore::Dilekce::Dilekce(Dilekce *other) : Item(Dilekce::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

SerikBLDCore::Dilekce::operator bool() const
{
    return !this->view ().empty ();
}




void SerikBLDCore::Dilekce::SetSayi(const int &sayi)
{
    this->append(KeySayi,sayi);
}

void SerikBLDCore::Dilekce::SetKonu(const QString &konu)
{
    this->append(KeyKonu,konu.toStdString ());
}

void SerikBLDCore::Dilekce::SetTCOid(const QString &oid)
{
    this->append(KeyTCOid,bsoncxx::oid{oid.toStdString ()});
}

void SerikBLDCore::Dilekce::SetBirim(const QString &birim)
{
    this->append(KeyBirim,birim.toStdString ());
}

void SerikBLDCore::Dilekce::SetIcerikTipi(const QString &icerikTipi)
{
    this->append(KeyIcerikTipi,icerikTipi.toStdString ());
}

void SerikBLDCore::Dilekce::SetIcerik(const QString &icerik)
{
    this->append(KeyIcerik,icerik.toStdString ());
}

void SerikBLDCore::Dilekce::SetDilekceOid(const QString &dilekceOid)
{
    this->append(KeyDilekceOid,dilekceOid.toStdString ());
}

void SerikBLDCore::Dilekce::AddEkOid(const QString &ekOid)
{
    //TODO: Array Eklenecek
    this->pushArray(KeyEkler,bsoncxx::oid{ekOid.toStdString ()});
}

void SerikBLDCore::Dilekce::SetTarih(const int &julianDay)
{
    this->append(KeyTarihJulian,julianDay);
}

void SerikBLDCore::Dilekce::SetSaat(const int &mSecsFromBeginDay)
{
    this->append(KeySaat,mSecsFromBeginDay);
}

void SerikBLDCore::Dilekce::AddBilgiBirim(const QString &bilgiBirim)
{
    this->pushArray(KeyBilgiBirimler,bilgiBirim.toStdString ());
}

void SerikBLDCore::Dilekce::SetOid(const QString &oid)
{
    this->append(KeyOid,bsoncxx::oid{oid.toStdString ()});

}

void SerikBLDCore::Dilekce::AddGorevliPersonel(const Personel &personel)
{
    this->pushArray(KeyGorevliPersonel,bsoncxx::document::value(personel.view ()));
}

void SerikBLDCore::Dilekce::DeleteGorevliPersonel(const Personel &personel)
{
    auto pList = this->GorevliList ();
    this->removeElement (KeyGorevliPersonel);

    if( pList.count () == 1 )
    {
        this->append(KeyGorevliPersonel,array{});
        return;
    }

    for( auto item : pList )
    {
        if( item.oid ().value ().to_string () != personel.oid ().value ().to_string () )
        {
            this->AddGorevliPersonel (item);
        }
    }
}

void SerikBLDCore::Dilekce::SetDurum(const QString &dilekceDurum)
{
    this->append(KeyDilekceDurum,dilekceDurum.toStdString ());
}

void SerikBLDCore::Dilekce::SetCevapOid(const QString &cevapOid)
{
    this->append(KeyCevapOid,bsoncxx::oid{cevapOid.toStdString ()});
}

SerikBLDCore::Dilekce &SerikBLDCore::Dilekce::setYil(const int &yil)
{
    this->append(KeyYil,yil);
    return *this;
}

SerikBLDCore::Dilekce &SerikBLDCore::Dilekce::setAy(const QString &ay)
{
    this->append(KeyAy,ay.toStdString ());
    return *this;
}


int SerikBLDCore::Dilekce::sayi()
{
    auto sayi = this->element (KeySayi);
    if( sayi )
    {
        return sayi->get_int32 ().value;
    }else{
        return -1;
    }
}

QString SerikBLDCore::Dilekce::konu()
{
    auto value = this->element (KeyKonu);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::Dilekce::tcoid()
{
    auto value = this->element (KeyTCOid);
    if( value )
    {
        return QString::fromStdString (value->get_oid ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::Dilekce::birim()
{
    auto value = this->element (KeyBirim);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::Dilekce::icerikTipi()
{
    auto value = this->element (KeyIcerikTipi);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::Dilekce::icerik()
{
    auto value = this->element (KeyIcerik);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

int SerikBLDCore::Dilekce::tarihJulian()
{
    auto value = this->element (KeyTarihJulian);
    if( value )
    {
        return  (value->get_int32 ().value);
    }else{
        return -1;
    }
}

QString SerikBLDCore::Dilekce::tarihText()
{
    auto value = this->element (KeyTarihJulian);
    if( value )
    {
        return QDate::fromJulianDay (value->get_int32 ().value).toString ("dd/MM/yyyy");
    }else{
        return "Tarih Yok";
    }
}

int SerikBLDCore::Dilekce::saatMSecStartofDay()
{
    auto value = this->element (KeySaat);
    if( value )
    {
        return  (value->get_int32 ().value);
    }else{
        return -1;
    }
}

QString SerikBLDCore::Dilekce::saatText()
{
    auto value = this->element (KeySaat);
    if( value )
    {
        return  QTime::fromMSecsSinceStartOfDay ((value->get_int32 ().value)).toString ("hh:mm");
    }else{
        return "Saat Yok";
    }
}

QString SerikBLDCore::Dilekce::dilekceOid()
{
    auto value = this->element (KeyDilekceOid);
    if( value )
    {
        return  QString::fromStdString (value->get_utf8 ().value.to_string ());
    }else{
        return "";
    }
}

QStringList SerikBLDCore::Dilekce::EkOidList()
{
    QStringList list;
    auto _list_ = this->element (KeyEkler);
    if( _list_ )
    {
        auto _list = _list_.value ().get_array ().value;
        for( auto item : _list )
        {
            list.push_back (item.get_oid ().value.to_string ().c_str ());
        }
    }
    return list;
}

QVector<SerikBLDCore::Personel> SerikBLDCore::Dilekce::GorevliList() const
{
    QVector<Personel> list;

    auto _list = this->element (KeyGorevliPersonel);

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

QVector<QString> SerikBLDCore::Dilekce::BilgiBirimList() const
{
    QVector<QString> list;

    auto _list = this->element (KeyBilgiBirimler);

    if( _list )
    {
        auto __list = _list.value ().get_array ().value;
        for( auto item : __list )
        {
            list.push_back (std::move(item.get_utf8 ().value.to_string().c_str ()));
        }
    }
    return list;
}

QString SerikBLDCore::Dilekce::Durum() const
{
    auto value = this->element (KeyDilekceDurum);
    if( value )
    {
        return  QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::Dilekce::cevapOid() const
{
    auto value = this->element (KeyCevapOid);
    if( value )
    {
        return  QString::fromStdString (value->get_oid ().value.to_string());
    }else{
        return "";
    }
}

