#include "personel.h"

const std::string SerikBLDCore::IK::Personel::CollectionHold{"PersonelHold"};
const std::string SerikBLDCore::IK::Personel::Collection{"Personel"};
const std::string SerikBLDCore::IK::Personel::KeyAdSoyad{"ad soyad"};
const std::string SerikBLDCore::IK::Personel::KeyBuroPersonel{"Büro Personeli"};
const std::string SerikBLDCore::IK::Personel::KeyTelefon{"telefon"};
const std::string SerikBLDCore::IK::Personel::KeyStatu{"Statü"};
const std::string SerikBLDCore::IK::Personel::KeyBirimi{"Birimi"};
const std::string SerikBLDCore::IK::Personel::KeyFotoOid{"fotooid"};
const std::string SerikBLDCore::IK::Personel::KeyPassword{"password"};
const std::string SerikBLDCore::IK::Personel::KeyTCNO{"tcno"};
const std::string SerikBLDCore::IK::Personel::KeyMudurlukler{"Müdürlükler"};
const std::string SerikBLDCore::IK::Personel::KeyAltBirim{"altbirim"};

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
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif

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
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif

    }else{
        return "";
    }
}

QString SerikBLDCore::IK::Personel::statu() const
{
    auto val = this->element (KeyStatu);
    if( val )
    {
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::IK::Personel::telefon() const
{
    auto val = this->element (KeyTelefon);
    if( val )
    {
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }else{
        return "";
    }
}

QString SerikBLDCore::IK::Personel::sifre() const
{
    auto val = this->element (KeyPassword);
    if( val )
    {
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }else{
        return "";
    }
}

QVector<bsoncxx::oid> SerikBLDCore::IK::Personel::mudurlukList() const
{
    QVector<bsoncxx::oid> list;

    auto _list = this->element (KeyMudurlukler);

    if( _list )
    {
        auto __list = _list.value ().get_array ().value;
        for( auto item : __list )
        {
            list.push_back (item.get_oid ().value);
        }
    }
    return list;
}

QVector<bsoncxx::oid> SerikBLDCore::IK::Personel::altBirimOidList() const
{

    QVector<bsoncxx::oid> list;

    auto _list = this->element (KeyAltBirim);

    if( _list )
    {
        auto __list = _list.value ().get_array ().value;
        for( auto item : __list )
        {
            list.push_back (item.get_oid ().value);
        }
    }
    return list;
}

bool SerikBLDCore::IK::Personel::altBirimContains(const bsoncxx::oid &altBirimOid) const
{
    bool returnValue = false;
    auto _list = this->element (KeyAltBirim);
    if( _list )
    {
        auto __list = _list.value ().get_array ().value;
        for( auto item : __list )
        {
            if( altBirimOid.to_string () == item.get_oid ().value.to_string () )
            {
                returnValue = true;
                break;
            }
        }
    }
    return returnValue;
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

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::addMudurluk(const QString &mudurlukOid)
{
    this->pushArray(KeyMudurlukler,bsoncxx::oid{mudurlukOid.toStdString ()});
    return *this;
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::deleteMudurluk(const QString &mudurlukOid)
{
    auto pList = this->mudurlukList ();
    this->removeElement (KeyMudurlukler);

    if( pList.count () == 1 )
    {
        this->append(KeyMudurlukler,array{});
        return *this;
    }

    for( auto item : pList )
    {
        if( item.to_string () != mudurlukOid.toStdString ())
        {
            this->addMudurluk (item.to_string ().c_str ());
        }
    }
    return *this;
}

SerikBLDCore::IK::Personel &SerikBLDCore::IK::Personel::addAltBirim(const QString &altBirim)
{
    if( !this->altBirimContains (bsoncxx::oid{altBirim.toStdString ()}) )
    {
        this->pushArray(KeyAltBirim,bsoncxx::oid{altBirim.toStdString ()});
    }
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
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }
    return "";
}

QString SerikBLDCore::IK::BirimItem::HaberlesmeKodu() const
{
    auto val = this->element (BirimKey::haberlesmeKodu);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

SerikBLDCore::IK::AltBirimItem::AltBirimItem()
    :Item (AltBirimKey::Collection)
{

}

SerikBLDCore::IK::AltBirimItem &SerikBLDCore::IK::AltBirimItem::setName(const QString &birimName)
{
    this->append(AltBirimKey::altBirimAdi,birimName.toStdString ());
    return *this;
}

SerikBLDCore::IK::AltBirimItem &SerikBLDCore::IK::AltBirimItem::setBirimOid(const bsoncxx::oid &birimOid)
{
    this->append(AltBirimKey::birimOid,birimOid);
    return *this;
}

QString SerikBLDCore::IK::AltBirimItem::name() const
{
    auto val = this->element (AltBirimKey::altBirimAdi);
    if( val )
    {
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif
    }
    return "";
}

std::string SerikBLDCore::IK::AltBirimItem::birimOid() const
{
    auto val = this->element (AltBirimKey::birimOid);
    if( val )
    {
        return  (val.value ().get_oid ().value.to_string());
    }
    return "";
}
