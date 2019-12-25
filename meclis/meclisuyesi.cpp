#include "meclisuyesi.h"


SerikBLDCore::Meclis::MeclisUyesi::MeclisUyesi()
    :SerikBLDCore::TC (UyeKey::Collection)
{

}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::setTCOid(const std::string &tcOid)
{
    this->append(UyeKey::tcOid,bsoncxx::oid{tcOid});
    return *this;
}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::setTCOid(const bsoncxx::oid &tcOid)
{
    this->append(UyeKey::tcOid,tcOid);
    return *this;
}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::setPartiOid(const std::string &partiOid)
{
    this->append(UyeKey::partiOid,bsoncxx::oid{partiOid});
    return *this;
}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::setPartiOid(const bsoncxx::oid &partiOid)
{
    this->append(UyeKey::partiOid,partiOid);
    return *this;
}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::setKomisyonOid(const std::string &komisyonOid)
{
    this->append(UyeKey::komisyonOid,bsoncxx::oid{komisyonOid});
    return *this;
}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::setKomisyonOid(const bsoncxx::oid &komisyonOid)
{
    this->append(UyeKey::komisyonOid,komisyonOid);
    return *this;
}

QString SerikBLDCore::Meclis::MeclisUyesi::tcOid() const
{
    auto val = this->element (UyeKey::tcOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

QString SerikBLDCore::Meclis::MeclisUyesi::partiOid() const
{
    auto val = this->element (UyeKey::partiOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}

QString SerikBLDCore::Meclis::MeclisUyesi::komisyonOid() const
{
    auto val = this->element (UyeKey::komisyonOid);
    if( val )
    {
        return QString::fromStdString (val.value ().get_oid ().value.to_string ());
    }
    return "";
}


SerikBLDCore::Meclis::MeclisDonemi::MeclisDonemi()
    :SerikBLDCore::Item (DonemKey::Collection)
{

}

SerikBLDCore::Meclis::MeclisDonemi &SerikBLDCore::Meclis::MeclisDonemi::setDonem(const std::string &donem)
{
    this->append(DonemKey::donem,donem);
    return *this;
}

QString SerikBLDCore::Meclis::MeclisDonemi::donem() const
{
    auto val = this->element (DonemKey::donem);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }
    return "";
}

SerikBLDCore::Meclis::PartiItem::PartiItem()
    :SerikBLDCore::Item (PartiKey::Collection)
{

}

SerikBLDCore::Meclis::PartiItem &SerikBLDCore::Meclis::PartiItem::setParti(const std::string &parti)
{
    this->append(PartiKey::parti,parti);
    return *this;
}

QString SerikBLDCore::Meclis::PartiItem::parti() const
{
    auto val = this->element (PartiKey::parti);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }
    return "";
}

SerikBLDCore::Meclis::KomisyonItem::KomisyonItem()
    :SerikBLDCore::Item (KomisyonKey::Collection)
{

}

SerikBLDCore::Meclis::KomisyonItem &SerikBLDCore::Meclis::KomisyonItem::setKomisyonAdi(const std::string &komisyonAdi)
{
    this->append(KomisyonKey::komisyon,komisyonAdi);
    return *this;
}

QString SerikBLDCore::Meclis::KomisyonItem::komisyonAdi() const
{
    auto val = this->element (KomisyonKey::komisyon);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
    }
    return "";
}
