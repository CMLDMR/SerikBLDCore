#include "meclisuyesi.h"
#include <algorithm>

SerikBLDCore::Meclis::MeclisUyesi::MeclisUyesi()
    :SerikBLDCore::Item (UyeKey::Collection)
{

}

SerikBLDCore::Meclis::MeclisUyesi::MeclisUyesi(const SerikBLDCore::Meclis::MeclisUyesi &other)
    :SerikBLDCore::Item (other.getCollection ())
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Meclis::MeclisUyesi::MeclisUyesi(SerikBLDCore::Meclis::MeclisUyesi &&other)
    :SerikBLDCore::Item (other.getCollection ())
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::operator=(const SerikBLDCore::Meclis::MeclisUyesi &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::operator=(SerikBLDCore::Meclis::MeclisUyesi &&other)
{
    this->setDocumentView (other.view ());
    return *this;
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

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::setPartiAdi(const std::string &partiAdi)
{
    this->append(UyeKey::partiAdi,partiAdi);
    return *this;
}



SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::addKomisyonAdi(const std::string &komisyonAdi)
{
    this->pushArray(UyeKey::komisyonAdi,komisyonAdi);
    return *this;
}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::delKomisyonAdi(const std::string &komisyonAdi)
{
    this->pullArray(UyeKey::komisyonAdi,bsoncxx::types::value (bsoncxx::types::b_utf8{komisyonAdi}));
    return *this;
}

SerikBLDCore::Meclis::MeclisUyesi &SerikBLDCore::Meclis::MeclisUyesi::setDonemAdi(const std::string &donem)
{
    this->append(UyeKey::donemAdi,donem);
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

QString SerikBLDCore::Meclis::MeclisUyesi::partiAdi() const
{
    auto val = this->element (UyeKey::partiAdi);
    if( val )
    {
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif

    }
    return "";
}

QString SerikBLDCore::Meclis::MeclisUyesi::donemAdi() const
{
    auto val = this->element (UyeKey::donemAdi);
    if( val )
    {
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif

    }
    return "";
}

QVector<QString> SerikBLDCore::Meclis::MeclisUyesi::komisyonUyelikleri() const
{
    QVector<QString> list;
    auto val = this->element (UyeKey::komisyonAdi);
    if( val )
    {
//        std::transform(val.value ().get_array ().value.begin (),
//                       val.value ().get_array ().value.end (),
//                       val.value ().get_array ().value.begin (),
//                       [&list](const bsoncxx::v_noabi::array::element &element){ list.push_back (QString::fromStdString (element.get_utf8 ().value.to_string ())); });

        for( auto item : val.value ().get_array ().value )
        {
#ifdef Q_CC_MSVC
        list.push_back (QString::fromStdString (item.get_utf8 ().value.to_string ()));
#endif
#ifdef Q_CC_GNU
        list.push_back (QString::fromStdString (item.get_utf8 ().value.data ()));
#endif

        }
    }
    return list;
}


SerikBLDCore::Meclis::MeclisDonemi::MeclisDonemi()
    :SerikBLDCore::Item (DonemKey::Collection)
{

}



SerikBLDCore::Meclis::MeclisDonemi &SerikBLDCore::Meclis::MeclisDonemi::setDonem(const int &baslangicYear, const int &bitisYear)
{
    this->append(DonemKey::baslangicJulianDay,bsoncxx::types::b_int32{baslangicYear});
    this->append(DonemKey::bitisJulianDay,bsoncxx::types::b_int32{bitisYear});
    return *this;
}

QString SerikBLDCore::Meclis::MeclisDonemi::donem() const
{
    auto bas = this->element (DonemKey::baslangicJulianDay);
    auto bit = this->element (DonemKey::bitisJulianDay);

    if( bas && bit )
    {
        return QString("%1 - %2").arg (bas.value ().get_int32 ().value).arg (bit.value().get_int32 ().value);
    }
    return "";
}

SerikBLDCore::Meclis::MeclisDonemi &SerikBLDCore::Meclis::MeclisDonemi::setBaslangicDate(const int64_t &julianBaslangic)
{
    this->append(DonemKey::startJulianDate,bsoncxx::types::b_int64{julianBaslangic});
    return *this;
}

SerikBLDCore::Meclis::MeclisDonemi &SerikBLDCore::Meclis::MeclisDonemi::setBitisDate(const int64_t &julianBitis)
{
    this->append(DonemKey::endJulianDate,bsoncxx::types::b_int64{julianBitis});
    return *this;
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
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif

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
#ifdef Q_CC_MSVC
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string ());
#endif
#ifdef Q_CC_GNU
        return QString::fromStdString (val.value ().get_utf8 ().value.data ());
#endif

    }
    return "";
}
