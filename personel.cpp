#include "personel.h"


const std::string SerikBLDCore::Personel::Collection{"Personel"};



SerikBLDCore::Personel::Personel() : Item(Collection)
{

}

SerikBLDCore::Personel::Personel(const Personel &other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Personel::Personel(Personel &&other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Personel &SerikBLDCore::Personel::operator=(const Personel &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Personel &SerikBLDCore::Personel::operator=(Personel &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

QString SerikBLDCore::Personel::AdSoyad() const
{
    auto val = this->element (KeyAdSoyad);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

bool SerikBLDCore::Personel::BuroPersoneli() const
{
    auto val = this->element (KeyBuroPersonel);
    if( val )
    {
        return  val.value ().get_bool ().value;
    }else{
        return false;
    }
}

QString SerikBLDCore::Personel::FotoOid() const
{
    auto val = this->element (KeyFotoOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::Personel::Birim() const
{
    auto val = this->element (KeyBirimi);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

void SerikBLDCore::Personel::setAdSoyad(const QString &adsoyad)
{
    this->append(KeyAdSoyad,adsoyad.toStdString ());
}

void SerikBLDCore::Personel::setBuroPersoneli(const bool &buro)
{
    this->append(KeyBuroPersonel,buro);
}

void SerikBLDCore::Personel::setFotoOid(const QString &fotoOid)
{
    this->append(KeyFotoOid,bsoncxx::oid{fotoOid.toStdString ()});
}

void SerikBLDCore::Personel::setBirim(const QString &birim)
{
    this->append(KeyBirimi,birim.toStdString ());
}
