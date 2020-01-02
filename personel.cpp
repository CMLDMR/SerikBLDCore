#include "personel.h"


const std::string SerikBLDCore::IK::Personel::Collection{"Personel"};
const std::string SerikBLDCore::IK::Personel::KeyAdSoyad{"ad soyad"};
const std::string SerikBLDCore::IK::Personel::KeyBuroPersonel{"Büro Personeli"};
const std::string SerikBLDCore::IK::Personel::KeyTelefon{"telefon"};
const std::string SerikBLDCore::IK::Personel::KeyStatu{"Statü"};
const std::string SerikBLDCore::IK::Personel::KeyBirimi{"Birimi"};
const std::string SerikBLDCore::IK::Personel::KeyFotoOid{"fotooid"};
const std::string SerikBLDCore::IK::Personel::KeyPassword{"password"};
const std::string SerikBLDCore::IK::Personel::KeyTCNO{"tcno"};


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

QString SerikBLDCore::IK::Personel::statu() const
{
    auto val = this->element (KeyStatu);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::IK::Personel::telefon() const
{
    auto val = this->element (KeyTelefon);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

QString SerikBLDCore::IK::Personel::sifre() const
{
    auto val = this->element (KeyPassword);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::setAdSoyad(const QString &adsoyad)
{
    this->append(KeyAdSoyad,adsoyad.toStdString ());
    return *this;
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::setBuroPersoneli(const bool &buro)
{
    this->append(KeyBuroPersonel,buro);
    return *this;
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::setFotoOid(const QString &fotoOid)
{
    this->append(KeyFotoOid,bsoncxx::oid{fotoOid.toStdString ()});
    return *this;
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::setBirim(const QString &birim)
{
    this->append(KeyBirimi,birim.toStdString ());
    return *this;
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::setStatu(const QString &statu)
{
    this->append(KeyStatu,statu.toStdString ());
    return *this;
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::setTelefon(const QString &telefon)
{
    if( !checkTelefonFormat (telefon) )
    {
        errorOccured ("Telefon Numrası Hatalı");
        return *this;
    }
    this->append(KeyTelefon,telefon.toStdString ());
    return *this;
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::setSifre(const QString &sifre)
{
    this->append(KeyPassword,sifre.toStdString ());
    return *this;
}

bool SerikBLDCore::IK::Personel::checkTelefonFormat(const QString &numara)
{

    QString str("0123456789");
    if( numara.count () != 11 )
    {
        return false;
    }

    if( numara.at (0) != '0' )
    {
        return false;
    }

    if( numara.at (1) != '5' )
    {
        return false;
    }

    bool returnType = true;
    for( auto item : numara )
    {
        if( !str.contains (item) )
        {
            returnType = false;
            break;
        }
    }

    return returnType;


}

void SerikBLDCore::IK::Personel::errorOccured(const std::string &errorText)
{

}

SerikBLDCore::IK::BirimItem::BirimItem()
    :SerikBLDCore::Item(BirimKey::Collection)
{

}

SerikBLDCore::IK::BirimItem::BirimItem(const SerikBLDCore::IK::BirimItem &other)
    :SerikBLDCore::Item(BirimKey::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::IK::BirimItem::BirimItem(SerikBLDCore::IK::BirimItem &&other)
    :SerikBLDCore::Item(BirimKey::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::IK::BirimItem &SerikBLDCore::IK::BirimItem::operator=(const SerikBLDCore::IK::BirimItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::IK::BirimItem &SerikBLDCore::IK::BirimItem::operator=(SerikBLDCore::IK::BirimItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
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
