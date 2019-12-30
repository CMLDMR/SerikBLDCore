#include "personel.h"


const std::string SerikBLDCore::IK::Personel::Collection{"Personel"};



SerikBLDCore::IK::Personel::Personel() : Item(Collection)
{

}

SerikBLDCore::IK::Personel::Personel(const Personel &other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::IK::Personel::Personel(Personel &&other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::operator=(const Personel &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::operator=(Personel &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

QString SerikBLDCore::IK::Personel::AdSoyad() const
{
    auto val = this->element (KeyAdSoyad);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

bool SerikBLDCore::IK::Personel::BuroPersoneli() const
{
    auto val = this->element (KeyBuroPersonel);
    if( val )
    {
        return  val.value ().get_bool ().value;
    }else{
        return false;
    }
}

QString SerikBLDCore::IK::Personel::FotoOid() const
{
    auto val = this->element (KeyFotoOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::IK::Personel::Birim() const
{
    auto val = this->element (KeyBirimi);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

void SerikBLDCore::IK::Personel::setAdSoyad(const QString &adsoyad)
{
    this->append(KeyAdSoyad,adsoyad.toStdString ());
}

void SerikBLDCore::IK::Personel::setBuroPersoneli(const bool &buro)
{
    this->append(KeyBuroPersonel,buro);
}

void SerikBLDCore::IK::Personel::setFotoOid(const QString &fotoOid)
{
    this->append(KeyFotoOid,bsoncxx::oid{fotoOid.toStdString ()});
}

void SerikBLDCore::IK::Personel::setBirim(const QString &birim)
{
    this->append(KeyBirimi,birim.toStdString ());
}

SerikBLDCore::IK::BirimItem::BirimItem()
    :SerikBLDCore::Item("COllection")
{

}

SerikBLDCore::IK::BirimItem &SerikBLDCore::IK::BirimItem::setBirimAdi(const QString &birimAdi)
{
    this->append(BirimKey::birim,birimAdi.toStdString ());
    return *this;
}

QString SerikBLDCore::IK::BirimItem::birimAdi() const
{
    auto val = this->element (BirimKey::birim);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}
