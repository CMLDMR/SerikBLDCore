#include "personel.h"


const std::string Personel::Collection{"Personel"};



Personel::Personel() : Item(Collection)
{

}

Personel::Personel(const Personel &other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

Personel::Personel(Personel &&other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

Personel &Personel::operator=(const Personel &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

Personel &Personel::operator=(Personel &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

QString Personel::AdSoyad() const
{
    auto val = this->element (KeyAdSoyad);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

bool Personel::BuroPersoneli() const
{
    auto val = this->element (KeyBuroPersonel);
    if( val )
    {
        return  val.value ().get_bool ().value;
    }else{
        return false;
    }
}

QString Personel::FotoOid() const
{
    auto val = this->element (KeyFotoOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string());
    }else{
        return "";
    }
}

QString Personel::Birim() const
{
    auto val = this->element (KeyBirimi);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

void Personel::setAdSoyad(const QString &adsoyad)
{
    this->append(KeyAdSoyad,adsoyad.toStdString ());
}

void Personel::setBuroPersoneli(const bool &buro)
{
    this->append(KeyBuroPersonel,buro);
}

void Personel::setFotoOid(const QString &fotoOid)
{
    this->append(KeyFotoOid,bsoncxx::oid{fotoOid.toStdString ()});
}

void Personel::setBirim(const QString &birim)
{
    this->append(KeyBirimi,birim.toStdString ());
}
